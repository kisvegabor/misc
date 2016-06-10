/**
 * @file idle.h
 * Measure the CPU load by measuring how long can CPU count (increment the variable) 
 * if do nothing else in reference time.
 * After it in the main loop also counts. 
 * The ratio of the last count in given time and the reference count will give the idle ratio. 
 */

#ifndef IDLE_H
#define IDLE_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_IDLE != 0

#include <stdint.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void idle_init(void);
uint8_t idle_get(void);
void idle_loop(void);

/**********************
 *      MACROS
 **********************/

#endif

#endif