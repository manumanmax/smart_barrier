#ifndef PARK_MANAGER_H
#define PARK_MANAGER_H

#include <stdlib.h>
#include <stdbool.h>
#include "state.h"
#include "io.h"
#include "mooremachine.h"

#define TIMEOUT                         1000000
#define TIMELIMIT                       1500000

#define NUM_OF_STATES                   4
#define NUM_OF_INPUTS                   3
#define NUM_OF_OUTPUTS                  3

/* I/O Pin Definition  */
#define IN_BEFORE_SENSOR_PIN            21
#define IN_RFID_PIN                     22
#define IN_AFTER_SENSOR_PIN             23
#define OUT_RED_LED_PIN                 17
#define OUT_GREEN_LED_PIN               18
#define OUT_BARRIER_PIN                 19

/* States */
#define STANDBY                         0
#define ERROR_CARD                      1
#define VALID_CARD                      2
#define CAR_UNDER_BARRIER               3

/* Outputs */
#define OUT_RED_LED                     0  // 0: led off ; 1: led on
#define OUT_GREEN_LED                   1  // 0: led off ; 1: led on
#define OUT_BARRIER                     2  // 0: barrier down ; 1: barrier up

/* inputs */
#define IN_BEFORE_SENSOR                0
#define IN_RFID                         1
#define IN_AFTER_SENSOR                 2

void begin_cycle(void* p);

/*
* Functions to read and write io
*/
void read_input(void* in);
void write_output(void* out);

//Init function
void initialize(moore_t* m);

#endif