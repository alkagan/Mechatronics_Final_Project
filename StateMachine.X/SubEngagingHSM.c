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
#include "motor_drivers.h"
#include "TopLevelHSM.h"
#include "SubEngagingHSM.h"
#include "pwm.h"
#include "pin_configuration.h"
#include "TapeEventChecker.h"
#include "serial.h"
#include "LED.h"
#include <stdio.h>

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
typedef enum {
    InitEngagingSubState,
    SubCollision,
    SubCollisionPart2,
    SubTapeDetected,
    SubWhiteDetected,
    SubCornerDetected,
    SubRenDetection,
    SubRenAllign,
    SubRenAllign2,
    SubRenAllign3,
    SubRenAllign4,
    SubTapeDetectedRen,
    SubTapeDetectedWhite,
    SubRenFire,
    SubRenCollision,
    SubRenCollisionPart2,
} SubEngagingHSMState_t;

static const char *StateNames[] = {
    "InitEngagingSubState",
    "SubCollision",
    "SubCollisionPart2",
    "SubTapeDetected",
    "SubWhiteDetected",
    "SubCornerDetected",
    "SubRenDetection",
    "SubRenAllign",
    "SubRenFire",
    "SubRenCollision",
    "SubRenCollisionPart2",
};

#define BUMP_TIME_VALUE             200
#define REALIGNMENT_TIMER_LENGTH    500
#define OH_SHIT_TIMER_LENGTH        2500
#define SHOOTING_TIMER_LENGTH       400

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

static SubEngagingHSMState_t CurrentState = InitEngagingSubState;
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
uint8_t InitSubEngagingHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitEngagingSubState;
    returnEvent = RunSubEngagingHSM(INIT_EVENT);
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
ES_Event RunSubEngagingHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    SubEngagingHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitEngagingSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                // this is where you would put any actions associated with the
                // transition from the initial pseudo-state into the actual
                // initial state

                // now put the machine into the actual initial state
                nextState = SubWhiteDetected;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case SubTapeDetected:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(OH_SHIT_TIMER, OH_SHIT_TIMER_LENGTH);
                    turn_right(); //turn right
                    break;

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

                case REN_DETECTED:
                    nextState = SubRenDetection;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_TIMEOUT:
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

        case SubWhiteDetected:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    turn_left(); //left turn
                    ES_Timer_InitTimer(OH_SHIT_TIMER, OH_SHIT_TIMER_LENGTH);
                    break;

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

                case REN_DETECTED:
                    nextState = SubRenDetection;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_TIMEOUT:
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

        case SubCornerDetected:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    rotate_clockwise_REN();
                    ES_Timer_InitTimer(OH_SHIT_TIMER, 4000);
                    break;

                case TAPE_NOT_DETECTED: //Case tape not detected
                    nextState = SubWhiteDetected; //middle state
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_TIMEOUT:
                    nextState = SubCollision;
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

        case SubCollision:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    reverse();
                    ES_Timer_InitTimer(BUMPER_TIMER, BUMP_TIME_VALUE);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case REN_DETECTED:
                    nextState = SubRenAllign;
                    makeTransition = TRUE;
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


            /*****************************REN DETECEDTED BEHAVIOR***************************************/


            /* I want to adjust the REN tape sensor so that it will only detect 
              immediately before bumping. After o.2 seconds without bump (might 
             have to go longer) we'll know that we aren't bumping into the Ren Ship 
             and it picked up something else*/


            /*RenAllign and RenFire are probably going to have to go in another 
             * Top Level Sub State. Otherwise we'll have to make a RenCollision and RenCollisionPart2*/

        case SubRenDetection:
            //If we don't bump the ship, return to normal behavior
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    onwards();
                    ES_Timer_InitTimer(SHOOTING_TIMER, 900);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                    //If we do bump the ship go to RenAllign
                case BUMP_PRESSED:
                    nextState = SubRenAllign;
                    reverse();
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_TIMEOUT:
                    stop_everything();
                    nextState = SubRenAllign;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default:
                    break;
            }
            break;

        case SubRenAllign:
            switch (ThisEvent.EventType) {
                    /*COLLIDE WITH TARGET UNTIL CORNER IS DETECTED. This marks that we 
                     will have reached the T in front of the target. Then spin to the 
                     left so we are facing the ren ship */

                    /***********************************************************************/
                    /*Need cases for collision behavior here */
                    /***********************************************************************/

                case ES_ENTRY:
                    reverse();
                    ES_Timer_InitTimer(BUMPER_TIMER, 333);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case CORNER_TAPE_NOT_DETECTED:
                    stop_everything();
                    nextState = SubRenAllign2;
                    makeTransition = TRUE;
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == BUMPER_TIMER) {
                        stop_everything();
                        nextState = SubRenAllign2;
                        makeTransition = TRUE;
                    }
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default:
                    break;
            }
            break;

        case SubRenAllign2:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    rotate_clockwise();
                    ES_Timer_InitTimer(BUMPER_TIMER, 420);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == BUMPER_TIMER) {
                        stop_everything();
                        nextState = SubRenAllign3;
                        makeTransition = TRUE;
                    }
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default:
                    break;
            }
            break;

        case SubRenAllign3:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    turn_left_REN();
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case BUMP_PRESSED:
                    stop_everything();
                    final_attack_high();
                    nextState = SubRenAllign4;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;

        case SubRenAllign4:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    //rotate_counter_clockwise_REN();
                    ES_Timer_InitTimer(BUMPER_TIMER, 750);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_TIMEOUT:
                    rotate_counter_clockwise_REN();
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default:
                    break;
            }
            break;

            //        case SubRenCollisionPart2:
            //            switch (ThisEvent.EventType) {
            //                case ES_ENTRY:
            //                    rotate_clockwise();
            //                    ES_Timer_InitTimer(BUMPER_TIMER, BUMP_TIME_VALUE);
            //                    ThisEvent.EventType = ES_NO_EVENT;
            //                    break;
            //
            //                case ES_TIMEOUT:
            //                    nextState = SubRenAllign;
            //                    makeTransition = TRUE;
            //                    ThisEvent.EventType = ES_NO_EVENT;
            //                    break;
            //
            //                case ES_EXIT:
            //                    turn_left_slower();
            //                    break;
            //
            //                default:
            //                    break;
            //            }
            //            break;
            //
            //        case SubRenFire:
            //            switch (ThisEvent.EventType) {
            //                    /*Once the front tape detects we are off the tape, wiggle forward 
            //                     * until we bump the Ren ship, raise the arm, then push forwards, 
            //                     * drifting to the right */
            //                case TAPE_NOT_DETECTED:
            //                    turn_right_slower();
            //                    ThisEvent.EventType = ES_NO_EVENT;
            //
            //                case TAPE_DETECTED:
            //                    turn_left_slower();
            //                    ThisEvent.EventType = ES_NO_EVENT;
            //
            //                case BUMP_PRESSED:
            //                    stop_everything();
            //                    final_attack_high();
            //                    ES_Timer_InitTimer(OH_SHIT_TIMER, 4000);
            //                    ThisEvent.EventType = ES_NO_EVENT;
            //                    break;
            //
            //                case ES_TIMEOUT:
            //                    turn_left_slower();
            //                    break;
            //
            //                default:
            //                    break;
            //            }
            //            break;
            /***************************************************************************************/

        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunSubEngagingHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunSubEngagingHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

