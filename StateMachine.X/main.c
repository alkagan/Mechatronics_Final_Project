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

#define time_delay 100
#define DUTY_CYCLE 500 //doesn't work for full duty cycle (1000)

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
    AD_AddPins(AD_PORTV4);
    PWM_AddPins(PWM_PORTZ06);
    PWM_AddPins(PWM_PORTY12);
    IO_PortsSetPortInputs(PORTV, PIN3);
    
    while(1){
        // Motor Code
        uint16_t potentiometer_value = AD_ReadADPin(AD_PORTV4);
        printf("Potentiometer's value is %d\r\n", potentiometer_value);
        delay(time_delay);
        PWM_SetFrequency(PWM_1KHZ);
        PWM_SetDutyCycle(PWM_PORTZ06, DUTY_CYCLE);
        PWM_SetDutyCycle(PWM_PORTY12, DUTY_CYCLE);
        
        // Switch Code
        uint16_t port_3_input = IO_PortsReadPort(PORTV);
        printf("The value of PORTV PIN3 is %d\r\n", port_3_input);
        
    }
}
