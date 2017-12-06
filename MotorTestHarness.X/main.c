/*
 * File:   main.c
 * Author: alkagan
 *
 * Created on November 16, 2017, 10:20 PM
 */
#define SERVO

#ifdef MOTOR

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

#define time_delay 500
#define DUTY_CYCLE 900 //doesn't work for full duty cycle (1000)
#define ADC_MAX 1023.0
#define RC_MAX (MAXPULSE - MINPULSE)

void delay(int time) {
    int zeropoint = TIMERS_GetTime();
    while ((TIMERS_GetTime() - zeropoint) < time);
}

int main(void) {
    BOARD_Init();
    AD_Init();
    TIMERS_Init();
    PWM_Init();
    SERIAL_Init();
    RC_Init();
    PWM_AddPins(PWM_PORTY10 | PWM_PORTZ06 | PWM_PORTY12);
    //RC_AddPins (RC_PORTZ08);
    PWM_SetFrequency(PWM_1KHZ);

    //IO_PortsSetPortInputs(PORTX, PIN8);
    //IO_PortsSetPortInputs(PORTX, PIN9);
    AD_AddPins(TAPE_TOP | TAPE_LEFT | TAPE_RIGHT | TAPE_CORNER);

    IO_PortsSetPortOutputs(PORTX, (PIN11 | PIN12));

    static bool direction_left = 0;
    static bool direction_right = 0;
    static int i = 0;

    while (1) {
        PWM_SetDutyCycle(PWM_PORTZ06, DUTY_CYCLE);
        PWM_SetDutyCycle(PWM_PORTY10, DUTY_CYCLE);
        PWM_SetDutyCycle(PWM_PORTY12, (DUTY_CYCLE + 50));
        //RC_SetPulseTime(RC_PORTZ08, RCValue);
        uint16_t left_duty = PWM_GetDutyCycle(PWM_PORTZ06);
        uint16_t right_duty = PWM_GetDutyCycle(PWM_PORTY12);
        printf("left_duty: %d\r\n", left_duty);
        printf("right_duty: %d\r\n", right_duty);
        //IO_PortsWritePort(PORTX, 0);

        // Switch Code
        uint16_t left_switch_input = AD_ReadADPin(AD_PORTW8);
        uint16_t right_switch_input = AD_ReadADPin(AD_PORTW5);

        uint16_t tape_sensor_top = AD_ReadADPin(TAPE_TOP);
        uint16_t tape_sensor_left = AD_ReadADPin(TAPE_LEFT); //idk
        uint16_t tape_sensor_right = AD_ReadADPin(TAPE_RIGHT); //idk
        uint16_t tape_sensor_corner = AD_ReadADPin(TAPE_CORNER); //idk

        printf("tape_top: %d\r\n", tape_sensor_top);
        printf("tape_left: %d\r\n", tape_sensor_left);
        printf("tape_right: %d\r\n", tape_sensor_right);
        printf("tape_corner: %d\r\n", tape_sensor_corner);
        delay(500);
        //printf("Left switch: %d\r\n", left_switch_input);
        //printf("Right switch: %d\r\n", right_switch_input);
        //delay(time_delay);

        //////////////////////////////////////////////////////////
        //Esteban's attempt at this Beacon shit
        //        for (i = 0; i < 10000; i++);
        //        uint16_t beacon_reading = AD_ReadADPin(AD_PORTW6);
        //        for (i = 0; i < 10000; i++);
        //        if (beacon_reading < 800) {
        //            printf("Beacon reading: %d\r\n\n", beacon_reading);
        //        }
        //        if( beacon_reading < 800) {
        //            printf("a");
        //        } else if( beacon_reading > 800) {
        //            printf("b");
        //        }

        //        if( beacon_reading > 500) {
        //            //beacon event detected
        //        } else if ( beacon_reading < 200) {
        //            //no beacon event detected
        //        }


        //////////////////////////////////////////////////////////

        //        bool port_5_output = IO_PortsReadPort(PORTX) & PIN11;
        //        bool port_6_output = IO_PortsReadPort(PORTX) & PIN12;

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
        //////////////////////////////////////////////////////////

        // Checking 0 or 1 and sending appropriate direction value
        if (direction_left) {
            IO_PortsWritePort(PORTX, PIN11);
        } else if (direction_right) {
            IO_PortsWritePort(PORTX, PIN12);
        } else {
            IO_PortsWritePort(PORTX, (PIN11 | PIN12));
        }
        //////////////////////////////////////////////////////////

        //printf("Direction left:  %d\r\n", IO_PortsReadPort(PORTX) & PIN11);
        //printf("Direction right: %d\r\n", IO_PortsReadPort(PORTX) & PIN12);

        /*
        IO_PortsClearPortBits(PORTX, PIN5);
        IO_PortsClearPortBits(PORTX, PIN6);
        IO_PortsWritePort(PORTX, PIN6);

        
        //IO_PortsSetPortBits(PORTX, PIN6);
        IO_PortsWritePort(PIN5, 0);
        IO_PortsTogglePortBits(PORTX, PIN6);
         */
    }
}
#endif

