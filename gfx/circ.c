/**
 * @file circ.c
 * Circle drawing algorithm (with Bresenham)
 * Only a 1/8 circle is calculated. Use CIRC_OCT1_X, CIRC_OCT1_Y macros to get
 * the other octets.
 */

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_CIRC != 0

#include "area.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

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
 * Initialize the circle drawing
 * @param c pointer to a point. The coordinates will be calculated here
 * @param tmp point to a variable. It will store temporary data
 * @param radius radius of the circle
 */
void circ_init(point_t * c, cord_t * tmp, cord_t radius)
{
    c->x = radius;
    c->y = 0;
    *tmp = 1 - radius;
}

/**
 * Test the circle drawing is ready or not
 * @param c same as in circ_init
 * @return true if the circle is not ready yet
 */
bool circ_cont(point_t * c)
{
    return c->y <= c->x ? true : false;
}

/**
 * Get the next point from the circle
 * @param c same as in circ_init. The next point stored here.
 * @param tmp same as in circ_init.
 */
void circ_next(point_t * c, cord_t * tmp)
{
    c->y++;
    
    if (*tmp <= 0) {
       (*tmp) += 2 * c->y + 1;   // Change in decision criterion for y -> y+1
    } else {
      c->x--;
      (*tmp) += 2 * (c->y - c->x) + 1;   // Change for y -> y+1, x -> x-1
    }    
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
#endif /*USE_CIRC*/

