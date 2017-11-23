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

#define time_delay 20
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
    AD_AddPins(AD_PORTV4);
    PWM_AddPins(PWM_PORTY10 | PWM_PORTZ06 | PWM_PORTY12);
    RC_AddPins (RC_PORTZ08);
    IO_PortsSetPortInputs(PORTV, PIN3);
    PWM_SetFrequency(PWM_1KHZ);
    
    while(1){
        // Motor Code
        uint16_t potentiometer_value = AD_ReadADPin(AD_PORTV4);
        uint16_t RCValue = potentiometer_value * (RC_MAX / ADC_MAX) + MINPULSE;
        printf("Potentiometer's value is %d\r\n", potentiometer_value);
        PWM_SetDutyCycle(PWM_PORTZ06, DUTY_CYCLE);
        delay(time_delay);
        PWM_SetDutyCycle(PWM_PORTY10, DUTY_CYCLE);
        delay(time_delay);
        PWM_SetDutyCycle(PWM_PORTY12, (DUTY_CYCLE + 50));
        RC_SetPulseTime(RC_PORTZ08, RCValue);
        
        // Switch Code
        //uint16_t port_3_input = IO_PortsReadPort(PORTV) & PIN3;
       // printf("The value of PORTV PIN3 is %d\r\n", port_3_input);
        
    }
}
