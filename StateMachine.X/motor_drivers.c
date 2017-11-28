/* 
 * File:   motor_drivers.c
 * Author: Kagan
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

/* Digital I/O is X, Y, Z Ports, will use the X port for our
 * switches and direction signal
*/

IO_PortsSetPortInputs(PORTX, PIN3); // this probably won't compile

void onwards_NOS(void){
    PWM_SetDutyCycle(PWM_PORTZ06, MAX_SPEED);
    PWM_SetDutyCycle(PWM_PORTY12, MAX_SPEED);
}

void onwards(void){
    PWM_SetDutyCycle(PWM_PORTZ06, NORMAL_SPEED);
    PWM_SetDutyCycle(PWM_PORTY12, NORMAL_SPEED);
}

void snails_pace(void){
    PWM_SetDutyCycle(PWM_PORTZ06, SNAIL_PACE);
    PWM_SetDutyCycle(PWM_PORTY12, SNAIL_PACE);
}

void stop_everything(void){
    PWM_SetDutyCycle(PWM_PORTZ06, NOT_MOVING);
    PWM_SetDutyCycle(PWM_PORTY12, NOT_MOVING);
}

void reverse(void){
    PWM_SetDutyCycle(PWM_PORTZ06, NORMAL_SPEED);
    PWM_SetDutyCycle(PWM_PORTY12, NORMAL_SPEED);
    
}

void rotate_clockwise(void){
    PWM_SetDutyCycle(PWM_PORTZ06, NORMAL_SPEED);
    //pin direction
    PWM_SetDutyCycle(PWM_PORTY12, NORMAL_SPEED);
}

void rotate_counter_clockwise(void){
    PWM_SetDutyCycle(PWM_PORTZ06, NORMAL_SPEED);
    //pin direction
    PWM_SetDutyCycle(PWM_PORTY12, NORMAL_SPEED);
}