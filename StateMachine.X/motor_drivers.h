/* 
 * File:   motor_drivers.h
 * Author: Kagan
 *
 * Created on November 28, 10:14 AM
 */

#ifndef MOTOR_DRIVERS_H
#define MOTOR_DRIVERS_H

#include "PWM.h"
#include "IO_Ports.h"
#include "RC_Servo.h"

void onwards_NOS(void);

void onwards_TYO(void);

void onwards(void);

void snails_pace(void);

void stop_everything(void);

void reverse(void);

void rotate_clockwise(void);

void rotate_counter_clockwise(void);

void turn_right(void);

void turn_left(void);

void attack_ATM6(void);

void stop_attack_ATM6(void);

void ping_pong_dispenser_low(void);

void ping_pong_dispenser_med(void);

void ping_pong_dispenser_high(void);

void final_attack_low(void);

void final_attack_high(void);

#endif /* MOTORS_DRIVERS_H */