/*
 * File: TapeService.h
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Tape file to set up a simple service to work with the Events and Services
 * Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that this file
 * will need to be modified to fit your exact needs, and most of the names will have
 * to be changed to match your code.
 *
 * This is provided as an example and a good place to start.
 *
 * Created on 23/Oct/2011
 * Updated on 13/Nov/2013
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "BOARD.h"
#include "AD.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "TapeService.h"
#include <stdio.h>
#include "ES_Timers.h"
#include "pin_configuration.h"
#include "TapeEventChecker.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/

#define TAPE_TOGGLE_TIME 5

#define THRESHOLD_CORNER_NOT_DETECTED   700
#define THRESHOLD_TOP_NOT_DETECTED      1110
#define THRESHOLD_LEFT_NOT_DETECTED     1110
#define THRESHOLD_RIGHT_NOT_DETECTED    1110

#define THRESHOLD_CORNER_DETECTED       500    
#define THRESHOLD_TOP_DETECTED          1080
#define THRESHOLD_LEFT_DETECTED         1050
#define THRESHOLD_RIGHT_DETECTED        1000

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/
/* You will need MyPriority and maybe a state variable; you may need others
 * as well. */

static uint8_t MyPriority;

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitTapeService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTapeService function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitTapeService(uint8_t Priority) {
    ES_Event ThisEvent;

    MyPriority = Priority;

    printf("in init service\r\n");

    // in here you write your initialization code
    // this includes all hardware and software initialization
    // that needs to occur.

    // post the initial transition event
    ThisEvent.EventType = ES_INIT;
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostTapeService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostTapeService(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunTapeService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue. 
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author J. Edward Carryer, 2011.10.23 19:25 */
ES_Event RunTapeService(ES_Event ThisEvent) {
    ES_Event ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    /********************************************
     in here you write your service code
     *******************************************/
    static ES_EventTyp_t lastEvent = TAPE_NOT_DETECTED;
    ES_EventTyp_t curEvent = lastEvent;

    static uint16_t AvgValueLow = 0;

    static uint16_t tape_sensor_top;
    static uint16_t tape_sensor_right;
    static uint16_t tape_sensor_left;
    static uint16_t tape_sensor_corner;

    static uint16_t atop;
    static uint16_t aleft;
    static uint16_t aright;
    static uint16_t acorner;

    static uint8_t tape_toggle_flag = 0;
    //uint16_t batVoltage = AD_ReadADPin(BAT_VOLTAGE); // read the battery voltage

    switch (ThisEvent.EventType) {
        case ES_INIT:
            // No hardware initialization or single time setups, those
            // go in the init function above.
            //
            // This section is used to reset service for some reason
            ES_Timer_InitTimer(TAPE_TIMER, TAPE_TOGGLE_TIME);

            break;

        case ES_TIMEOUT:

            ES_Timer_InitTimer(TAPE_TIMER, TAPE_TOGGLE_TIME);

            if (tape_toggle_flag == 0) {
                tape_sensor_top = AD_ReadADPin(TAPE_TOP);
                tape_sensor_left = AD_ReadADPin(TAPE_LEFT);
                tape_sensor_right = AD_ReadADPin(TAPE_RIGHT);
                tape_sensor_corner = AD_ReadADPin(TAPE_CORNER);

                AvgValueLow = (AvgValueLow + tape_sensor_top + tape_sensor_left +
                        tape_sensor_right + tape_sensor_corner) / 5;

//                printf("top: %d\r\n", tape_sensor_top);
//                printf("left: %d\r\n", tape_sensor_left);
//                printf("right: %d\r\n", tape_sensor_right);
//                printf("corner: %d\r\n", tape_sensor_corner);

                tape_toggle_flag = 1;\
                IO_PortsClearPortBits(PORTX, TAPE_TOGGLE);
            } else {
                atop = (10 * (AD_ReadADPin(TAPE_TOP) - AvgValueLow)) - 2000;
                aleft = (10 * (AD_ReadADPin(TAPE_LEFT) - AvgValueLow)) - 2000;
                aright = (10 * (AD_ReadADPin(TAPE_LEFT) - AvgValueLow)) - 2000;
                acorner = (10 * (AD_ReadADPin(TAPE_LEFT) - AvgValueLow)) - 2000;
                
                IO_PortsSetPortBits(PORTX, TAPE_TOGGLE);

//                printf("atop: %d\r\n", atop);
//                printf("aleft: %d\r\n", aleft);
//                printf("aright: %d\r\n", aright);
//                printf("acorner: %d\r\n", acorner);

                if (atop < THRESHOLD_TOP_DETECTED ||
                        aleft < THRESHOLD_LEFT_DETECTED ||
                        aright < THRESHOLD_RIGHT_DETECTED ||
                        acorner < THRESHOLD_CORNER_DETECTED
                        ) {
                    curEvent = TAPE_DETECTED;
                } else if (atop > THRESHOLD_TOP_NOT_DETECTED ||
                        aleft > THRESHOLD_LEFT_NOT_DETECTED ||
                        aright > THRESHOLD_RIGHT_NOT_DETECTED ||
                        acorner > THRESHOLD_CORNER_NOT_DETECTED
                        ) {
                    curEvent = TAPE_NOT_DETECTED;
                }
                tape_toggle_flag = 0;
            }

            if (curEvent != lastEvent) { // check for change from last time
                ReturnEvent.EventType = curEvent;
                if (tape_sensor_top < THRESHOLD_TOP_DETECTED) {
                    ReturnEvent.EventParam = TAPE_TOP_PARAM;
                } else if (tape_sensor_left < THRESHOLD_LEFT_DETECTED) {
                    ReturnEvent.EventParam = TAPE_LEFT_PARAM;
                } else if (tape_sensor_right < THRESHOLD_RIGHT_DETECTED) {
                    ReturnEvent.EventParam = TAPE_RIGHT_PARAM;
                } else if (tape_sensor_corner < THRESHOLD_CORNER_DETECTED) {
                    ReturnEvent.EventParam = TAPE_CORNER_PARAM;
                }
                //returnVal = TRUE;
                lastEvent = curEvent; // update history
#ifndef SIMPLESERVICE_TEST           // keep this as is for test harness
                PostTopLevelHSM(ReturnEvent);
#else
                PostTapeService(ReturnEvent);
#endif   
            }
            break;
#ifdef SIMPLESERVICE_TEST     // keep this as is for test harness      
        default:
            printf("\r\nEvent: %s\tParam: 0x%X",
                    EventNames[ThisEvent.EventType], ThisEvent.EventParam);
            break;
#endif
    }

    return ReturnEvent;
}

/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/

