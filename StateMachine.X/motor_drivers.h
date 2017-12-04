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

void onwards_NOS(void);

void onwards_TYO(void);

void onwards(void);

void snails_pace(void);

void stop_everything(void);

void reverse(void);

void rotate_clockwise(void);

void rotate_counter_clockwise(void);

void tape_realign_left_detected(void);

void tape_realign_right_detected(void);

#endif /* MOTORS_DRIVERS_H */