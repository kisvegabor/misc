/**
 * @file strcmd.c
 * String Command parser. Waits for "\r\n" terminated commands. 
 */

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_STRCMD != 0

#include <string.h>
#include "strcmd.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static int16_t strcmd_test(sc_t * sc_p) ;

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * 
 */
void strcmd_init(sc_t * sc_p, const char ** cmds, char *buf, uint16_t buf_len)
{
    sc_p->cmds = cmds;
    sc_p->bufp = buf;
    sc_p->buf_len = buf_len;
    sc_p->bufi = 0;
    sc_p->state = SC_WAIT;
}

/**
 * 
 * @param buf
 * @param buf_len
 * @param cmds
 * @param c
 * @return 
 */
int16_t strcmd_add(sc_t * sc_p, char c)
{
    int16_t res = STRCMD_NOT_READY;
    
    switch(sc_p->state) {
        case SC_WAIT:
            if(c != '\r' && c != '\n') {
                sc_p->bufp[0] = c;
                sc_p->bufi = 1;
                sc_p->state = SC_DATA_REC;
            }
            break;
        case SC_DATA_REC:
            if(sc_p->bufi >= sc_p->buf_len) {
                sc_p->state = SC_WAIT;  /*Buffer oveflow*/
            } else {
                if(c != '\r') {
                    sc_p->bufp[sc_p->bufi] = c;
                    sc_p->bufi ++;
                } else {
                    sc_p->state = SC_N_REC;
                }
            }
            break;
        case SC_N_REC:
            if(c == '\n') {
                sc_p->bufp[sc_p->bufi] = '\0';  /*Convert to string*/
                res = strcmd_test(sc_p);        
                sc_p->state = SC_WAIT;
            } else {
                sc_p->bufp[sc_p->bufi] = c;
                sc_p->bufi ++;
            }
            break;
    }
            
    return res;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * 
 * @param buf
 * @param cmds
 * @return 
 */
static int16_t strcmd_test(sc_t * sc_p) 
{
    uint16_t i;
    for(i = 0; sc_p->cmds[i][0] != '\0'; i++) {
        if(strcmp(sc_p->bufp, sc_p->cmds[i]) == 0) return i;
    }
    
    return STRCMD_UNKNOWN;
}
#endif