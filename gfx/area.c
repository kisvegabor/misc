/**
 * @file 2d.c
 * 
 */

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_AREA != 0

#include "area.h"
#include "../math/math_base.h"

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
 * Initialize an area
 * @param area_p pointer to an area
 * @param x1 left coordinate of the area
 * @param y1 top coordinate of the area
 * @param x2 right coordinate of the area
 * @param y2 bottom coordinate of the area
 */
void area_set(area_t * area_p, cord_t x1, cord_t y1, cord_t x2, cord_t y2)
{
    area_p->x1 = x1;
    area_p->y1 = y1;
    area_p->x2 = x2;
    area_p->y2 = y2;
}

/**
 * Set the width of an area
 * @param area_p pointer to an area
 * @param w the new width of the area (w == 1 makes x1 == x2)
 */
void area_set_width(area_t * area_p, cord_t w)
{
	area_p->x2 = area_p->x1 + w - 1;
}

/**
 * Set the height of an area
 * @param area_p pointer to an area
 * @param h the new height of the area (h == 1 makes y1 == y2)
 */
void area_set_height(area_t * area_p, cord_t h)
{
	area_p->y2 = area_p->y1 + h - 1;
}

/**
 * Set the position of an area (width and height will be kept)
 * @param area_p pointer to an area
 * @param x the new x coordinate of the area
 * @param y the new y coordinate of the area
 */
void area_set_pos(area_t * area_p, cord_t x, cord_t y)
{
	cord_t w = area_get_width(area_p);
	cord_t h = area_get_height(area_p);
	area_p->x1 = x;
	area_p->y1 = y;
	area_set_width(area_p, w);
	area_set_height(area_p, h);
}

/**
 * Return with area of an area (x * y)
 * @param area_p pointer to an area
 * @return size of area
 */
uint32_t area_get_size(const area_t * area_p)
{
    uint32_t size;
    
    size = (uint32_t)(area_p->x2 - area_p->x1 + 1) * 
                     (area_p->y2 - area_p->y1 + 1);
    
    return size;
}

/**
 * Get the common parts of two areas
 * @param res_p pointer to an area, the result will be stored her
 * @param a1_p pointer to the first area
 * @param a2_p pointer to the second area
 * @return false: the two area has NO common parts, res_p is invalid
 */
bool area_union(area_t * res_p, const area_t * a1_p, const area_t * a2_p)
{
    /* Get the smaller area from 'a1_p' and 'a2_p' */
    res_p->x1 = MATH_MAX(a1_p->x1, a2_p->x1);
    res_p->y1 = MATH_MAX(a1_p->y1, a2_p->y1);
    res_p->x2 = MATH_MIN(a1_p->x2, a2_p->x2);
    res_p->y2 = MATH_MIN(a1_p->y2, a2_p->y2);
    
    /*If x1 or y1 greater then x2 or y2 then the areas union is empty*/
    bool union_ok = true;
    if((res_p->x1 > res_p->x2) ||
       (res_p->y1 > res_p->y2))
    {
        union_ok = false;
    }
    
    return union_ok;
}
/**
 * Join two areas into a third which involves the other two 
 * @param res_p pointer to an area, the result will be stored here
 * @param a1_p pointer to the first area
 * @param a2_p pointer to the second area
 */
void area_join(area_t * a_res_p, const area_t * a1_p, const area_t * a2_p)
{
    a_res_p->x1 = MATH_MIN(a1_p->x1, a2_p->x1);
    a_res_p->y1 = MATH_MIN(a1_p->y1, a2_p->y1);
    a_res_p->x2 = MATH_MAX(a1_p->x2, a2_p->x2);
    a_res_p->y2 = MATH_MAX(a1_p->y2, a2_p->y2);
}

/**
 * Check if a point is on an area
 * @param a_p pointer to an area
 * @param p_p pointer to a point
 * @return false:the point is out of the area
 */
bool area_is_point_on(const area_t * a_p, const point_t * p_p)
{
    bool is_on = false;
    
    if((p_p->x >= a_p->x1 && p_p->x <= a_p->x2) &&
       ((p_p->y >= a_p->y1 && p_p->y <= a_p->y2)))
    {
        is_on = true;
    }
    
    return is_on;
}

/**
 * Check if two area has common parts
 * @param a1_p pointer to an area. 
 * @param a2_p pointer to an other area
 * @return false: a1_p and a2_p has no common parts
 */
bool area_is_on(const area_t * a1_p, const area_t * a2_p)
{
    /*Two area are on each other if... */
    
    point_t p;
    /*a2 left-top corner is on a1*/
    p.x = a2_p->x1;
    p.y = a2_p->y1;
    if(area_is_point_on(a1_p, &p)) return true;
    
    /*a2 right-top corner is on a1*/
    p.x = a2_p->x1;
    p.y = a2_p->y1;
    if(area_is_point_on(a1_p, &p)) return true;
    
    /*a2 left-bottom corner is on a1*/
    p.x = a2_p->x1;
    p.y = a2_p->y2;
    if(area_is_point_on(a1_p, &p)) return true;
    
    /*a2 right-bottom corner is on a1*/
    p.x = a2_p->x2;
    p.y = a2_p->y2;
    if(area_is_point_on(a1_p, &p)) return true;
    
    /*a2 is horizontally bigger then a1 and covers it*/
    if((a2_p->x1 <= a1_p->x1 && a2_p->x2 >= a1_p->x2) &&  /*a2 hor. cover a1?*/
      ((a2_p->y1 <= a1_p->y1 && a2_p->y1 >= a1_p->y2) || /*upper edge is on a1?*/
       (a2_p->y2 <= a1_p->y1 && a2_p->y2 >= a1_p->y2) ||/* or lower edge is on a1?*/
       (a2_p->y1 <= a1_p->y1 && a2_p->y2 >= a1_p->y2))) /*or a2 vert bigger then a1*/     
       return true;
    
    /*a2 is vertically bigger then a1 and covers it*/
    if((a2_p->y1 <= a1_p->y1 && a2_p->y2 >= a1_p->y2) &&  /*a2 vert. cover a1?*/
      ((a2_p->x1 <= a1_p->x1 && a2_p->x1 >= a1_p->x2) || /*left edge is on a1?*/
       (a2_p->x2 <= a1_p->x1 && a2_p->x2 >= a1_p->x2) ||/* or right edge is on a1?*/
       (a2_p->x1 <= a1_p->x1 && a2_p->x2 >= a1_p->x2)))  /*or a2 hor. bigger then a1*/     
        return true; 
   
    /*Else no cover*/
    return false;
}

/**
 * Check if an area is fully on an other
 * @param ain_p pointer to an area which could be on aholder_p
 * @param aholder pointer to an area which could involve ain_p
 * @return 
 */
bool area_is_in(const area_t * ain_p, const area_t * aholder_p)
{
    bool is_in = false;
    
    if(ain_p->x1  >= aholder_p->x1 &&
       ain_p->y1  >= aholder_p->y1 &&
       ain_p->x2  <= aholder_p->x2 &&
       ain_p->y2  <= aholder_p->y2)
    {
        is_in = true;
    }
    
    return is_in;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /*USE_AREA*/
