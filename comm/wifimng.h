/**
 * @file templ.h
 * 
 */

#ifndef WIFIMNG_H
#define WIFIMNG_H

#ifdef __cplusplus
extern "C" {
#endif


/*********************
 *      INCLUDES
 *********************/
#include "../../misc_conf.h"
#if USE_WIFIMNG != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef enum
{
    WIFIMNG_STATE_NETW_TEST,
    WIFIMNG_STATE_NETW_CON,
    WIFIMNG_STATE_TCP_CON_DELAY,
    WIFIMNG_STATE_TCP_LEAVE,
    WIFIMNG_STATE_TCP_CON,
    WIFIMNG_STATE_WAIT,
    WIFIMNG_STATE_RETRY,
    WIFIMNG_STATE_READY,
}wifimng_state_t;


/**********************
 * GLOBAL PROTOTYPES
 **********************/
void wifimng_init(void);

void wifimng_set_last_netw(const char * ssid, const char * pwd);
void wifimng_set_last_tcp(const char * ip, const char * port);

void wifimng_reconnect(void);

const char * wifimng_get_last_ssid(void) ;
const char * wifimng_get_last_pwd(void) ;
const char * wifimng_get_last_ip(void) ;
const char * wifimng_get_last_port(void);

wifimng_state_t wifimng_get_state(void);

/**********************
 *      MACROS
 **********************/

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif
