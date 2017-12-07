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
#include "TopLevelHSM.h"
#include "SubSearchingHSM.h"
#include "pin_configuration.h"
#include "motor_drivers.h"
#include "LED.h"
#include "pwm.h"
#include "IO_Ports.h"
#include <stdio.h>
#include "RC_Servo.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
typedef enum {
    InitSearchSubState,
    SubCollision,
    SubCollisionPart2,
    SubTapeDetected,
    SubWhiteDetected,
    SubCornerDetected,
    SubFinalAdjustment,
    SubTrackWireDetectedState,
    SubTrackWireDetectedStatePart2,
    SubAllThreeDestroyed,
} SubSearchingHSMState_t;

static const char *StateNames[] = {
	"InitSearchSubState",
	"SubCollision",
	"SubCollisionPart2",
	"SubTapeDetected",
	"SubWhiteDetected",
	"SubCornerDetected",
	"SubFinalAdjustment",
	"SubTrackWireDetectedState",
	"SubTrackWireDetectedStatePart2",
	"SubAllThreeDestroyed",
};

#define BUMP_TIME_VALUE             200
#define TRACKWIRE_TIME_LENGTH       0
#define REALIGNMENT_TIMER_LENGTH    500
#define OH_SHIT_TIMER_LENGTH        4000
#define SHOOTING_TIMER_LENGTH       500
/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ***************************er***************************************************/

/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */
 

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

