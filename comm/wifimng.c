/**
 * @file wifimng.c
 * 
 */

#include "wifimng.h"

#include <string.h>
#include "hal/wifi/wifi.h"
#include "hal/systick/systick.h"
#include "misc/os/ptask.h"
#include "hw/dev/ui/log.h"

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/
#define WIFI_MNG_TCP_CON_DELAY      5000   /*ms*/
#define WIFI_MNG_RETRY_WAIT         10000   /*ms*/ 

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
LOG_FN("wifimng");

static wifimng_state_t wifimng_state;
static uint32_t wifimng_timestamp = 0;
static char last_ssid[64];
static char last_pwd[64];
static char last_ip[32];
static char last_port[16];

static void wifimng_task(void * param);
static void wifimng_netw_ssid_cb(wifi_state_t state, const char * txt);
static void wifimng_netw_con_cb(wifi_state_t state, const char * txt);
static void wifimng_tcp_leave_cb(wifi_state_t state, const char * txt);
static void wifimng_tcp_con_cb(wifi_state_t state, const char * txt);

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void wifimng_init(void)
{
    wifimng_state = WIFIMNG_STATE_NETW_TEST;
    ptask_create(wifimng_task, 1000, PTASK_PRIO_LOW, NULL);
}


void wifimng_set_last_netw(const char * ssid, const char * pwd)
{
    strcpy(last_ssid, ssid);
    strcpy(last_pwd, pwd);
}

void wifimng_set_last_tcp(const char * ip, const char * port)
{
    strcpy(last_ip, ip);
    strcpy(last_port, port);
}

wifimng_state_t wifimng_get_state(void)
{
    return wifimng_state;
}

void wifimng_reconnect(void)
{
    wifimng_state = WIFIMNG_STATE_NETW_TEST;
}

const char * wifimng_get_last_ssid(void) 
{
    return last_ssid;
}

const char * wifimng_get_last_pwd(void) 
{
    return last_ssid;
}

const char * wifimng_get_last_ip(void) 
{
    return last_ip;
}

const char * wifimng_get_last_port(void) 
{
    return last_port;
}


/**********************
 *   STATIC FUNCTIONS
 **********************/

static void wifimng_task(void * param)
{
    
    if(last_ssid[0] == '\0' || last_pwd[0] == '\0' || last_ip[0] == '\0' || last_port[0] == '\0') {
        SWARN("Not configured");
        return;
    }
    
    switch(wifimng_state) {
        
        case WIFIMNG_STATE_NETW_TEST:
            SMSG("Test network");
            if(wifi_busy() != false) break;
            
            wifi_netw_get_ssid(wifimng_netw_ssid_cb);
            wifimng_state = WIFIMNG_STATE_WAIT;
            break;
            
             
        case WIFIMNG_STATE_NETW_CON:
            SMSG("Connect to network: %s, %s", last_ssid, last_pwd);
            wifi_netw_con(last_ssid, last_pwd, wifimng_netw_con_cb);
            wifimng_state = WIFIMNG_STATE_WAIT;
            break;
            
            
        case WIFIMNG_STATE_TCP_LEAVE:
            SMSG("Leave current TCP server");
            wifi_tcp_leave(wifimng_tcp_leave_cb);
            break;
            
        case WIFIMNG_STATE_TCP_CON_DELAY:
            SMSG("Delay before TCP connect");
            if(systick_elaps(wifimng_timestamp) > WIFI_MNG_TCP_CON_DELAY) {
                wifimng_state = WIFIMNG_STATE_TCP_CON;
            }
            break;
            
        case WIFIMNG_STATE_TCP_CON:
            SMSG("Connect to TCP server: %s, %s", last_ip, last_port);
            wifi_tcp_con(last_ip, last_port, wifimng_tcp_con_cb);
            wifimng_state = WIFIMNG_STATE_WAIT;
            break;
            
        case WIFIMNG_STATE_WAIT:
            SMSG("Waiting...");
            break;
            
        case WIFIMNG_STATE_RETRY:
            SMSG("Retry");
            if(systick_elaps(wifimng_timestamp) > WIFI_MNG_RETRY_WAIT) {
                wifimng_state = WIFIMNG_STATE_NETW_CON;
            }
        break;
        case WIFIMNG_STATE_READY:
            break;
    }
    
}

static void wifimng_netw_ssid_cb(wifi_state_t state, const char * txt)
{
    if(state == WIFI_STATE_READY) {
        if(txt[0] == '\0') {
            SMSG("Wifi SSID empty");
            wifimng_state = WIFIMNG_STATE_NETW_CON;
        } else {
            SMSG("Wifi SSID OK: %s", txt);
            wifimng_state = WIFIMNG_STATE_TCP_LEAVE;
        }
    } else {
        SMSG("Wifi SSID Err: %s", txt);
        wifimng_state = WIFIMNG_STATE_NETW_CON;
    }
}

static void wifimng_netw_con_cb(wifi_state_t state, const char * txt)
{
    if(state == WIFI_STATE_READY) {
        SMSG("Wifi Netw con ok: %s", txt);
        wifimng_timestamp = systick_get();
        wifimng_state = WIFIMNG_STATE_TCP_CON_DELAY;
    } else {
        SMSG("Wifi Netw con err: %s", txt);
        wifimng_timestamp = systick_get();
        wifimng_state = WIFIMNG_STATE_RETRY;
    }
}

static void wifimng_tcp_leave_cb(wifi_state_t state, const char * txt)
{
    /*Unconditionally go to TCP connect*/
    wifimng_state = WIFIMNG_STATE_TCP_CON;
}

static void wifimng_tcp_con_cb(wifi_state_t state, const char * txt)
{
    if(state == WIFI_STATE_READY) {
        wifimng_state = WIFIMNG_STATE_READY;
    } else {
        wifimng_timestamp = systick_get();
        wifimng_state = WIFIMNG_STATE_RETRY;
    }
}