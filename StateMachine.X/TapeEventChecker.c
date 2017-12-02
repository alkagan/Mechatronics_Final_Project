/*
 * File:   TemplateEventChecker.c
 * Author: Gabriel Hugh Elkaim
 *
 * Template file to set up typical EventCheckers for the  Events and Services
 * Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that
 * this file will need to be modified to fit your exact needs, and most of the
 * names will have to be changed to match your code.
 *
 * This EventCheckers file will work with both FSM's and HSM's.
 *
 * Remember that EventCheckers should only return TRUE when an event has occured,
 * and that the event is a TRANSITION between two detectable differences. They
 * should also be atomic and run as fast as possible for good results.
 *
 * This file includes a test harness that will run the event detectors listed in the
 * ES_Configure file in the project, and will conditionally compile main if the macro
 * EVENTCHECKER_TEST is defined (either in the project or in the file). This will allow
 * you to check you event detectors in their own project, and then leave them untouched
 * for your project unless you need to alter their post functions.
 *
 * Created on September 27, 2013, 8:37 AM
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "TapeEventChecker.h"
#include "ES_Events.h"
#include "serial.h"
#include "AD.h"
#include "pin_configuration.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define THRESHOLD_CORNER_NOT_DETECTED   540
#define THRESHOLD_TOP_NOT_DETECTED      1200
#define THRESHOLD_LEFT_NOT_DETECTED     1350
#define THRESHOLD_RIGHT_NOT_DETECTED    1400

#define THRESHOLD_CORNER_DETECTED       480     
#define THRESHOLD_TOP_DETECTED          1100
#define THRESHOLD_LEFT_DETECTED         1000
#define THRESHOLD_RIGHT_DETECTED        1000
/*******************************************************************************
 * EVENTCHECKER_TEST SPECIFIC CODE                                                             *
 ******************************************************************************/

//#define EVENTCHECKER_TEST
#ifdef EVENTCHECKER_TEST
#include <stdio.h>
#define SaveEvent(x) do {eventName=__func__; storedEvent=x;} while (0)

static const char *eventName;
static ES_Event storedEvent;
#endif

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this EventChecker. They should be functions
   relevant to the behavior of this particular event checker */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/

