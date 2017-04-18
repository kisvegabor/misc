/**
 * @file math_base.h
 * 
 */

#ifndef MATH_BASE_H
#define MATH_BASE_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_MATH_BASE != 0

/*********************
 *      DEFINES
 *********************/

#define MATH_MIN(a,b) (a<b?a:b)
#define MATH_MAX(a,b) (a>b?a:b)
#define MATH_ABS(x) ((x)>0?(x):(-(x)))

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#endif /*USE_MATH_BASE*/

#endif
