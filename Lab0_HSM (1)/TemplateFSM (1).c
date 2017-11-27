/*
 * File: TemplateFSM.c
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Template file to set up a Flat State Machine to work with the Events and Services
 * Frameword (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that this file
 * will need to be modified to fit your exact needs, and most of the names will have
 * to be changed to match your code.
 *
 * This is provided as an example and a good place to start.
 *
 *Generally you will just be modifying the statenames and the run function
 *However make sure you do a find and replace to convert every instance of
 *  "Template" to your current state machine's name
 * History
 * When           Who     What/Why
 * -------------- ---     --------
 * 09/13/13 15:17 ghe      added tattletail functionality and recursive calls
 * 01/15/12 11:12 jec      revisions for Gen2 framework
 * 11/07/11 11:26 jec      made the queue static
 * 10/30/11 17:59 jec      fixed references to CurrentEvent in RunTemplateSM()
 * 10/23/11 18:20 jec      began conversion from SMTemplate.c (02/20/07 rev)
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BumperService.h"
#include "TemplateFSM.h"
#include <BOARD.h>
//Uncomment these for the Roaches
#include "roach.h"
//#include "RoachFrameworkEvents.h"
#include <stdio.h>


/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/


/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine.*/


/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/

/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

typedef enum {
    Light,
    Dark,
    FL_Bump,
    FR_Bump,
    Back_Bump,
    Roach_Stuck
} TemplateFSMState_t;

static const char *StateNames[] = {
	"Light",
	"Dark",
	"FL_Bump",
	"FR_Bump",
	"Back_Bump",
};


static TemplateFSMState_t CurrentState = Light; // <- change enum name to match ENUM
static uint8_t MyPriority;


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitTemplateFSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitTemplateFSM(uint8_t Priority) {
    MyPriority = Priority;
    // put us into the Initial PseudoState
    CurrentState = Light;
    // post the initial transition event
    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostTemplateFSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostTemplateFSM(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunTemplateFSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the flat state machine,
 *        as this is called any time a new event is passed to the event queue. This
 *        function will be called recursively to implement the correct order for a
 *        state transition to be: exit current state -> enter next state using the
 *        ES_EXIT and ES_ENTRY events.
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed."
 * @author J. Edward Carryer, 2011.10.23 19:25 */

#define ROACH_CALM    0
#define ROACH_ENRAGED 1

ES_Event RunTemplateFSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    TemplateFSMState_t nextState; // <- need to change enum type here

    static uint8_t bumpCount = 0;
    static uint32_t bumpTime = 0;
    static uint8_t roachTemperment = ROACH_CALM;

    static uint8_t rightBumpRecent = FALSE;
    static uint8_t leftBumpRecent = FALSE;


    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case Light: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_ENTRY) {
                MoveForward(50);
            } else if (ThisEvent.EventType == ES_EXIT) {
                MoveForward(0);
            } else if ((ThisEvent.EventType == LIGHT_EVENT) && (ThisEvent.EventParam == 0x00)) {
                nextState = Dark;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            } else if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                // this is where you would put any actions associated with the
                // transition from the initial pseudo-state into the actual
                // initial state

                // now put the machine into the actual initial state
                RunTemplateFSM(ENTRY_EVENT);
            } else if (ThisEvent.EventType == BUMPER_EVENT && ThisEvent.EventParam & 0x01) {
                nextState = FL_Bump;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;

            } else if (ThisEvent.EventType == BUMPER_EVENT && ThisEvent.EventParam & 0x04) {
                nextState = FR_Bump;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case Dark: // in the first state, replace this with appropriate state
            if (ThisEvent.EventType == ES_ENTRY) {
                ;
            } else if (ThisEvent.EventType == ES_EXIT) {
                ;
            } else if ((ThisEvent.EventType == LIGHT_EVENT) && (ThisEvent.EventParam & 0x01)) {
                nextState = Light;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case FL_Bump:
            if (ThisEvent.EventType == ES_ENTRY) {
                if (roachTemperment == ROACH_ENRAGED) {
                    TurnRoach(-10, -70, 1500);
                } else {
                    TurnRoach(-10, -50, 1000);
                }
            } else if (ThisEvent.EventType == ES_EXIT) {
                MoveForward(0);
            } else if ((ThisEvent.EventType == LIGHT_EVENT) && (ThisEvent.EventParam == 0x00)) {
                nextState = Dark;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            } else if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = Light;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            } else if (ThisEvent.EventType == BUMPER_EVENT && (ThisEvent.EventParam & 0x50)) {
                nextState = Back_Bump;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case FR_Bump:
            if (ThisEvent.EventType == ES_ENTRY) {
                if (roachTemperment == ROACH_ENRAGED) {
                    TurnRoach(-70, -10, 1500);
                } else {
                    TurnRoach(-50, -10, 1000);
                }
            } else if (ThisEvent.EventType == ES_EXIT) {
                MoveForward(0);
            } else if ((ThisEvent.EventType == LIGHT_EVENT) && (ThisEvent.EventParam == 0x00)) {
                nextState = Dark;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            } else if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = Light;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            } else if (ThisEvent.EventType == BUMPER_EVENT && (ThisEvent.EventParam & 0x50)) {
                nextState = Back_Bump;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case Back_Bump:
            if ((ThisEvent.EventType == LIGHT_EVENT) && (ThisEvent.EventParam == 0x00)) {
                nextState = Dark;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            } else {
                nextState = Light;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;
        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (nextState == FL_Bump || nextState == FR_Bump) {
        if (bumpCount == 0) {
            bumpTime = ES_Timer_GetTime();
            roachTemperment = ROACH_CALM;
        } else if (bumpCount > 0) {
            if (ES_Timer_GetTime() - bumpTime < 3000)
                roachTemperment = ROACH_ENRAGED;
            else
                roachTemperment = ROACH_CALM;
            bumpCount = 0;
            bumpTime = ES_Timer_GetTime();
        }
        bumpCount++;
    }

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunTemplateFSM(EXIT_EVENT);
        CurrentState = nextState;
        RunTemplateFSM(ENTRY_EVENT);
    }
    ES_Tail(); // trace call stack end
    return ThisEvent;
}

/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/
void MoveForward(uint8_t speed) {
    Roach_LeftMtrSpeed(speed);
    Roach_RightMtrSpeed(speed);
    return;
}

void TurnRoach(uint8_t spdLeft, uint8_t spdRight, uint16_t time) {
    Roach_LeftMtrSpeed(spdLeft);
    Roach_RightMtrSpeed(spdRight);
    ES_Timer_InitTimer(MOTOR_TIMER, time);
}