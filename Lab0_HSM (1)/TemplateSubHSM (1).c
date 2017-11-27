/*
 * File: TemplateSubHSM.c
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Template file to set up a Heirarchical State Machine to work with the Events and
 * Services Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that
 * this file will need to be modified to fit your exact needs, and most of the names
 * will have to be changed to match your code.
 *
 * There is for a substate machine. Make sure it has a unique name
 *
 * This is provided as an example and a good place to start.
 *
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
#include "BOARD.h"
#include "TemplateHSM.h"
#include "TemplateSubHSM.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
typedef enum {
    Run,
    FL_Bump,
    FR_Bump,
    Back_Bump,
    Jig,
} TemplateSubHSMState_t;

static const char *StateNames[] = {
	"Run",
	"FL_Bump",
	"FR_Bump",
	"Back_Bump",
	"Jig",
};


/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

static TemplateSubHSMState_t CurrentState = Run; // <- change name to match ENUM
static uint8_t MyPriority;


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitTemplateSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitTemplateSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = Run;
    returnEvent = RunTemplateSubHSM(INIT_EVENT);
    ES_Timer_InitTimer(JIG_TIMER, 5000);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunTemplateSubHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the heirarchical state
 *        machine, as this is called any time a new event is passed to the event
 *        queue. This function will be called recursively to implement the correct
 *        order for a state transition to be: exit current state -> enter next state
 *        using the ES_EXIT and ES_ENTRY events.
 * @note Remember to rename to something appropriate.
 *       The lower level state machines are run first, to see if the event is dealt
 *       with there rather than at the current level. ES_EXIT and ES_ENTRY events are
 *       not consumed as these need to pass pack to the higher level state machine.
 * @author J. Edward Carryer, 2011.10.23 19:25
 * @author Gabriel H Elkaim, 2011.10.23 19:25 */
#define ROACH_CALM    0
#define ROACH_ENRAGED 1
#define ENRAGE_TIMER 2000
#define ENRAGE_DURATION 1000
#define JIG_TIME_VAL 1250
#define JIG_TIMEOUT  8000

#define NEITHER    0
#define RIGHT_SIDE 1
#define LEFT_SIDE  2

ES_Event RunTemplateSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    TemplateSubHSMState_t nextState; // <- change type to correct enum

    static uint8_t bumpCount = 0;
    static uint32_t bumpTime = 0;
    static uint8_t roachTemperment = ROACH_CALM;
    static uint8_t jigTimeout = FALSE;
    static uint8_t jigDanceNum = 0;
    static uint8_t lastBump = NEITHER;
    uint8_t curBump = NEITHER;

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case Run: // If current state is initial Psedudo State
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    MoveForward(60);

                    if (jigTimeout) {
                        nextState = Jig;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    } 
                    break;
                case ES_EXIT:
                    MoveForward(0);
                    break;
                case ES_INIT:
                    RunTemplateSubHSM(ENTRY_EVENT);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == JIG_TIMER) {
                        nextState = Jig;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case BUMPER_EVENT:
                    if (ThisEvent.EventParam & 0x01) {
                        nextState = FL_Bump;
                        curBump = LEFT_SIDE;
                    } else if (ThisEvent.EventParam & 0x04) {
                        nextState = FR_Bump;
                        curBump = RIGHT_SIDE;
                    } else
                        break;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case ES_NO_EVENT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;

        case FL_Bump: // in the first state, replace this with correct names
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    if (roachTemperment == ROACH_ENRAGED) {
                        TurnRoach(-10, -60, ENRAGE_DURATION);
                    } else {
                        TurnRoach(-10, -40, 1000);
                    }
                    lastBump = LEFT_SIDE;
                    break;
                case ES_EXIT:
                    MoveForward(0);
                    break;
                case BUMPER_EVENT:
                    if (ThisEvent.EventParam & 0x50) {
                        nextState = Back_Bump;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == JIG_TIMER) {
                        jigTimeout = TRUE;
                    } else {
                        nextState = Run;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case ES_NO_EVENT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;

        case FR_Bump: // in the first state, replace this with correct names
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    if (roachTemperment == ROACH_ENRAGED) {
                        TurnRoach(-70, -10, ENRAGE_DURATION);
                    } else {
                        TurnRoach(-50, -10, 1000);
                    }
                    lastBump = RIGHT_SIDE;
                    
                    break;
                case ES_EXIT:
                    MoveForward(0);
                    break;
                case BUMPER_EVENT:
                    if (ThisEvent.EventParam & 0x50) {
                        nextState = Back_Bump;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == JIG_TIMER) {
                        jigTimeout = TRUE;
                    } else {
                        nextState = Run;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case ES_NO_EVENT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;

        case Back_Bump:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    nextState = Run;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == JIG_TIMER) {
                        jigTimeout = TRUE;
                    }
                    break;
                case ES_EXIT:
                    break;

                default:

                    break;
            }
            break;

        case Jig:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    doALittleDance(jigDanceNum);
                    jigDanceNum = (jigDanceNum + 1) % 3;
                    break;
                case ES_EXIT:
                    MoveForward(0);
                    ES_Timer_InitTimer(JIG_TIMER, JIG_TIMEOUT);
                    jigTimeout = FALSE;
                    break;
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == MOTOR_TIMER) {
                        nextState = Run;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;
                case BUMPER_EVENT:
                    if (ThisEvent.EventParam & 0x01) {
                        nextState = FL_Bump;
                    } else if (ThisEvent.EventParam & 0x04) {
                        nextState = FR_Bump;
                    } else
                        break;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                case ES_NO_EVENT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }

        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (nextState == FL_Bump || nextState == FR_Bump) {
        if (bumpCount == 0) {
            bumpTime = ES_Timer_GetTime();
            roachTemperment = ROACH_CALM;
        } else if (bumpCount > 0) {
            if ((ES_Timer_GetTime() - bumpTime < ENRAGE_TIMER) && (curBump != lastBump))
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
        RunTemplateSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunTemplateSubHSM(ENTRY_EVENT); // <- rename to your own Run function
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
#define TANK_TURN  0
#define TURN_RIGHT 1
#define TURN_LEFT  2
#define SOMEWHAT_FAST_SPEED 75
#define TANK_TURN_SPEED 50
#define JIGGING_TIME 1200

void doALittleDance(uint8_t danceNum) {
    if (danceNum == TANK_TURN) {
        Roach_LeftMtrSpeed(TANK_TURN_SPEED);
        Roach_RightMtrSpeed(-TANK_TURN_SPEED);
        ES_Timer_InitTimer(MOTOR_TIMER, JIGGING_TIME);
    } else if (danceNum == TURN_RIGHT) {
        Roach_LeftMtrSpeed(SOMEWHAT_FAST_SPEED);
        Roach_RightMtrSpeed(SOMEWHAT_FAST_SPEED >> 1);
        ES_Timer_InitTimer(MOTOR_TIMER, JIGGING_TIME);
    } else if (danceNum == TURN_LEFT) {
        Roach_LeftMtrSpeed(SOMEWHAT_FAST_SPEED >> 1);
        Roach_RightMtrSpeed(SOMEWHAT_FAST_SPEED);
        ES_Timer_InitTimer(MOTOR_TIMER, JIGGING_TIME);
    }

}
