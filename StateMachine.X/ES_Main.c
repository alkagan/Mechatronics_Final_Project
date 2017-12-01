#include <BOARD.h>
#include <xc.h>
#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "pin_configuration.h"

void set_AD_pins(void){
    AD_AddPins(BEACON_DETECTOR | LEFT_SWITCH | RIGHT_SWITCH | TRACK_WIRE |
               TAPE_LEFT | TAPE_TOP | TAPE_RIGHT | TAPE_CORNER);
    printf("AD pins set\r\n");
}

void set_IO_pins(void){
    IO_PortsSetPortOutputs(PORTX,(LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION));
    printf("I/O pins set\r\n");
}

void set_PWM_pins(void){
    PWM_AddPins(LEFT_MOTOR | RIGHT_MOTOR);
    printf("PWM pins set\r\n");
}

void main(void)
{
    ES_Return_t ErrorType;

    BOARD_Init();
    AD_Init();
    TIMERS_Init();
    PWM_Init();
    
    set_AD_pins();
    set_IO_pins();
    set_PWM_pins();

    printf("Starting ES Framework Template\r\n");
    printf("using the 2nd Generation Events & Services Framework\r\n");


    // Your hardware initialization function calls go here

    // now initialize the Events and Services Framework and start it running
    ErrorType = ES_Initialize();
    if (ErrorType == Success) {
        ErrorType = ES_Run();

    }
    //if we got to here, there was an error
    switch (ErrorType) {
    case FailedPointer:
        printf("Failed on NULL pointer");
        break;
    case FailedInit:
        printf("Failed Initialization");
        break;
    default:
        printf("Other Failure: %d", ErrorType);
        break;
    }
    for (;;)
        ;

};

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/
