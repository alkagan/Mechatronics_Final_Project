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

#define time_delay 500
#define DUTY_CYCLE 900 //doesn't work for full duty cycle (1000)
#define ADC_MAX 1023.0
#define RC_MAX (MAXPULSE - MINPULSE)

void delay(int time){
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
    //AD_AddPins(AD_PORTV4);
    PWM_AddPins(PWM_PORTY10 | PWM_PORTZ06 | PWM_PORTY12);
    RC_AddPins (RC_PORTZ08);
    PWM_SetFrequency(PWM_1KHZ);
    
    //IO_PortsSetPortInputs(PORTX, PIN8);
    //IO_PortsSetPortInputs(PORTX, PIN9);
    AD_AddPins(AD_PORTW8 | AD_PORTW5 | AD_PORTV3 | AD_PORTV4 | AD_PORTV5 | AD_PORTV6);
    
    IO_PortsSetPortOutputs(PORTX, PIN5);
    IO_PortsSetPortOutputs(PORTX, PIN6);
        
    while(1){
        // Motor Code
        uint16_t potentiometer_value = AD_ReadADPin(AD_PORTV4);
        uint16_t RCValue = potentiometer_value * (RC_MAX / ADC_MAX) + MINPULSE;
        //printf("Potentiometer's value is %d\r\n", potentiometer_value);
        PWM_SetDutyCycle(PWM_PORTZ06, DUTY_CYCLE);
        //delay(time_delay);
        PWM_SetDutyCycle(PWM_PORTY10, DUTY_CYCLE);
        //delay(time_delay);
        PWM_SetDutyCycle(PWM_PORTY12, (DUTY_CYCLE + 50));
        RC_SetPulseTime(RC_PORTZ08, RCValue);
        
        // Switch Code
        uint16_t left_switch_input  = AD_ReadADPin(AD_PORTW8);
        uint16_t right_switch_input = AD_ReadADPin(AD_PORTW5);
        
        uint16_t unknown_tape_V3 = AD_ReadADPin(AD_PORTV3);
        uint16_t unknown_tape_V4 = AD_ReadADPin(AD_PORTV4);
        uint16_t unknown_tape_V5 = AD_ReadADPin(AD_PORTV5);
        uint16_t unknown_tape_V6 = AD_ReadADPin(AD_PORTV6);
        
        printf("Port V3 is %d\r\n", unknown_tape_V3);
        printf("Port V4 is %d\r\n", unknown_tape_V4);
        printf("Port V5 is %d\r\n", unknown_tape_V5);
        printf("Port V6 is %d\r\n", unknown_tape_V6);
        printf("+++++++++++++++++++++++++++++\r\n\n");
        
        uint16_t AvgValueLow = (AvgValueLow + unknown_tape_V3 + unknown_tape_V4
                + unknown_tape_V5 + unknown_tape_V6) / 5;
        
        // Takes real value of each sensor
        unknown_tape_V3 -= AvgValueLow;
        unknown_tape_V4 -= AvgValueLow;
        unknown_tape_V5 -= AvgValueLow;
        unknown_tape_V6 -= AvgValueLow;
        uint16_t AvgValueHigh = (unknown_tape_V3 + unknown_tape_V4 + 
                unknown_tape_V5 + unknown_tape_V6) / 4;
        // printf("tapeOne is %i%,\r\n tapeTwo is %i%\r\n tapeThree is %i%,"
        //        "\r\n tapeFour is %i%\r\n", tapeOne, tapeTwo, tapeThree, tapeFour);
        
        printf("Port V3 is %d\r\n", unknown_tape_V3);
        printf("Port V4 is %d\r\n", unknown_tape_V4);
        printf("Port V5 is %d\r\n", unknown_tape_V5);
        printf("Port V6 is %d\r\n", unknown_tape_V6);
        
        delay(1000);
        
        /*
        printf("The value of AD_PORTW8 aka left switch is %d\r\n", left_switch_input);
        printf("The value of AD_PORTW5 aka right switch is %d\r\n", right_switch_input);
        delay(time_delay);
        */
        
        bool port_5_output = IO_PortsReadPort(PORTX) & PIN5;
        bool port_6_output = IO_PortsReadPort(PORTX) & PIN6;
        bool direction_left = 0;
        bool direction_right = 0;
        
        if (left_switch_input > 800){
            direction_left = 1;
        }
        
        if (right_switch_input > 800){
            direction_right = 1;
        }
        
        if(direction_left){
            IO_PortsWritePort(PORTX, PIN5);
        }
        
        if(direction_right){
            IO_PortsWritePort(PORTX, PIN6);
        }
        
        /*
        printf("The value of PORTX PIN5 is %d\r\n", IO_PortsReadPort(PORTX) & PIN5);
        printf("The value of PORTX PIN6 is %d\r\n", IO_PortsReadPort(PORTX) & PIN6);
        */
        
        /*
        delay(time_delay);
        IO_PortsClearPortBits(PORTX, PIN5);
        IO_PortsClearPortBits(PORTX, PIN6);
        IO_PortsWritePort(PORTX, PIN6);
       
        delay(time_delay);
        
        //IO_PortsSetPortBits(PORTX, PIN6);
        delay(time_delay);
        IO_PortsWritePort(PIN5, 0);
        IO_PortsTogglePortBits(PORTX, PIN6);
        delay(time_delay);
        */
        
        //printf("The value of PORTV PIN3 is %d\r\n", port_3_input);
        //printf("The value of PORTV PIN4 is %d\r\n", port_4_input);
        //printf("The value of PORTV PIN5 is %d\r\n", port_5_output);
        //printf("The value of PORTV PIN6 is %d\r\n", port_6_output);
    }
}
