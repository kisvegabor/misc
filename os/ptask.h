/**
 * @file ptask.h
 * A Periodic Tasks is a void (*fp) (void) type function which will be called periodically.
 * A priority (5 levels + disable) can be assigned to ptasks. 
 */

#ifndef PTASK_H
#define PTASK_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"

#if USE_PTASK != 0
#include <stdint.h>
#include <stdbool.h>
#include "misc/mem/dyn_mem.h"
#include "misc/mem/linked_list.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
/**
 * Possible priorities for ptasks
 */
typedef enum
{
    PTASK_PRIO_OFF = 0,
    PTASK_PRIO_LOWEST,
    PTASK_PRIO_LOW,
    PTASK_PRIO_MID,
    PTASK_PRIO_HIGH,
    PTASK_PRIO_HIGHEST,
    PTASK_PRIO_NUM,
}ptask_prio_t;

/**
 * Descriptor of a ptask
 */
typedef struct
{
    uint32_t period;
    uint32_t last_run;
    void (*task) (void);
    ptask_prio_t prio;
}ptask_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void ptask_init(void);
void ptask_handler(void);
ptask_t* ptask_create(void (*task) (void), uint32_t period, ptask_prio_t prio);
void ptask_del(ptask_t* ptask_p); 
void ptask_set_prio(ptask_t* ptask_p, ptask_prio_t prio);
void ptask_ready(ptask_t* ptask_p);
void ptask_reset(ptask_t* ptask_p);
void ptask_en(bool en);

/**********************
 *      MACROS
 **********************/

#endif

#endif 
