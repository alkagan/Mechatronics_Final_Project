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
#define magicnumber 600

void delay(int time);

int main(void) {
    BOARD_Init();
    AD_Init();
    TIMERS_Init();
    AD_AddPins(AD_PORTV3 | AD_PORTV4 | AD_PORTV5 | AD_PORTV6);
    IO_PortsSetPortOutputs(PORTX, PIN3);
    SERIAL_Init();

    while (1) {
        IO_PortsClearPortBits(PORTX, PIN3);
        delay(magicnumber);

        // Accounts for noise
        uint16_t tapeOne = AD_ReadADPin(AD_PORTV3);
        uint16_t tapeTwo = AD_ReadADPin(AD_PORTV4);
        uint16_t tapeThree = AD_ReadADPin(AD_PORTV5);
        uint16_t tapeFour = AD_ReadADPin(AD_PORTV6);
        uint16_t AvgValueLow = (AvgValueLow + tapeOne + tapeTwo + tapeThree + tapeFour) / 5;

        delay(magicnumber);

        IO_PortsSetPortBits(PORTX, PIN3);
        delay(magicnumber);

        // Takes real value of each sensor
        tapeOne = AD_ReadADPin(AD_PORTV3) - AvgValueLow;
        tapeTwo = AD_ReadADPin(AD_PORTV4) - AvgValueLow;
        tapeThree = AD_ReadADPin(AD_PORTV5) - AvgValueLow;
        tapeFour = AD_ReadADPin(AD_PORTV6) - AvgValueLow;
        uint16_t AvgValueHigh = (tapeOne + tapeTwo + tapeThree + tapeFour) / 4;
        printf("tapeOne is %i%,\r\n tapeTwo is %i%\r\n tapeThree is %i%,"
                "\r\n tapeFour is %i%\r\n", tapeOne, tapeTwo, tapeThree, tapeFour);
        delay(magicnumber);
    }
}

void delay(int time) {
    int zeropoint = TIMERS_GetTime();
    while ((TIMERS_GetTime() - zeropoint) < time);
}
