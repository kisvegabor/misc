/**
 * @file gsmmng.h
 * 
 */

#ifndef GSMMNG_H
#define GSMMNG_H

#ifdef __cplusplus
extern "C" {
#endif


/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_GSMMNG != 0
    
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef enum
{
    GSMMNG_STATE_IDLE,
    GSMMNG_STATE_NETW_LEAVE,
    GSMMNG_STATE_NETW_CON,
    GSMMNG_STATE_TCP_CON_DELAY,
    GSMMNG_STATE_TCP_LEAVE,
    GSMMNG_STATE_TCP_CON,
    GSMMNG_STATE_WAIT,
    GSMMNG_STATE_RETRY,
    GSMMNG_STATE_READY,
}gsmmng_state_t;


/**********************
 * GLOBAL PROTOTYPES
 **********************/
void gsmmng_init(void);

void gsmmng_set_last_apn(const char * apn);
void gsmmng_set_last_tcp(const char * ip, const char * port);

void gsmmng_reconnect(void);

const char * gsmmng_get_last_apn(void);
const char * gsmmng_get_last_ip(void);
const char * gsmmng_get_last_port(void);

gsmmng_state_t gsmmng_get_state(void);

/**********************
 *      MACROS
 **********************/

#endif /*USE_GSMMNG != 0*/ 

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif
