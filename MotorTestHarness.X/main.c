/*
 * File:   StickyBoi.c
 * Author: dmquiroz
 *
 * Created on November 15, 2017, 3:32 PM
 */


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
        uint16_t acorner = (10 * (AD_ReadADPin(AD_PORTV3) - AvgValueLow)) - 2000;
        uint16_t atapeRight = (10 * (AD_ReadADPin(AD_PORTV4) - AvgValueLow)) - 2000;
        uint16_t atapeLeft = (10 * (AD_ReadADPin(AD_PORTV5) - AvgValueLow)) - 2000;
        uint16_t atapeCenter = (10 * (AD_ReadADPin(AD_PORTV6) - AvgValueLow)) - 2000;
        printf("corner is %i\r\n tapeRight is %i\r\n tapeLeft is %i\r\n tapeCenter"
                " is %i\r\n AvgValueLow is %i\r\n corner is %i\r\n atapeRight is %i\r\n atapeLeft is %i\r\n atapeCenter"
                " is %i\r\n____________________,\r\n", corner, tapeRight, tapeLeft,
                tapeCenter, AvgValueLow, acorner, atapeRight, atapeLeft, atapeCenter);
        
        delay(magicnumber);
    }
}

void delay(int time) {
    int zeropoint = TIMERS_GetTime();
    while ((TIMERS_GetTime() - zeropoint) < time);
}
