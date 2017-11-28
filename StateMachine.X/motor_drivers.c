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

#define REVERSE_1_SECOND 1000

#define PORT_LEFT               PWM_PORTZ06
#define PORT_RIGHT              PWM_PORTY12
#define DIRECTION_PIN_LEFT      PIN3
#define DIRECTION_PIN_RIGHT     PIN4

/* Digital I/O is X, Y, Z Ports, will use the X port for our
 * switches and direction signal
*/

//IO_PortsSetPortInputs(PORTX, PIN3); // this probably won't compile

void onwards_NOS(void){
    PWM_SetDutyCycle(PORT_LEFT, MAX_SPEED);
    PWM_SetDutyCycle(PORT_RIGHT, MAX_SPEED);
}

void onwards(void){
    PWM_SetDutyCycle(PORT_LEFT, NORMAL_SPEED);
    PWM_SetDutyCycle(PORT_RIGHT, NORMAL_SPEED);
}

void snails_pace(void){
    PWM_SetDutyCycle(PORT_LEFT, SNAIL_PACE);
    PWM_SetDutyCycle(PORT_RIGHT, SNAIL_PACE);
}

void stop_everything(void){
    PWM_SetDutyCycle(PORT_LEFT, NOT_MOVING);
    PWM_SetDutyCycle(PORT_RIGHT, NOT_MOVING);
}

// Setting both direction pins to HIGH which makes motors turn in reverse
void reverse(void){
    IO_PortsSetPortOutputs(PORTX, DIRECTION_PIN_LEFT);
    IO_PortsSetPortOutputs(PORTX, DIRECTION_PIN_RIGHT);
    PWM_SetDutyCycle(PORT_LEFT, NORMAL_SPEED);
    PWM_SetDutyCycle(PORT_RIGHT, NORMAL_SPEED);
}

// Setting right direction pins to HIGH which makes right motor reverse
// while left one remains forward
void rotate_clockwise(void){
    IO_PortsSetPortOutputs(PORTX, DIRECTION_PIN_RIGHT);
    PWM_SetDutyCycle(PORT_LEFT, NORMAL_SPEED);
    PWM_SetDutyCycle(PORT_RIGHT, NORMAL_SPEED);
}

// Setting left direction pins to HIGH which makes left motor reverse
// while right one remains forward
void rotate_counter_clockwise(void){
    IO_PortsSetPortOutputs(PORTX, DIRECTION_PIN_LEFT);
    PWM_SetDutyCycle(PORT_LEFT, NORMAL_SPEED);
    PWM_SetDutyCycle(PORT_RIGHT, NORMAL_SPEED);
}