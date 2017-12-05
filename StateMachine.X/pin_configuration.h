/*
 * File: pin_configuration.h
 * Author: Kagan
 * 
 * Setting the pin configuration for the final project.
   Total number of AD pins used:  9 (4 on V port, 5 on W port)
   Total number of I/O Pins used: 2
   Total number of PWM pins used: 2
 */

#ifndef PIN_CONFIGURATION_H
#define PIN_CONFIGURATION_H

#include "PWM.h"
#include "IO_Ports.h"
#include "AD.h"

// Beacon Detector Pin Configuration
#define BEACON_DETECTOR         AD_PORTW6   //uint16_t value

// Bump Pin Configuration
#define LEFT_SWITCH             AD_PORTW8   //uint16_t value
#define RIGHT_SWITCH            AD_PORTW5   //uint16_t value

// Motor Pin Configuration
#define LEFT_MOTOR              PWM_PORTZ06 //PWM signal
#define RIGHT_MOTOR             PWM_PORTY12 //PWM signal
#define LEFT_MOTOR_DIRECTION    PIN11       //Port X output pin
#define RIGHT_MOTOR_DIRECTION   PIN12       //Port X output pin
#define LAUNCHER_MOTOR          PWM_PORTY10         //PWM signal

// Tape Sensor Pin Configuration
#define TAPE_CORNER             AD_PORTV3   //uint16_t value
#define TAPE_TOP                AD_PORTV4   //uint16_t value
#define TAPE_RIGHT              AD_PORTV5   //uint16_t value

// Tape Parameters
#define TAPE_TOP_PARAM                  1
#define TAPE_LEFT_PARAM                 2
// Track Wire Pin Configuration
#define TRACK_WIRE              AD_PORTW7   //uint16_t value

#define TAPE_RIGHT_PARAM                3
#define TAPE_CORNER_PARAM               4

// RC Servo Pins
#define INDEXER                 RC_PORTY06  //Servo 
#define PUSHER                  RC_PORTY07  //Servo

// RC Servo Pins
#define RIGHT_BUMPER            PIN5 //uint16_t value
#define LEFT_BUMPER              PIN8 //uint16_t value

#endif
