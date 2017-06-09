/**
 * @file font.c
 * 
 */

/*********************
 *      INCLUDES
 *********************/
#include "../../misc_conf.h"
#if USE_FONT != 0

#include <stddef.h>
#include "font.h"
#include "fonts/dejavu_8.h"
#include "fonts/dejavu_10.h"
#include "fonts/dejavu_14.h"
#include "fonts/dejavu_20.h"
#include "fonts/dejavu_30.h"
#include "fonts/dejavu_40.h"
#include "fonts/dejavu_60.h"
#include "fonts/dejavu_80.h"
#include "fonts/dejavu_120.h"
#include "fonts/symbol_30.h"
#include "fonts/symbol_60.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct
{
}font_map_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
const font_t * (*font_map[FONT_NAME_NUM])(void);


/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize the built-in fonts
 */
void font_init(void)
{
#if USE_FONT_DEJAVU_8 != 0
    font_add(FONT_DEJAVU_8, dejavu_8_get_dsc);
#endif

#if USE_FONT_DEJAVU_10 != 0
    font_add(FONT_DEJAVU_10, dejavu_10_get_dsc);
#endif

#if USE_FONT_DEJAVU_14 != 0
    font_add(FONT_DEJAVU_14, dejavu_14_get_dsc);
#endif

#if USE_FONT_DEJAVU_20 != 0
    font_add(FONT_DEJAVU_20, dejavu_20_get_dsc);
#endif

#if USE_FONT_DEJAVU_30 != 0
    font_add(FONT_DEJAVU_30, dejavu_30_get_dsc);
#endif

#if USE_FONT_DEJAVU_40 != 0
    font_add(FONT_DEJAVU_40, dejavu_40_get_dsc);
#endif

#if USE_FONT_DEJAVU_60 != 0
    font_add(FONT_DEJAVU_60, dejavu_60_get_dsc);
#endif

#if USE_FONT_DEJAVU_80 != 0
    font_add(FONT_DEJAVU_80, dejavu_80_get_dsc);
#endif

#if USE_FONT_DEJAVU_120 != 0
    font_add(FONT_DEJAVU_120, dejavu_120_get_dsc);
#endif

#if USE_FONT_SYMBOL_30 != 0
    font_add(FONT_SYMBOL_30, symbol_30_get_dsc);
#endif

#if USE_FONT_SYMBOL_60 != 0
    font_add(FONT_SYMBOL_60, symbol_60_get_dsc);
#endif
}

/**
 * Create a pair from font name and font dsc. get function. After it 'font_get' can be used for this font
 * @param name name of the font
 * @param dsc_get_fp the font descriptor get function
 */
void font_add(font_name_t name, const font_t * (*dsc_get_fp)(void))
{
    if(name >= FONT_NAME_NUM) return;

    font_map[name] = dsc_get_fp;
}


/**
 * Get the font from its id 
 * @param name: name of a font (form 'font_name_t' enum)
 * @return pointer to a font descriptor
 */
const font_t * font_get(font_name_t name)
{

    if(name >= FONT_NAME_NUM) return font_map[FONT_DEFAULT]();

    const font_t * font_p = font_map[name]();

    if(font_p == NULL) font_p = font_map[FONT_DEFAULT]();

    return font_p;
}

/**
 * Return with the bitmap of a font.
 * @param font_p pointer to a font
 * @param letter a letter
 * @return  pointer to the bitmap of the letter
 */
const uint8_t * font_get_bitmap(const font_t * font_p, uint8_t letter)
{
    if(letter < font_p->start_ascii || letter >= font_p->start_ascii + font_p->letter_cnt) return NULL;

    uint32_t index = (letter - font_p->start_ascii) * font_p->height_row * font_p->width_byte;
    return &font_p->bitmaps_a[index];
}

/**
 * Get the width of a letter in a font
 * @param font_p pointer to a font
 * @param letter a letter
 * @return the width of a letter
 */
uint8_t font_get_width(const font_t * font_p, uint8_t letter)
{
    if(letter < font_p->start_ascii) return 0;

    letter -= font_p->start_ascii;
    uint8_t w = 0;
    if(letter < font_p->letter_cnt) {
        w = font_p->fixed_width != 0 ? font_p->fixed_width :
                                      font_p->width_bit_a[letter];
    }

    return w;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
         
#endif /*USE_FONT*/
