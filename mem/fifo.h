/**
 * @file fifo.h
 * Classical First In First Out buffer implementation
 */

#ifndef FIFO_H
#define FIFO_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"

#if USE_FIFO != 0
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "dyn_mem.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**
 * Descriptor of a fifo 
 */
typedef struct
{
    uint32_t item_size;
    uint32_t item_num;
    uint32_t wp;
    uint32_t rp;
    uint8_t empty :1;
    uint8_t full  :1;
    uint8_t * buf;
}fifo_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void fifo_init(fifo_t  * fifo_p, void * buf_p, uint32_t item_size, uint32_t item_num);
bool fifo_push(fifo_t  * fifo_p, const void * data_p);
uint32_t fifo_push_mult(fifo_t  * fifo_p, const void * data_p, uint32_t num);
bool fifo_pop(fifo_t  * fifo_p, void * data_p);
uint32_t fifo_pop_mult(fifo_t  * fifo_p, void * data_p, uint32_t num);
void fifo_clear(fifo_t  * fifo_p);
uint32_t fifo_get_free(fifo_t  * fifo_p);

/**********************
 *      MACROS
 **********************/

#endif 

#endif
