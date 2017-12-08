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

#define BATTERY_CHARGED

#ifdef BATTERY_CHARGED
#define FAST_AND_FURIOUS    1000
#define TOKYO_DRIFT         700
#define NORMAL_SPEED        600
#define SNAIL_PACE          200 
#define NOT_MOVING          0
#define REVERSE             1
#define LITTLE_MORE         675

#define REVERSE_1_SECOND    1000
#define FIRING_BALL_SPEED   800
#endif

#ifdef BATTERY_ALMOST_DISCHARGED
#define FAST_AND_FURIOUS    1000
#define TOKYO_DRIFT         800
#define NORMAL_SPEED        700
#define SNAIL_PACE          200
#define NOT_MOVING          0
#define REVERSE             1
#define LITTLE_MORE         675

#define REVERSE_1_SECOND    1000
#define FIRING_BALL_SPEED   800
#endif

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
    IO_PortsWritePort(PORTX, 0x00);
    PWM_SetDutyCycle(LEFT_MOTOR, NOT_MOVING);
    PWM_SetDutyCycle(RIGHT_MOTOR, NOT_MOVING);
}

// Setting both direction pins to LOW which makes motors turn in reverse
void reverse(void){
    IO_PortsWritePort(PORTX, 0);
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

// Setting both direction pins to HIGH which makes motors turn in reverse
void reverse_again(void){
    IO_PortsWritePort(PORTX, 0);
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

// Setting right direction pins to HIGH which makes right motor reverse
// while left one remains forward
void rotate_clockwise(void){
    IO_PortsWritePort(PORTX, RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, NORMAL_SPEED);
    PWM_SetDutyCycle(RIGHT_MOTOR, NORMAL_SPEED);
}

// Setting left direction pins to HIGH which makes left motor reverse
// while right one remains forward
void rotate_counter_clockwise(void){
    IO_PortsWritePort(PORTX, LEFT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, TOKYO_DRIFT);
    PWM_SetDutyCycle(RIGHT_MOTOR, TOKYO_DRIFT);
}

void turn_right(void){
    IO_PortsWritePort(PORTX, 0);
    IO_PortsWritePort(PORTX, (LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION));
    PWM_SetDutyCycle(LEFT_MOTOR, TOKYO_DRIFT);
    PWM_SetDutyCycle(RIGHT_MOTOR, SNAIL_PACE);
}

void turn_left(void){
    //IO_PortsWritePort(PORTX, 0);
    IO_PortsWritePort(PORTX, LEFT_MOTOR_DIRECTION | RIGHT_MOTOR_DIRECTION);
    PWM_SetDutyCycle(LEFT_MOTOR, SNAIL_PACE);
    PWM_SetDutyCycle(RIGHT_MOTOR, TOKYO_DRIFT);
}

void attack_ATM6(void){
    ping_pong_dispenser_low();
    PWM_SetDutyCycle(LAUNCHER_MOTOR, FIRING_BALL_SPEED);
}

void stop_attack_ATM6(void){
    PWM_SetDutyCycle(LAUNCHER_MOTOR, NOT_MOVING);
}

void ping_pong_dispenser_low(void){
    RC_SetPulseTime(INDEXER, 1150);
}

void ping_pong_dispenser_med(void){
    RC_SetPulseTime(INDEXER, 1600);
}

void ping_pong_dispenser_high(void){
    RC_SetPulseTime(INDEXER, 2000);
}

void final_attack_low(void){
    RC_SetPulseTime(PUSHER, 2000);
}

void final_attack_high(void){
    RC_SetPulseTime(PUSHER, 1000);
}