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
    PWM_AddPins(PWM_PORTY10 | PWM_PORTZ06 | PWM_PORTY12);
    //RC_AddPins (RC_PORTZ08);
    PWM_SetFrequency(PWM_1KHZ);
    
    //IO_PortsSetPortInputs(PORTX, PIN8);
    //IO_PortsSetPortInputs(PORTX, PIN9);
    AD_AddPins(AD_PORTW8 | AD_PORTW5 | AD_PORTW6);
    
    IO_PortsSetPortOutputs(PORTX, (PIN11 | PIN12));
    
    static bool direction_left = 0;
    static bool direction_right = 0;
    static int i = 0;
        
    while(1){
        PWM_SetDutyCycle(PWM_PORTZ06, DUTY_CYCLE);
        PWM_SetDutyCycle(PWM_PORTY10, DUTY_CYCLE);
        PWM_SetDutyCycle(PWM_PORTY12, (DUTY_CYCLE + 50));
        //RC_SetPulseTime(RC_PORTZ08, RCValue);
        
        //IO_PortsWritePort(PORTX, 0);
                
        // Switch Code
        uint16_t left_switch_input  = AD_ReadADPin(AD_PORTW8);
        uint16_t right_switch_input = AD_ReadADPin(AD_PORTW5);
        
        
        
        //printf("Left switch: %d\r\n", left_switch_input);
        //printf("Right switch: %d\r\n", right_switch_input);
        //delay(time_delay);
        
        //////////////////////////////////////////////////////////
        //Esteban's attempt at this Beacon shit
        for( i = 0; i < 10000; i++);
        uint16_t beacon_reading = AD_ReadADPin(AD_PORTW6);
        for( i = 0; i < 10000; i++);
        if( beacon_reading < 800) {
            printf("Beacon reading: %d\r\n\n", beacon_reading);
        } 
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
        if (left_switch_input > 800){
            direction_left = 1;
        } else if (left_switch_input < 400){
            direction_left = 0;
        }
        
        if (right_switch_input > 800){
            direction_right = 1;
        } else if (right_switch_input < 400){
            direction_right = 0;
        }
        //////////////////////////////////////////////////////////
        
        // Checking 0 or 1 and sending appropriate direction value
        if(direction_left){
            IO_PortsWritePort(PORTX, PIN11);
        } else if(direction_right){
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