#ifdef TAPE

#include "xc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <BOARD.h>
#include <AD.h>
#include <timers.h>
#include <LED.h>
#include <serial.h>
#include <IO_Ports.h>

#define ADC_MAX 1023.0
#define voltage 3.3
#define magicnumber 50

void delay(int time);

int main(void) {
    BOARD_Init();
    AD_Init();
    TIMERS_Init();
    AD_AddPins(AD_PORTV3 | AD_PORTV4 | AD_PORTV5 | AD_PORTV6);
    IO_PortsSetPortOutputs(PORTX, PIN3);
    SERIAL_Init();

    while (1) {
        //        IO_PortsSetPortBits(PORTX, PIN3);
        //        delay(magicnumber);
        //
        //        // Accounts for noise
        //        uint16_t corner = AD_ReadADPin(AD_PORTV3);
        //        uint16_t tapeRight = AD_ReadADPin(AD_PORTV4);
        //        uint16_t tapeLeft = AD_ReadADPin(AD_PORTV5);
        //        uint16_t tapeCenter = AD_ReadADPin(AD_PORTV6);
        //        uint16_t AvgValueLow = (AvgValueLow + corner + tapeRight + tapeLeft + tapeCenter) / 5;
        //
        //        delay(magicnumber);
        //
        //        IO_PortsClearPortBits(PORTX, PIN3);
        //        delay(magicnumber);
        //
        //        // Takes real value of each sensor
        //        uint16_t acorner = (AD_ReadADPin(AD_PORTV3));
        //        uint16_t atapeRight = (AD_ReadADPin(AD_PORTV4) );
        //        uint16_t atapeLeft = (AD_ReadADPin(AD_PORTV5) );
        //        uint16_t atapeCenter = (AD_ReadADPin(AD_PORTV6));
        //        printf("corner is %i\r\n tapeRight is %i\r\n tapeLeft is %i\r\n tapeCenter"
        //                " is %i\r\n AvgValueLow is %i\r\n corner is %i\r\n atapeRight is %i\r\n atapeLeft is %i\r\n atapeCenter"
        //                " is %i\r\n____________________,\r\n, cht, tapeLeft,
        //                tapeCenter, AvgValueLow, acorner, atapeRight, atapeLeft, atapeCenter);
        //
        //        delay(magicnumber);
        uint16_t corner = AD_ReadADPin(AD_PORTV3);
        printf("corner is %i\r\n", corner);
        delay(magicnumber);
    }
}

void delay(int time) {
    int zeropoint = TIMERS_GetTime();
    while ((TIMERS_GetTime() - zeropoint) < time);
}

#endif

#ifdef SERVO

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

#define time_delay 500
#define DUTY_CYCLE 1000 //doesn't work for full duty cycle (1000)
#define ADC_MAX 1023.0
#define RC_MAX (MAXPULSE - MINPULSE)
#define INDEXER RC_PORTY06  //Servo 
#define PUSHER  RC_PORTY07

void delay(int time) {
    int zeropoint = TIMERS_GetTime();
    while ((TIMERS_GetTime() - zeropoint) < time);
}

int main(void) {
    BOARD_Init();
    AD_Init();
    TIMERS_Init();
    SERIAL_Init();
    RC_Init();
    PWM_Init();
    RC_AddPins(RC_PORTY07 | RC_PORTY06);
    PWM_AddPins(PWM_PORTY10);
    
    static int i = 0;
    static uint16_t ServoVal = 0;
    static uint16_t ServoDuty;
    static bool flag = 0;

    while (1) {
        if ( flag == TRUE) {
            ServoVal = ServoVal - 1;
        } else if (flag == FALSE) {
            ServoVal += 1;
        }
        
        PWM_SetDutyCycle(PWM_PORTY10, DUTY_CYCLE);
        
        ServoDuty = 1000 + ServoVal;
        RC_SetPulseTime(RC_PORTY07, ServoDuty);
        RC_SetPulseTime(RC_PORTY06, ServoDuty);
        if (ServoVal == 1000) {
            flag = 1;
        } else if (ServoVal == 0){
            flag = 0;
        }
        //delay(10);
        printf("servoduty: %d\r\n", ServoDuty);
        printf("servoVal:  %d\r\n", ServoVal);
        
        
        //delay(500);
//        if (ServoVal == 1000) {
//            ServoVal -= 10;
//            ServoDuty = 1000 + ServoVal;
//            RC_SetPulseTime(RC_PORTX03, ServoDuty);
//        }
    }

    //    ServoVal = ((float) (PotValue) / 1023)*1000;
    //            ServoDuty = 1000 + (unsigned short int) ServoVal;
    //            RC_SetPulseTime(RC_PORTZ08, ServoDuty);
}
#endif
