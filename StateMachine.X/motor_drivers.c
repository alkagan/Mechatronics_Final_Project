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
#include "pin_configuration.h"
#include "motor_drivers.h"
#include <stdio.h>

#define FAST_AND_FURIOUS    1000
#define TOKYO_DRIFT         750
#define NORMAL_SPEED        650
#define SNAIL_PACE          550
#define NOT_MOVING          0
#define REVERSE             1
#define LITTLE_MORE         675

#define REVERSE_1_SECOND    1000

/* Digital I/O is X, Y, Z Ports, will use the X port for our
 * switches and direction signal
*/

void onwards_NOS(void){    
    IO_PortsWritePort(PORTX, LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, FAST_AND_FURIOUS);
    PWM_SetDutyCycle(RIGHT_MOTOR, FAST_AND_FURIOUS);
}

void onwards_TYO(void){
    IO_PortsWritePort(PORTX, LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, TOKYO_DRIFT);
    PWM_SetDutyCycle(RIGHT_MOTOR, TOKYO_DRIFT);
}

void onwards(void){
    IO_PortsWritePort(PORTX, LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

void snails_pace(void){
    IO_PortsWritePort(PORTX, LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, SNAIL_PACE);
    PWM_SetDutyCycle(RIGHT_MOTOR, SNAIL_PACE);
}

void stop_everything(void){
    printf("stopeverything\r\n");
    IO_PortsWritePort(PORTX, 0x00);
    PWM_SetDutyCycle(LEFT_MOTOR, NOT_MOVING);
    PWM_SetDutyCycle(RIGHT_MOTOR, NOT_MOVING);
}

// Setting both direction pins to HIGH which makes motors turn in reverse
void reverse(void){
    printf("reverse\r\n");
    IO_PortsClearPortBits(PORTX, 0);
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

// Setting both direction pins to HIGH which makes motors turn in reverse
void reverse_again(void){
    printf("reverse_again\r\n");
    IO_PortsWritePort(PORTX, 0);
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

// Setting right direction pins to HIGH which makes right motor reverse
// while left one remains forward
void rotate_clockwise(void){
    printf("rotate_clockwise\r\n");
    //PWM_SetFrequency(PWM_1KHZ);
    IO_PortsWritePort(PORTX, RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, TOKYO_DRIFT);
    PWM_SetDutyCycle(RIGHT_MOTOR, TOKYO_DRIFT);
    
}

// Setting left direction pins to HIGH which makes left motor reverse
// while right one remains forward
void rotate_counter_clockwise(void){
    printf("rotate counterclockwise\r\n");
    IO_PortsWritePort(PORTX, LEFT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, TOKYO_DRIFT);
    PWM_SetDutyCycle(RIGHT_MOTOR, TOKYO_DRIFT);
}

void tape_realign_left_detected(void){
    IO_PortsWritePort(PORTX, 0);
    IO_PortsWritePort(PORTX, (LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION));
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NOT_MOVING);
}


void tape_realign_right_detected(void){
    //IO_PortsWritePort(PORTX, 0);
    IO_PortsWritePort(PORTX, LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, NOT_MOVING);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}