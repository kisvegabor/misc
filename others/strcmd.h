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
/*Return codes*/
#define STRCMD_NOT_READY    (-1)
#define STRCMD_UNKNOWN      (-2)
#define STRCMD_FORMAT_ERR   (-3)
#define STRCMD_OVERFLOW     (-4)

/**********************
 *      TYPEDEFS
 **********************/

/*Internal states of command processing*/
typedef enum
{
    SC_WAIT,        /*Wait for the first data*/
    SC_CMD_REC,     /*Receiving command*/
    SC_PAR_REC,     /*Receiving paramter*/
    SC_N_REC,       /*Wait for \n*/
}sc_state_t;

typedef struct
{
    const char ** cmds;
    char * bufp;
    uint16_t buf_len;
    uint16_t bufi;
    sc_state_t state;
    int16_t last_cmd;
    uint8_t par :1; /*The command has paramter*/
}sc_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void strcmd_init(sc_t * sc_p, const char ** cmds, char *buf, uint16_t buf_len);
int16_t strcmd_add(sc_t * sc_p, char c);
const char * strcmd_get_par(sc_t * sc_p);

/**********************
 *      MACROS
 **********************/

#endif  /*USE_STRCMD != 0*/

#endif
