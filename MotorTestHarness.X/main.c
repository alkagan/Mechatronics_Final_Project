/*
 * File:   main.c
 * Author: alkagan
 *
 * Created on November 16, 2017, 10:20 PM
 */

#include <BOARD.h>
#include <stdio.h>
#include <stdbool.h>
#include "AD.h"
#include "IO_Ports.h"
#include "LED.h"
#include "pwm.h"
#include "serial.h"
#include "timers.h"
#include "RC_Servo.h"
#include "pin_configuration.h"
#include "xc.h"

#define time_delay 500
#define DUTY_CYCLE 900 //doesn't work for full duty cycle (1000)
#define ADC_MAX 1023.0
#define RC_MAX (MAXPULSE - MINPULSE)
#define voltage 3.3
#define magicnumber 50

#define FAST_AND_FURIOUS    1000
#define TOKYO_DRIFT         600
#define NORMAL_SPEED        600
#define SNAIL_PACE          200
#define NOT_MOVING          0
#define REVERSE             1
#define LITTLE_MORE         675

void delay(int time) {
    int zeropoint = TIMERS_GetTime();
    while ((TIMERS_GetTime() - zeropoint) < time);
}

void delay(int time) {
    int zeropoint = TIMERS_GetTime();
    while ((TIMERS_GetTime() - zeropoint) < time);
}

void turn_right(void) {
    IO_PortsWritePort(PORTX, 0);
    IO_PortsWritePort(PORTX, (LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION));
    PWM_SetDutyCycle(LEFT_MOTOR, TOKYO_DRIFT);
    PWM_SetDutyCycle(RIGHT_MOTOR, SNAIL_PACE);
}

void turn_left(void) {
    IO_PortsWritePort(PORTX, LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, SNAIL_PACE);
    PWM_SetDutyCycle(RIGHT_MOTOR, TOKYO_DRIFT);
}

void set_IO_pins(void) {
    IO_PortsSetPortOutputs(PORTX, (LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION));
}

