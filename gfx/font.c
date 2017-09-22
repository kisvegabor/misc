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
#include "fonts/dejavu_30_latin_ext_a.h"
#include "fonts/dejavu_30_latin_ext_b.h"
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

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
font_t * (*font_map[FONT_NAME_NUM])(void);


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
    font_add(FONT_DEJAVU_8, dejavu_8_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_10 != 0
    font_add(FONT_DEJAVU_10, dejavu_10_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_14 != 0
    font_add(FONT_DEJAVU_14, dejavu_14_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_20 != 0
    font_add(FONT_DEJAVU_20, dejavu_20_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_30 != 0
    font_add(FONT_DEJAVU_30, dejavu_30_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_30_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_30_LATIN_EXT_A, dejavu_30_latin_ext_a_get_dsc, dejavu_30_get_dsc());
#endif

#if USE_FONT_DEJAVU_30_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_30_LATIN_EXT_B, dejavu_30_latin_ext_b_get_dsc, dejavu_30_get_dsc());
#endif

#if USE_FONT_DEJAVU_40 != 0
    font_add(FONT_DEJAVU_40, dejavu_40_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_60 != 0
    font_add(FONT_DEJAVU_60, dejavu_60_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_80 != 0
    font_add(FONT_DEJAVU_80, dejavu_80_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_120 != 0
    font_add(FONT_DEJAVU_120, dejavu_120_get_dsc), NULL;
#endif

#if USE_FONT_SYMBOL_30 != 0
    font_add(FONT_SYMBOL_30, symbol_30_get_dsc, NULL);
#endif

#if USE_FONT_SYMBOL_60 != 0
    font_add(FONT_SYMBOL_60, symbol_60_get_dsc, NULL);
#endif
}

/**
 * Create a pair from font name and font dsc. get function. After it 'font_get' can be used for this font
 * @param name name of the font
 * @param dsc_get_fp the font descriptor get function
 * @param parent add this font as charter set extension of 'parent'
 */
void font_add(font_name_t name, font_t * (*dsc_get_fp)(void), font_t * parent)
{
    if(name >= FONT_NAME_NUM) return;
    if(dsc_get_fp == NULL) return;

    font_map[name] = dsc_get_fp;

    font_t * font = dsc_get_fp();
    font->next_page = NULL;

    if(parent) {
        while(parent->next_page != NULL) parent = parent->next_page; /*Got to the last page and as the new one there*/

        parent->next_page = dsc_get_fp();
    }
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
const uint8_t * font_get_bitmap(const font_t * font_p, uint32_t letter)
{
    const font_t * font_i = font_p;
    while(font_i != NULL) {
        if(letter >= font_i->start_ascii && letter < font_i->start_ascii + font_i->letter_cnt) {
            uint32_t index = (letter - font_i->start_ascii) * font_i->height_row * font_i->width_byte;
            return &font_i->bitmaps_a[index];
        }

        font_i = font_i->next_page;
    }

    return NULL;
}

/**
 * Get the width of a letter in a font
 * @param font_p pointer to a font
 * @param letter a letter
 * @return the width of a letter
 */
uint8_t font_get_width(const font_t * font_p, uint32_t letter)
{
    const font_t * font_i = font_p;
    while(font_i != NULL) {
        if(letter >= font_i->start_ascii && letter < font_i->start_ascii + font_i->letter_cnt) {
            uint8_t  w = font_i->fixed_width != 0 ? font_i->fixed_width : font_i->width_bit_a[letter - font_i->start_ascii];
            return w;
        }
        font_i = font_i->next_page;
    }

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
         
#endif /*USE_FONT*/
