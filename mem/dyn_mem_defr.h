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

#if USE_DYN_MEM_DEFR != 0

#include <stdint.h>
#include <stddef.h>

/*********************
 *      DEFINES
 *********************/
            
/**********************
 *      TYPEDEFS
 **********************/

/*The size of this union must be 4 bytes (uint32_t)*/
typedef union
{
	struct
	{
		uint32_t used:1;        //1: if the entry is used
		uint32_t d_size:31;     //Size off the data (1 means 4 bytes)
	};
	uint32_t header;            //The header (used + d_size)
}dmd_headr_t;

typedef struct 
{
    uint8_t * data_p;
    
    dmd_headr_t header;

}dmd_ent_t;

typedef struct
{
    uint32_t cnt_free;
    uint32_t cnt_used;
    uint32_t size_free;
    uint32_t size_free_big;
    uint32_t pct_frag;
}dmd_mon_t;


/**********************
 * GLOBAL PROTOTYPES
 **********************/
void dmd_init(void);
void * dmd_alloc(uint32_t size);
void dmd_free(void  * data);
void * dmd_realloc(void * data_p, uint32_t new_size);
void dmd_defrag(void);
uint32_t dmd_get_size(void * p);
void dmd_monitor(dmd_mon_t * mon_p);

/**********************
 *      MACROS
 **********************/

#define da(p) (*p)
#define dp *


#endif /*USE_DYN_MEM*/

#endif

