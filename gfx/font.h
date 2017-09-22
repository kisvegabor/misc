/**
 * @file font.h
 * 
 */

#ifndef FONT_H
#define FONT_H

#ifdef __cplusplus
extern "C" {
#endif


/*********************
 *      INCLUDES
 *********************/
#include "../../misc_conf.h"
#if USE_FONT != 0

#include <stdint.h>
#include <stddef.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef enum
{
#if USE_FONT_DEJAVU_8 != 0
    FONT_DEJAVU_8,
#endif
#if USE_FONT_DEJAVU_10 != 0
    FONT_DEJAVU_10,
#endif
#if USE_FONT_DEJAVU_14 != 0
    FONT_DEJAVU_14,
#endif
#if USE_FONT_DEJAVU_20 != 0
    FONT_DEJAVU_20,
#endif
#if USE_FONT_DEJAVU_30 != 0
    FONT_DEJAVU_30,
#endif
#if USE_FONT_DEJAVU_30_LATIN_EXT_A != 0
    FONT_DEJAVU_30_LATIN_EXT_A,
#endif
#if USE_FONT_DEJAVU_30_LATIN_EXT_B != 0
    FONT_DEJAVU_30_LATIN_EXT_B,
#endif
#if USE_FONT_DEJAVU_40 != 0
    FONT_DEJAVU_40,
#endif
#if USE_FONT_DEJAVU_60 != 0
    FONT_DEJAVU_60,
#endif
#if USE_FONT_DEJAVU_80 != 0
    FONT_DEJAVU_80,
#endif
#if USE_FONT_DEJAVU_120 != 0
    FONT_DEJAVU_120,
#endif
#if USE_FONT_SYMBOL_30 != 0
    FONT_SYMBOL_30,
#endif
#if USE_FONT_SYMBOL_60 != 0
    FONT_SYMBOL_60,
#endif

    /*Insert the user defined font names*/
#ifdef FONT_NEW_NAMES
    FONT_NEW_NAMES
#endif

    FONT_NAME_NUM,
}font_name_t;


struct _font_struct;

typedef struct _font_struct
{
    uint32_t letter_cnt;
    uint32_t start_ascii;
    uint8_t width_byte;
    uint8_t height_row;
    uint8_t fixed_width;
    const uint8_t * width_bit_a;
    const uint8_t * bitmaps_a;
    struct _font_struct * next_page;    /*Pointer to a font extension*/
}font_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the built-in fonts
 */
void font_init(void);

/**
 * Create a pair from font name and font dsc. get function. After it 'font_get' can be used for this font
 * @param name name of the font
 * @param dsc_get_fp the font descriptor get function
 * @param parent add this font the charter set extension of 'parent'
 */
void font_add(font_name_t name, font_t * (*dsc_get_fp)(void), font_t * parent);

/**
 * Get the font from its id
 * @param font_id: the id of a font (an element of font_types_t enum)
 * @return pointer to a font descriptor
 */
const font_t * font_get(font_name_t font_id);


/**
 * Return with the bitmap of a font.
 * @param font_p pointer to a font
 * @param letter a letter
 * @return  pointer to the bitmap of the letter
 */
const uint8_t * font_get_bitmap(const font_t * font_p, uint32_t letter);

/**
 * Get the height of a font
 * @param font_p pointer to a font
 * @return the height of a font
 */
static inline uint8_t font_get_height(const font_t * font_p)
{
    return font_p->height_row;
}


/**
 * Get the width of a letter in a font
 * @param font_p pointer to a font
 * @param letter a letter
 * @return the width of a letter
 */
uint8_t font_get_width(const font_t * font_p, uint32_t letter);


/**********************
 *      MACROS
 **********************/

#endif /*USE_FONT*/

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif
