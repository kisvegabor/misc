/**
 * @file base_math.h
 * 
 */

#ifndef BASE_MATH_H
#define BASE_MATH_H

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/
#ifndef min
#define min(a,b) (a<b?a:b)
#endif

#ifndef max
#define max(a,b) (a>b?a:b)
#endif

#ifndef abs
#define abs(x) ((x)>0?(x):(-(x)))
#endif
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#endif