int main(void) {
    BOARD_Init();
    AD_Init();
    TIMERS_Init();
    AD_AddPins(AD_PORTV3 | AD_PORTV4 | AD_PORTV5 | AD_PORTV6);
    IO_PortsSetPortOutputs(PORTX, PIN3);
    SERIAL_Init();

    while (1) {

        ///// Motor test
        if(test == 0){
            PWM_SetDutyCycle(PWM_PORTZ06, DUTY_CYCLE);
            PWM_SetDutyCycle(PWM_PORTY10, DUTY_CYCLE);
            PWM_SetDutyCycle(PWM_PORTY12, (DUTY_CYCLE + 50));
            RC_SetPulseTime(RC_PORTZ08, RCValue);
            uint16_t left_duty = PWM_GetDutyCycle(PWM_PORTZ06);
            uint16_t right_duty = PWM_GetDutyCycle(PWM_PORTY12);
            printf("left_duty: %d\r\n", left_duty);
            printf("right_duty: %d\r\n", right_duty);
            IO_PortsWritePort(PORTX, 0);

            // Switch Code
            uint16_t left_switch_input = AD_ReadADPin(AD_PORTW8);
            uint16_t right_switch_input = AD_ReadADPin(AD_PORTW5);

            uint16_t tape_sensor_top = AD_ReadADPin(TAPE_TOP);
            uint16_t tape_sensor_left = AD_ReadADPin(TAPE_LEFT); 
            uint16_t tape_sensor_right = AD_ReadADPin(TAPE_RIGHT); 
            uint16_t tape_sensor_corner = AD_ReadADPin(TAPE_CORNER); 

            printf("tape_top: %d\r\n", tape_sensor_top);
            printf("tape_left: %d\r\n", tape_sensor_left);
            printf("tape_right: %d\r\n", tape_sensor_right);
            printf("tape_corner: %d\r\n", tape_sensor_corner);
            delay(500);
            //printf("Left switch: %d\r\n", left_switch_input);
            //printf("Right switch: %d\r\n", right_switch_input);
            //delay(time_delay);

            bool port_5_output = IO_PortsReadPort(PORTX) & PIN11;
            bool port_6_output = IO_PortsReadPort(PORTX) & PIN12;

            // Creating hysteresis bounds for the switch ADC values
            if (left_switch_input > 800) {
                direction_left = 1;
            } else if (left_switch_input < 400) {
                direction_left = 0;
            }

            if (right_switch_input > 800) {
                direction_right = 1;
            } else if (right_switch_input < 400) {
                direction_right = 0;
            }

            // Checking 0 or 1 and sending appropriate direction value
            if (direction_left) {
                IO_PortsWritePort(PORTX, PIN11);
            } else if (direction_right) {
                IO_PortsWritePort(PORTX, PIN12);
            } else {
                IO_PortsWritePort(PORTX, (PIN11 | PIN12));
            }

            //printf("Direction left:  %d\r\n", IO_PortsReadPort(PORTX) & PIN11);
            //printf("Direction right: %d\r\n", IO_PortsReadPort(PORTX) & PIN12);

            IO_PortsClearPortBits(PORTX, PIN5);
            IO_PortsClearPortBits(PORTX, PIN6);
            IO_PortsWritePort(PORTX, PIN6);

            IO_PortsWritePort(PIN5, 0);
            IO_PortsTogglePortBits(PORTX, PIN6);

        ///// Tape test
        } else if (test == 1){
            IO_PortsSetPortBits(PORTX, PIN3);
            delay(magicnumber);

            // Accounts for noise
            uint16_t corner = AD_ReadADPin(AD_PORTV3);
            uint16_t tapeRight = AD_ReadADPin(AD_PORTV4);
            uint16_t tapeLeft = AD_ReadADPin(AD_PORTV5);
            uint16_t tapeCenter = AD_ReadADPin(AD_PORTV6);
            uint16_t AvgValueLow = (AvgValueLow + corner + tapeRight + tapeLeft + tapeCenter) / 5;

            delay(magicnumber);

            IO_PortsClearPortBits(PORTX, PIN3);
            delay(magicnumber);

            // Takes real value of each sensor
            uint16_t acorner = (AD_ReadADPin(AD_PORTV3));
            uint16_t atapeRight = (AD_ReadADPin(AD_PORTV4) );
            uint16_t atapeLeft = (AD_ReadADPin(AD_PORTV5) );
            uint16_t atapeCenter = (AD_ReadADPin(AD_PORTV6));
            printf("corner is %i\r\n tapeRight is %i\r\n tapeLeft is %i\r\n tapeCenter"
                    " is %i\r\n AvgValueLow is %i\r\n corner is %i\r\n atapeRight is %i\r\n atapeLeft is %i\r\n atapeCenter"
                    " is %i\r\n____________________,\r\n, cht, tapeLeft,
                    tapeCenter, AvgValueLow, acorner, atapeRight, atapeLeft, atapeCenter");

            delay(magicnumber);
            uint16_t corner = AD_ReadADPin(AD_PORTV3);
            printf("corner is %i\r\n", corner);
            delay(magicnumber);

            ServoVal = ((float) (PotValue) / 1023)*1000;
            ServoDuty = 1000 + (unsigned short int) ServoVal;
            RC_SetPulseTime(RC_PORTZ08, ServoDuty);

        ///// Servo Test
        } else if (test == 2){
            if (flag == TRUE) {
                ServoVal = ServoVal - 2;
            } else if (flag == FALSE) {
                ServoVal += 2;
            }

            track_wire_value = AD_ReadADPin(TRACK_WIRE);
            printf("trackWireVal: %d\r\n", track_wire_value);
            ServoDuty = 1000 + ServoVal;
            RC_SetPulseTime(RC_PORTY07, ServoDuty);
            RC_SetPulseTime(RC_PORTY06, ServoDuty);
            if (ServoVal == 1000) {
                flag = 1;
            } else if (ServoVal == 0) {
                flag = 0;
            }

            printf("servoduty: %d\r\n", ServoDuty);
            printf("servoVal:  %d\r\n", ServoVal);
            delay(500);

            if (ServoVal == 1000) {
                ServoVal -= 10;
                ServoDuty = 1000 + ServoVal;
                RC_SetPulseTime(RC_PORTX03, ServoDuty);
            }

        ///// Motor turning test
        } else if (test == 3){
            turn_left();
            printf("delay1 \r\n");
            delay(2000);
            printf("turning right\r\n");
            turn_right();
            printf("delay2 \r\n");
            delay(2000);
        }
    }
}