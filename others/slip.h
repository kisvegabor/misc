/**
 * @file slip.h
 * 
 */

#ifndef SLIP_H
#define SLIP_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_SLIP != 0

#include <stdint.h>
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef enum
{
    SLIP_READY,     /*Message is ready in buffer*/
    SLIP_WAIT,      /*Waiting for the next byte*/
    SLIP_LONG,      /*Buffer is not big enough for the message*/
    SLIP_PROT_ERR,  /*Protocol error*/
}slip_res_t;

typedef struct
{
    uint8_t * buf;
    uint32_t buf_size;
    uint32_t data_cnt;
    uint8_t escaping :1;
    uint8_t ready :1;
}slip_proc_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
uint32_t slip_encode(void * dest_p, void * src_p, uint32_t src_len); 
void slip_proc_init(slip_proc_t * slip_p, void * buf_p, uint32_t buf_size);
slip_res_t slip_proc_byte(slip_proc_t  * slip_p, uint8_t next_data);
uint32_t slip_proc_get_msg_length(const slip_proc_t * slip_p);

/**********************
 *      MACROS
 **********************/

#endif

#endif