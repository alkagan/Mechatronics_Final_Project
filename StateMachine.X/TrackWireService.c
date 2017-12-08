/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "BOARD.h"
#include "AD.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "TrackWireService.h"
#include "pin_configuration.h"
#include <stdio.h>
#include "motor_drivers.h"


/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define TRACK_SERVICE_TIMER_LENGTH 20
#define TRACKWIRE_DETECTED_THRESHOLD 750
#define TRACKWIRE_NOT_DETECTED_THRESHOLD 200
/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/
static uint8_t MyPriority;
static int trackState = 0;
static uint16_t last_avg_reading = TRACKWIRE_DETECTED_THRESHOLD; // initialize to high bound
static uint16_t trackwire_reading1 = 0;
static uint16_t trackwire_reading2 = 0;
static uint16_t trackwire_reading3 = 0;
static uint16_t trackwire_reading4 = 0;
static uint16_t trackwire_reading5 = 0;
static uint16_t trackwire_reading6 = 0;
static uint16_t trackwire_reading7 = 0;
//static uint16_t trackwire_reading8 = 0;
//static uint16_t trackwire_reading9 = 0;
//static uint16_t trackwire_reading10 = 0;
static uint16_t trackwire_reading_average = 0;

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                  *
 ******************************************************************************/

/**
 * @Function InitTemplateService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateService function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitTrackWireService(uint8_t Priority) {
    ES_Event ThisEvent;

    MyPriority = Priority;

    // in here you write your initialization code
    // this includes all hardware and software initialization
    // that needs to occur.

    // post the initial transition event
    ThisEvent.EventType = ES_INIT;
    ES_Timer_InitTimer(TRACK_SERVICE_TIMER, TRACK_SERVICE_TIMER_LENGTH);
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostTemplateService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostTrackWireService(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunTemplateService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue.
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed."
 * @author J. Edward Carryer, 2011.10.23 19:25 */
ES_Event RunTrackWireService(ES_Event ThisEvent) {
    ES_Event ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    static ES_EventTyp_t last_trackwire_event = TRACKWIRE_NOT_DETECTED;
    ES_EventTyp_t current_trackwire_event;
    uint16_t trackwire_reading = AD_ReadADPin(TRACK_WIRE); // read the battery voltage

    switch (ThisEvent.EventType) {
        case ES_INIT:
            break;

        case ES_TIMERACTIVE:
        case ES_TIMERSTOPPED:
            break;
        case ES_TIMEOUT:
            ES_Timer_InitTimer(TRACK_SERVICE_TIMER, TRACK_SERVICE_TIMER_LENGTH);
            //event checking
            if (trackwire_reading > TRACKWIRE_DETECTED_THRESHOLD) {

                //////////////////////////////////////////////////////
                trackwire_reading1 = AD_ReadADPin(TRACK_WIRE);
                trackwire_reading2 = AD_ReadADPin(TRACK_WIRE);
                trackwire_reading3 = AD_ReadADPin(TRACK_WIRE);
                trackwire_reading4 = AD_ReadADPin(TRACK_WIRE);
                trackwire_reading5 = AD_ReadADPin(TRACK_WIRE);
                trackwire_reading6 = AD_ReadADPin(TRACK_WIRE);
                trackwire_reading7 = AD_ReadADPin(TRACK_WIRE);
                //        trackwire_reading8 = AD_ReadADPin(TRACK_WIRE);
                //        trackwire_reading9 = AD_ReadADPin(TRACK_WIRE);
                //        trackwire_reading10 = AD_ReadADPin(TRACK_WIRE);


                trackwire_reading_average = (trackwire_reading1 + trackwire_reading2
                        + trackwire_reading3 + trackwire_reading4 + trackwire_reading5
                        + trackwire_reading6 + trackwire_reading7 /*+ trackwire_reading8
                + trackwire_reading9 + trackwire_reading10*/) / 7;


                if (trackwire_reading_average > last_avg_reading) {
                    last_avg_reading = trackwire_reading_average;
                    current_trackwire_event = TRACKWIRE_NOT_DETECTED;
                } else {
                    current_trackwire_event = TRACKWIRE_DETECTED;
                    last_avg_reading = TRACKWIRE_DETECTED_THRESHOLD; // reset to high bounds
                }

                //////////////////////////////////////////////////////

            } else if (trackwire_reading < TRACKWIRE_NOT_DETECTED_THRESHOLD) {
                current_trackwire_event = TRACKWIRE_NOT_DETECTED;
                last_avg_reading = TRACKWIRE_DETECTED_THRESHOLD;
            } else {
                current_trackwire_event = last_trackwire_event;
            }

            break;
        default:
            break;

    }

    return ReturnEvent;
}