/* Any private module level variable that you might need for keeping track of
   events would be placed here. Private variables should be STATIC so that they
   are limited in scope to this module. */

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function TemplateCheckBattery(void)
 * @param none
 * @return TRUE or FALSE
 * @brief This function is a prototype event checker that checks the battery voltage
 *        against a fixed threshold (#defined in the .c file). Note that you need to
 *        keep track of previous history, and that the actual battery voltage is checked
 *        only once at the beginning of the function. The function will post an event
 *        of either BATTERY_CONNECTED or BATTERY_DISCONNECTED if the power switch is turned
 *        on or off with the USB cord plugged into the Uno32. Returns TRUE if there was an 
 *        event, FALSE otherwise.
 * @note Use this code as a template for your other event checkers, and modify as necessary.
 * @author Gabriel H Elkaim, 2013.09.27 09:18
 * @modified Gabriel H Elkaim/Max Dunne, 2016.09.12 20:08 */
uint8_t CheckTape(void) {
    static ES_EventTyp_t lastEvent = TAPE_NOT_DETECTED;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    
    uint16_t tape_sensor_top = AD_ReadADPin(TAPE_TOP); 
    uint16_t tape_sensor_left = AD_ReadADPin(TAPE_LEFT);
    uint16_t tape_sensor_right = AD_ReadADPin(TAPE_RIGHT);
    uint16_t tape_sensor_corner = AD_ReadADPin(TAPE_CORNER);
    uint16_t AvgValueLow = (AvgValueLow + tape_sensor_top + tape_sensor_left +
                            tape_sensor_right + tape_sensor_corner ) / 5;
    
    printf("top: %d\r\n", tape_sensor_top);
    printf("left: %d\r\n", tape_sensor_left);
    printf("right: %d\r\n", tape_sensor_right);
    printf("corner: %d\r\n", tape_sensor_corner);
    
    uint16_t atop = (10 * (AD_ReadADPin(TAPE_TOP) - AvgValueLow)) - 2000;
    uint16_t aleft = (10 * (AD_ReadADPin(TAPE_LEFT) - AvgValueLow)) - 2000;
    uint16_t aright = (10 * (AD_ReadADPin(TAPE_RIGHT) - AvgValueLow)) - 2000;
    uint16_t acorner = (10 * (AD_ReadADPin(TAPE_CORNER) - AvgValueLow)) - 2000;
    
    printf("atop: %d\r\n", atop);
    printf("aleft: %d\r\n", aleft);
    printf("aright: %d\r\n", aright);
    printf("acorner: %d\r\n", acorner);
        
    if (tape_sensor_top < THRESHOLD_TOP_DETECTED ||
        tape_sensor_left < THRESHOLD_LEFT_DETECTED ||
        tape_sensor_right < THRESHOLD_RIGHT_DETECTED ||
        tape_sensor_corner < THRESHOLD_CORNER_DETECTED
        ) { 
        curEvent = TAPE_DETECTED;
    } else if (tape_sensor_top > THRESHOLD_TOP_NOT_DETECTED ||
        tape_sensor_left > THRESHOLD_LEFT_NOT_DETECTED ||
        tape_sensor_right > THRESHOLD_RIGHT_NOT_DETECTED ||
        tape_sensor_corner > THRESHOLD_CORNER_NOT_DETECTED
        ){
        curEvent = TAPE_NOT_DETECTED;
    }
    
    if (curEvent != lastEvent) { // check for change from last time
        thisEvent.EventType = curEvent;
        if (tape_sensor_top < THRESHOLD_TOP_DETECTED){
            thisEvent.EventParam = tape_sensor_top;
        } else if (tape_sensor_left < THRESHOLD_LEFT_DETECTED){
            thisEvent.EventParam = tape_sensor_left;
        } else if (tape_sensor_right < THRESHOLD_RIGHT_DETECTED){
            thisEvent.EventParam = tape_sensor_right;
        } else if (tape_sensor_corner < THRESHOLD_CORNER_DETECTED){
            thisEvent.EventParam = tape_sensor_corner;
        }    
        returnVal = TRUE;
        lastEvent = curEvent; // update history
#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
        PostTopLevelHSM(thisEvent);
#else
        SaveEvent(thisEvent);
#endif   
    }
    return (returnVal);
}

/* 
 * The Test Harness for the event checkers is conditionally compiled using
 * the EVENTCHECKER_TEST macro (defined either in the file or at the project level).
 * No other main() can exist within the project.
 * 
 * It requires a valid ES_Configure.h file in the project with the correct events in 
 * the enum, and the correct list of event checkers in the EVENT_CHECK_LIST.
 * 
 * The test harness will run each of your event detectors identically to the way the
 * ES_Framework will call them, and if an event is detected it will print out the function
 * name, event, and event parameter. Use this to test your event checking code and
 * ensure that it is fully functional.
 * 
 * If you are locking up the output, most likely you are generating too many events.
 * Remember that events are detectable changes, not a state in itself.
 * 
 * Once you have fully tested your event checking code, you can leave it in its own
 * project and point to it from your other projects. If the EVENTCHECKER_TEST marco is
 * defined in the project, no changes are necessary for your event checkers to work
 * with your other projects.
 */
#ifdef EVENTCHECKER_TEST
#include <stdio.h>
static uint8_t(*EventList[])(void) = {EVENT_CHECK_LIST};

void PrintEvent(void);

void main(void) {
    BOARD_Init();
    /* user initialization code goes here */

    // Do not alter anything below this line
    int i;

    printf("\r\nEvent checking test harness for %s", __FILE__);

    while (1) {
        if (IsTransmitEmpty()) {
            for (i = 0; i< sizeof (EventList) >> 2; i++) {
                if (EventList[i]() == TRUE) {
                    PrintEvent();
                    break;
                }

            }
        }
    }
}

void PrintEvent(void) {
    printf("\r\nFunc: %s\tEvent: %s\tParam: 0x%X", eventName,
            EventNames[storedEvent.EventType], storedEvent.EventParam);
}
#endif