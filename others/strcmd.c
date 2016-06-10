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
    sc_p->last_cmd = STRCMD_NOT_READY;
    sc_p->par = 0;
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
    sc_state_t res = STRCMD_NOT_READY;
    
    switch(sc_p->state) {
        case SC_WAIT:
            if(c != '\r' && c != '\n') {
                sc_p->bufp[0] = c;
                sc_p->bufi = 1;
                sc_p->state = SC_CMD_REC;
                sc_p->par = 0;
                sc_p->last_cmd = STRCMD_NOT_READY;
            }
            break;
            
        case SC_CMD_REC:
            if(sc_p->bufi >= sc_p->buf_len) {
                sc_p->state = SC_WAIT;  /*Buffer overflow*/
                res = STRCMD_OVERFLOW;
            } else {
                if(c == '\r') {
                    /*Save the command*/
                    sc_p->bufp[sc_p->bufi] = '\0';  /*Convert to string*/
                    sc_p->last_cmd = strcmd_test(sc_p);  
                    sc_p->state = SC_N_REC; /*Command end*/
                } else if(c == '=') {  /*Parameter will come after '='*/
                    /*Save the command*/
                    sc_p->bufp[sc_p->bufi] = '\0';  /*Convert to string*/
                    sc_p->last_cmd = strcmd_test(sc_p);  
                    sc_p->state = SC_PAR_REC;
                    sc_p->bufi = 0;
                    sc_p->par = 1;
                } else {
                    sc_p->bufp[sc_p->bufi] = c;
                    sc_p->bufi ++;
                }
            }
            break;
            
        case SC_PAR_REC: 
            if(sc_p->bufi >= sc_p->buf_len) {
                sc_p->state = SC_WAIT;  /*Buffer overflow*/
                res = STRCMD_OVERFLOW;
            } else {
                if(c == '\r') {
                    sc_p->bufp[sc_p->bufi] = '\0';  /*Convert to string*/
                    sc_p->state = SC_N_REC; /*Parameter end*/
                } else {
                    sc_p->bufp[sc_p->bufi] = c;
                    sc_p->bufi ++;
                }
            }
            break;
            
        case SC_N_REC:
            if(c != '\n') {
                sc_p->last_cmd = STRCMD_FORMAT_ERR;
            }
            sc_p->state = SC_WAIT;
            
            res = sc_p->last_cmd;
            break;
    }
            
    return res;
}

/**
 * Return with parameter of the last command.
 * @param sc_p pointer to an 'sc_t' variable.
 * @return the parameter as string or "" if no parameter
 */
const char * strcmd_get_par(sc_t * sc_p)
{
    if(sc_p->par == 0) return "";
    else return sc_p->bufp;
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