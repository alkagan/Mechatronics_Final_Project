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
 * for your project unless you need to alter their post func                                   tions.
 *
 * Created on September 27, 2013, 8:37 AM
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "TrackWireEventChecker.h"
#include "ES_Events.h"
#include "serial.h"
#include "AD.h"
#include <stdbool.h> // for I/O pins
#include "IO_Ports.h"
#include "pin_configuration.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/

#define TRACKWIRE_DETECTED_THRESHOLD     600
#define TRACKWIRE_NOT_DETECTED_THRESHOLD 200



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
static uint16_t last_avg_reading = TRACKWIRE_DETECTED_THRESHOLD; // initialize to high bound
static uint16_t trackwire_reading1 = 0;
static uint16_t trackwire_reading2 = 0;
static uint16_t trackwire_reading3 = 0;
static uint16_t trackwire_reading4 = 0;
static uint16_t trackwire_reading5 = 0;
static uint16_t trackwire_reading6 = 0;
static uint16_t trackwire_reading7 = 0;
static uint16_t trackwire_reading8 = 0;
static uint16_t trackwire_reading9 = 0;
static uint16_t trackwire_reading10 = 0;
static uint16_t trackwire_reading_average = 0;

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
uint8_t CheckForTrackWireEvent(void) {
    static ES_EventTyp_t last_track_event = TRACKWIRE_NOT_DETECTED;
    //static last_avg_reading = TRACKWIRE_DETECTED_THRESHOLD; // initialize to high bound
    ES_EventTyp_t current_track_event = last_track_event;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;



    uint16_t trackwire_reading = AD_ReadADPin(TRACK_WIRE);

    if (trackwire_reading > TRACKWIRE_DETECTED_THRESHOLD) {
        trackwire_reading1 = AD_ReadADPin(TRACK_WIRE);
        trackwire_reading2 = AD_ReadADPin(TRACK_WIRE);
        trackwire_reading3 = AD_ReadADPin(TRACK_WIRE);
        trackwire_reading4 = AD_ReadADPin(TRACK_WIRE);
        trackwire_reading5 = AD_ReadADPin(TRACK_WIRE);
        trackwire_reading6 = AD_ReadADPin(TRACK_WIRE);
        trackwire_reading7 = AD_ReadADPin(TRACK_WIRE);
        trackwire_reading8 = AD_ReadADPin(TRACK_WIRE);
        trackwire_reading9 = AD_ReadADPin(TRACK_WIRE);
        trackwire_reading10 = AD_ReadADPin(TRACK_WIRE);

        trackwire_reading_average = (trackwire_reading1 + trackwire_reading2
                + trackwire_reading3 + trackwire_reading4 + trackwire_reading5
                + trackwire_reading6 + trackwire_reading7 + trackwire_reading8
                + trackwire_reading9 + trackwire_reading10) / 10;

        if (trackwire_reading_average > last_avg_reading) {
            last_avg_reading = trackwire_reading_average;
            current_track_event = TRACKWIRE_NOT_DETECTED;
        } else {
            current_track_event = TRACKWIRE_DETECTED;
            last_avg_reading = TRACKWIRE_DETECTED_THRESHOLD; // reset to high bounds
        }
        
    } else if (trackwire_reading < TRACKWIRE_NOT_DETECTED_THRESHOLD) {
        current_track_event = TRACKWIRE_NOT_DETECTED;
        last_avg_reading = TRACKWIRE_DETECTED_THRESHOLD; // reset to high bounds
    } else {
        current_track_event = last_track_event;
    }
    /*******************************************************************************
    
    AD_ReadADPin(TRACK_WIRE);
    
    if (trackwire_reading > TRACKWIRE_DETECTED_THRESHOLD){
        current_track_event = TRACKWIRE_DETECTED;
//        printf("******************************************************************************************************************************\r\n\n");
//        printf("\n\nTrackwireEventChecker: TRACKWIRE DETECTED\r\n");
//        printf("******************************************************************************************************************************\r\n\n");
    } else if (trackwire_reading < TRACKWIRE_NOT_DETECTED_THRESHOLD){
        current_track_event = TRACKWIRE_NOT_DETECTED;
    } else {
        current_track_event = last_track_event;
    }
     *  ******************************************************************************/

    if (current_track_event != last_track_event) { // check for change from last time
        thisEvent.EventType = current_track_event;
        thisEvent.EventParam = trackwire_reading;
        returnVal = TRUE;
        last_track_event = current_track_event; // update history
        PostTopLevelHSM(thisEvent); // ensures continuous checking 

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
    printf("\r\nFunc: %s\tEvent: %s\tParam: %d", eventName,
            EventNames[storedEvent.EventType], storedEvent.EventParam);
}
#endif