static SubSearchingHSMState_t CurrentState = InitSearchSubState; // <- change name to match ENUM
static uint8_t MyPriority;
static uint8_t kill_count_BRRRRRRRRRAAAAAAPPPPPPP = 0;

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
uint8_t InitSubSearchingHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSearchSubState;
    returnEvent = RunSubSearchingHSM(INIT_EVENT);
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
ES_Event RunSubSearchingHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    SubSearchingHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitSearchSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                // this is where you would put any actions associated with the
                // transition from the initial pseudo-state into the actual
                // initial state

                // now put the machine into the actual initial state
                nextState = SubTapeDetected;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case SubCollision: // in the first state, replace this with correct names
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    reverse();
                    ES_Timer_InitTimer(BUMPER_TIMER, BUMP_TIME_VALUE);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_TIMEOUT:
                    nextState = SubCollisionPart2;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_NO_EVENT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;

        case SubCollisionPart2:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    rotate_clockwise();
                    ES_Timer_InitTimer(BUMPER_TIMER, BUMP_TIME_VALUE);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_TIMEOUT:
                    nextState = SubWhiteDetected;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default:
                    break;
            }
            break;

        case SubTapeDetected:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(OH_SHIT_TIMER, OH_SHIT_TIMER_LENGTH);
                    // tape_realign_right_detected();
                    turn_right(); //turn right
                    //LED_InvertBank(LED_BANK1, 0x0F);
                    //ES_Timer_InitTimer(REALIGNMENT_TIMER, REALIGNMENT_TIMER_LENGTH);
                    break;

                    // case not detected? when left tape is still on? maybe use
                    //that instead of a timer?
                case TAPE_NOT_DETECTED:
                    nextState = SubWhiteDetected;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case BUMP_PRESSED:
                    nextState = SubCollision;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case CORNER_TAPE_DETECTED:
                    nextState = SubCornerDetected;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case TRACKWIRE_DETECTED:
                    //start timer
                    ES_Timer_InitTimer(TRACK_TIMER, TRACKWIRE_TIME_LENGTH);
                    //nextState = SubTrackWireDetectedState;
                    //makeTransition = TRUE;
                    //ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_TIMEOUT:
                    //transition into dummy state
                    if (ThisEvent.EventParam == TRACK_TIMER) {
                        nextState = SubTrackWireDetectedState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    } else if (ThisEvent.EventParam == OH_SHIT_TIMER_LENGTH) {
                        nextState = SubWhiteDetected;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;


                case ES_EXIT:
                    stop_everything();
                    break;

                default:
                    break;
            }
            break;

        case SubWhiteDetected:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    //  tape_realign_left_detected();
                    turn_left(); //left turn
                    ES_Timer_InitTimer(OH_SHIT_TIMER, OH_SHIT_TIMER_LENGTH);
                    //LED_InvertBank(LED_BANK1, 0x0F);
                    //ES_Timer_InitTimer(REALIGNMENT_TIMER, REALIGNMENT_TIMER_LENGTH);
                    break;

                    // case not detected? when left tape is still on? maybe use
                    //that instead of a timer?

                case TAPE_DETECTED:
                    nextState = SubTapeDetected;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case BUMP_PRESSED:
                    nextState = SubCollision;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case CORNER_TAPE_DETECTED:
                    nextState = SubCornerDetected;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case TRACKWIRE_DETECTED:
                    ES_Timer_InitTimer(TRACK_TIMER, TRACKWIRE_TIME_LENGTH);
                    //                    nextState = SubTrackWireDetectedState;
                    //                    makeTransition = TRUE;
                    //                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_TIMEOUT:
                    //transition into dummy state
                    if (ThisEvent.EventParam == TRACK_TIMER) {
                        nextState = SubTrackWireDetectedState;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    } else if (ThisEvent.EventParam == OH_SHIT_TIMER_LENGTH) {
                        nextState = SubWhiteDetected;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;

                case ES_EXIT:
                    stop_everything();
                    break;

                default:
                    break;
            }
            break;

        case SubCornerDetected:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    rotate_clockwise();
                    //reverse
                    //start timer
                    break;
                    //case timeout
                    //nextState = SubFinalAdjustment

                case CORNER_TAPE_NOT_DETECTED: //Case tape not detected
                    nextState = SubTapeDetected; //middle state
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case BUMP_PRESSED:
                    nextState = SubCollision;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_EXIT:
                    stop_everything();
                    break;

                default:
                    break;
            }
            break;

        case SubFinalAdjustment:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    rotate_clockwise();
                    break;

                case CORNER_TAPE_DETECTED:
                    nextState = SubWhiteDetected; //middle state
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case BUMP_PRESSED:
                    nextState = SubCollision;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_EXIT:
                    stop_everything();
                    break;

                default:
                    break;
            }
            break;
            //case middle state
            //check event
            //case tape detected

        case SubTrackWireDetectedState:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(SHOOTING_TIMER, SHOOTING_TIMER_LENGTH);
                    stop_everything();
                    attack_ATM6();
                    break;

                case ES_TIMEOUT:
                    nextState = SubTrackWireDetectedStatePart2;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                default:
                    break;
            }
            break;

        case SubTrackWireDetectedStatePart2:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ping_pong_dispenser_low();
                    break;
                    
                case TRACKWIRE_NOT_DETECTED:
                    ping_pong_dispenser_med();
                    printf("SubSearchingHSM: In subDummyState: trackwire count before: %d\r\n", kill_count_BRRRRRRRRRAAAAAAPPPPPPP);
                    kill_count_BRRRRRRRRRAAAAAAPPPPPPP++;
                    printf("SubSearchingHSM: In subDummyState: trackwire count after: %d\r\n", kill_count_BRRRRRRRRRAAAAAAPPPPPPP);
                    if (kill_count_BRRRRRRRRRAAAAAAPPPPPPP == 3) {
                        IO_PortsSetPortBits(PORTX, ALL_3_DESTROYED);
                        //nextState = SubAllThreeDestroyed;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        ES_Event NextEvent;
                        NextEvent.EventType = ALL_ATM6s_DESTROYED;
                        PostTopLevelHSM(NextEvent);
                        //once kill count is 3 set io port bit high
                        //checker function detects event, leaves state                        
                        //PostTopLevelHSM(ALL_ATM6s_DESTROYED);
                    } else {
                        nextState = SubTapeDetected;
                    }
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_EXIT:
                    stop_everything();
                    ping_pong_dispenser_high();
                    stop_attack_ATM6();
                    break;
                    
                default:
                    break;
            }
            break;

        case SubAllThreeDestroyed:
            printf("SubSearchingHSM: In SubAllthreedestroyed state\r\n");
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    reverse();
                    ES_Timer_InitTimer(BUMPER_TIMER, 500);
                    break;

                case ES_TIMEOUT:
                    stop_everything();
                    break;

                default:
                    break;
            }

            break;



        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunSubSearchingHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunSubSearchingHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

