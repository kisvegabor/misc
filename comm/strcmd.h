/**
 * @file strcmd.h
 * 
 */

#ifndef STRCMD_H
#define STRCMD_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_STRCMD != 0

#include <stdint.h>

/*********************
 *      DEFINES
 *********************/
#define STRCMD_NOT_READY    (-1)
#define STRCMD_UNKNOWN  (-2)

/**********************
 *      TYPEDEFS
 **********************/
typedef enum
{
    SC_WAIT,        /*Wait for the first data*/
    SC_DATA_REC,    /*Receiving data*/
    SC_N_REC,       /*Wait for \n*/ 
}sc_state_t;

typedef struct
{
    const char ** cmds;
    char * bufp;
    uint16_t buf_len;
    uint16_t bufi;
    sc_state_t state;
}sc_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void strcmd_init(sc_t * sc_p, const char ** cmds, char *buf, uint16_t buf_len);
int16_t strcmd_add(sc_t * sc_p, char c);

/**********************
 *      MACROS
 **********************/

#endif  /*USE_STRCMD != 0*/

#endif