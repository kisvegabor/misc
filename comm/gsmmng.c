/**
 * @file gsmmng.c
 * 
 */

/*********************
 *      INCLUDES
 *********************/
#include "gsmmng.h"
#if USE_GSMMNG != 0

#include <string.h>
#include "hal/gsm/gsm.h"
#include "hal/systick/systick.h"
#include "../os/ptask.h"
#include "hw/dev/ui/log.h"



/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static gsmmng_state_t gsmmng_state;
static uint32_t gsmmng_timestamp = 0;
static char last_apn[128];
static char last_ip[32];
static char last_port[16];

static void gsmmng_task(void * param);
static void gsmmng_netw_leave(gsm_state_t state, const char * txt);
static void gsmmng_netw_con_cb(gsm_state_t state, const char * txt);
static void gsmmng_tcp_leave_cb(gsm_state_t state, const char * txt);
static void gsmmng_tcp_con_cb(gsm_state_t state, const char * txt);

/**********************
 *  STATIC VARIABLES
 **********************/
LOG_FN("gsmmng");

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void gsmmng_init(void)
{
    gsmmng_state = GSMMNG_STATE_NETW_LEAVE;
    ptask_create(gsmmng_task, 1000, PTASK_PRIO_LOW, NULL);
}


void gsmmng_set_last_apn(const char * apn)
{
    strcpy(last_apn, apn);
}

void gsmmng_set_last_tcp(const char * ip, const char * port)
{
    strcpy(last_ip, ip);
    strcpy(last_port, port);
}

gsmmng_state_t gsmmng_get_state(void)
{
    return gsmmng_state;
}

void gsmmng_reconnect(void)
{
    gsmmng_state = GSMMNG_STATE_NETW_LEAVE;
}

const char * gsmmng_get_last_apn(void) 
{
    return last_apn;
}

const char * gsmmng_get_last_ip(void) 
{
    return last_ip;
}

const char * gsmmng_get_last_port(void) 
{
    return last_port;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void gsmmng_task(void * param)
{
    
    if(last_apn[0] == '\0' || last_ip[0] == '\0' || last_port[0] == '\0') {
        return;
    }
    
    switch(gsmmng_state) {
        
        case GSMMNG_STATE_NETW_LEAVE:
            SMSG("netw_leave");
            if(gsm_busy() != false) break;
            
            gsm_netw_leave(gsmmng_netw_leave);
            gsmmng_state = GSMMNG_STATE_WAIT;
            break;
             
        case GSMMNG_STATE_NETW_CON:
            SMSG("netw con");
            gsm_netw_con(last_apn, gsmmng_netw_con_cb);
            gsmmng_state = GSMMNG_STATE_WAIT;
            break;
            
            
        case GSMMNG_STATE_TCP_LEAVE:
            SMSG("tcp leave");
            gsm_tcp_leave(gsmmng_tcp_leave_cb);
            break;
            
        case GSMMNG_STATE_TCP_CON_DELAY:
            SMSG("con delay");
            if(systick_elaps(gsmmng_timestamp) > GSMMNG_TCP_CON_DELAY) {
                gsmmng_state = GSMMNG_STATE_TCP_CON;
            }
            break;
            
        case GSMMNG_STATE_TCP_CON:
            SMSG("tcp con");
            gsm_tcp_con(last_ip, last_port, gsmmng_tcp_con_cb);
            gsmmng_state = GSMMNG_STATE_WAIT;
            break;
            
        case GSMMNG_STATE_WAIT:
            SMSG("wait...");
            break;
            
        case GSMMNG_STATE_RETRY:
            SMSG("retry...");
            if(systick_elaps(gsmmng_timestamp) > GSMMNG_RETRY_WAIT) {
                gsmmng_state = GSMMNG_STATE_NETW_CON;
            }
        break;
        case GSMMNG_STATE_READY:
            SMSG("ready");
            break;
    }
    
}

static void gsmmng_netw_leave(gsm_state_t state, const char * txt)
{
    if(state == GSM_STATE_OK) {
        gsmmng_state = GSMMNG_STATE_NETW_CON;
    } else {
        gsmmng_state = GSMMNG_STATE_RETRY;
    }
}

static void gsmmng_netw_con_cb(gsm_state_t state, const char * txt)
{
    if(state == GSM_STATE_OK) {
        gsmmng_timestamp = systick_get();
        gsmmng_state = GSMMNG_STATE_TCP_CON_DELAY;
    } else {
        gsmmng_timestamp = systick_get();
        gsmmng_state = GSMMNG_STATE_RETRY;
    }
}

static void gsmmng_tcp_leave_cb(gsm_state_t state, const char * txt)
{
    /*Unconditionally go to TCP connect*/
    gsmmng_state = GSMMNG_STATE_TCP_CON;
}

static void gsmmng_tcp_con_cb(gsm_state_t state, const char * txt)
{
    if(state == GSM_STATE_OK) {
        gsmmng_state = GSMMNG_STATE_READY;
    } else {
        gsmmng_timestamp = systick_get();
        gsmmng_state = GSMMNG_STATE_RETRY;
    }
}

#endif /*USE_GSMMNG != 0*/ 