/**
 * @file dyn_mem.h
 *
 */

#ifndef DYN_MEM_H
#define DYN_MEM_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_DYN_MEM != 0

#include <stdint.h>
#include <stddef.h>


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct
{
    uint32_t cnt_free;
    uint32_t cnt_used;
    uint32_t size_free;
    uint32_t size_free_big;
    uint32_t pct_frag;
}dm_mon_t;


/**********************
 * GLOBAL PROTOTYPES
 **********************/
void dm_init(void);
void * dm_alloc(uint32_t size);
void dm_free(const void  * data);
void * dm_realloc(void * data_p, uint32_t new_size);
void dm_defrag(void);
uint32_t dm_get_size(void * p);
void dm_monitor(dm_mon_t * mon_p);

/**********************
 *      MACROS
 **********************/

#define dm_assert(p) {if(p == NULL) {while(1);}}

#else /*USE_DYN_MEM == 0*/
#include <stdlib.h> /*To use normal malloc/free instead*/
#define dm_assert(p) {if(p == NULL) {while(1);}}

#endif /*USE_DYN_MEM*/

#endif /*DYN_MEM_H*/

