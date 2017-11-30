/* 
 * File:   motor_drivers.c
 * Author: Kagan
 *
 * @Note: Header guards necessary to account if we are including this 
 * header file in multiple places; the compiler will deal with it once
 * and then will not try to redefine it in other files that it may be
 * included in.
 *
 * Created on November 28, 10:25 AM
 */

#include "motor_drivers.h"

#define MAX_SPEED    1000
#define NORMAL_SPEED 500
#define SNAIL_PACE   200
#define NOT_MOVING   0
#define REVERSE      1
#define LITTLE_MORE  650

#define REVERSE_1_SECOND 1000

#define LEFT_MOTOR              PWM_PORTZ06
#define RIGHT_MOTOR             PWM_PORTY12
#define LEFT_MOTOR_DIRECTION    PIN3
#define RIGHT_MOTOR_DIRECTION   PIN4

/* Digital I/O is X, Y, Z Ports, will use the X port for our
 * switches and direction signal
*/

//IO_PortsSetPortInputs(PORTX, PIN3); // this probably won't compile

void onwards_NOS(void){
    PWM_SetDutyCycle(LEFT_MOTOR, MAX_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, MAX_SPEED);
}

void onwards(void){
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

void snails_pace(void){
    PWM_SetDutyCycle(LEFT_MOTOR, SNAIL_PACE);
    PWM_SetDutyCycle(RIGHT_MOTOR, SNAIL_PACE);
}

void stop_everything(void){
    PWM_SetDutyCycle(LEFT_MOTOR, NOT_MOVING);
    PWM_SetDutyCycle(RIGHT_MOTOR, NOT_MOVING);
}

// Setting both direction pins to HIGH which makes motors turn in reverse
void reverse(void){
    IO_PortsSetPortOutputs(PORTX, LEFT_MOTOR_DIRECTION);
    IO_PortsSetPortOutputs(PORTX, RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

// Setting right direction pins to HIGH which makes right motor reverse
// while left one remains forward
void rotate_clockwise(void){
    IO_PortsSetPortOutputs(PORTX, RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

// Setting left direction pins to HIGH which makes left motor reverse
// while right one remains forward
void rotate_counter_clockwise(void){
    IO_PortsSetPortOutputs(PORTX, LEFT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

void tape_realign_left_detected(void){
    PWM_SetDutyCycle(LEFT_MOTOR, LITTLE_MORE);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

void tape_realign_right_detected(void){
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, LITTLE_MORE);
}