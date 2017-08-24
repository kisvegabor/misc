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
#include "misc_conf.h"
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
    /*DEJAVU 10*/
#if USE_FONT_DEJAVU_10 != 0
    FONT_DEJAVU_10,
#endif

#if USE_FONT_DEJAVU_10_SUP != 0
    FONT_DEJAVU_10_SUP,
#endif

#if USE_FONT_DEJAVU_10_LATIN_EXT_A != 0
    FONT_DEJAVU_10_LATIN_EXT_A,
#endif

#if USE_FONT_DEJAVU_10_LATIN_EXT_B != 0
    FONT_DEJAVU_10_LATIN_EXT_B,
#endif

#if USE_FONT_DEJAVU_10_CYRILLIC != 0
    FONT_DEJAVU_10_CYRILLIC,
#endif

    /*DEJAVU 15*/
 #if USE_FONT_DEJAVU_15 != 0
     FONT_DEJAVU_15,
 #endif

 #if USE_FONT_DEJAVU_15_SUP != 0
     FONT_DEJAVU_15_SUP,
 #endif

 #if USE_FONT_DEJAVU_15_LATIN_EXT_A != 0
     FONT_DEJAVU_15_LATIN_EXT_A,
 #endif

 #if USE_FONT_DEJAVU_15_LATIN_EXT_B != 0
     FONT_DEJAVU_15_LATIN_EXT_B,
 #endif

 #if USE_FONT_DEJAVU_15_CYRILLIC != 0
     FONT_DEJAVU_15_CYRILLIC,
 #endif

     /*DEJAVU 20*/
#if USE_FONT_DEJAVU_20 != 0
     FONT_DEJAVU_20,
#endif

#if USE_FONT_DEJAVU_20_SUP != 0
     FONT_DEJAVU_20_SUP,
#endif

#if USE_FONT_DEJAVU_20_LATIN_EXT_A != 0
     FONT_DEJAVU_20_LATIN_EXT_A,
#endif

#if USE_FONT_DEJAVU_20_LATIN_EXT_B != 0
     FONT_DEJAVU_20_LATIN_EXT_B,
#endif

#if USE_FONT_DEJAVU_20_CYRILLIC != 0
     FONT_DEJAVU_20_CYRILLIC,
#endif

  /*DEJAVU 25*/
#if USE_FONT_DEJAVU_25 != 0
   FONT_DEJAVU_25,
#endif

#if USE_FONT_DEJAVU_25_SUP != 0
   FONT_DEJAVU_25_SUP,
#endif

#if USE_FONT_DEJAVU_25_LATIN_EXT_A != 0
   FONT_DEJAVU_25_LATIN_EXT_A,
#endif

#if USE_FONT_DEJAVU_25_LATIN_EXT_B != 0
   FONT_DEJAVU_25_LATIN_EXT_B,
#endif

#if USE_FONT_DEJAVU_25_CYRILLIC != 0
   FONT_DEJAVU_25_CYRILLIC,
#endif

   /*DEJAVU 30*/
#if USE_FONT_DEJAVU_30 != 0
   FONT_DEJAVU_30,
#endif

#if USE_FONT_DEJAVU_30_SUP != 0
   FONT_DEJAVU_30_SUP,
#endif

#if USE_FONT_DEJAVU_30_LATIN_EXT_A != 0
   FONT_DEJAVU_30_LATIN_EXT_A,
#endif

#if USE_FONT_DEJAVU_30_LATIN_EXT_B != 0
   FONT_DEJAVU_30_LATIN_EXT_B,
#endif

#if USE_FONT_DEJAVU_30_CYRILLIC != 0
   FONT_DEJAVU_30_CYRILLIC,
#endif

    /*DEJAVU 40*/
#if USE_FONT_DEJAVU_40 != 0
    FONT_DEJAVU_40,
#endif

#if USE_FONT_DEJAVU_40_SUP != 0
    FONT_DEJAVU_40_SUP,
#endif

#if USE_FONT_DEJAVU_40_LATIN_EXT_A != 0
    FONT_DEJAVU_40_LATIN_EXT_A,
#endif

#if USE_FONT_DEJAVU_40_LATIN_EXT_B != 0
    FONT_DEJAVU_40_LATIN_EXT_B,
#endif

#if USE_FONT_DEJAVU_40_CYRILLIC != 0
    FONT_DEJAVU_40_CYRILLIC,
#endif

    /*DEJAVU 50*/
#if USE_FONT_DEJAVU_50 != 0
    FONT_DEJAVU_50,
#endif

#if USE_FONT_DEJAVU_50_SUP != 0
    FONT_DEJAVU_50_SUP,
#endif

#if USE_FONT_DEJAVU_50_LATIN_EXT_A != 0
    FONT_DEJAVU_50_LATIN_EXT_A,
#endif

#if USE_FONT_DEJAVU_50_LATIN_EXT_B != 0
    FONT_DEJAVU_50_LATIN_EXT_B,
#endif

#if USE_FONT_DEJAVU_50_CYRILLIC != 0
    FONT_DEJAVU_50_CYRILLIC,
#endif

    /*DEJAVU 60*/
#if USE_FONT_DEJAVU_60 != 0
    FONT_DEJAVU_60,
#endif

#if USE_FONT_DEJAVU_60_SUP != 0
    FONT_DEJAVU_60_SUP,
#endif

#if USE_FONT_DEJAVU_60_LATIN_EXT_A != 0
    FONT_DEJAVU_60_LATIN_EXT_A,
#endif

#if USE_FONT_DEJAVU_60_LATIN_EXT_B != 0
    FONT_DEJAVU_60_LATIN_EXT_B,
#endif

#if USE_FONT_DEJAVU_60_CYRILLIC != 0
    FONT_DEJAVU_60_CYRILLIC,
#endif

    /*DEJAVU 80*/
#if USE_FONT_DEJAVU_80 != 0
    FONT_DEJAVU_80,
#endif

#if USE_FONT_DEJAVU_80_SUP != 0
    FONT_DEJAVU_80_SUP,
#endif

#if USE_FONT_DEJAVU_80_LATIN_EXT_A != 0
    FONT_DEJAVU_80_LATIN_EXT_A,
#endif

#if USE_FONT_DEJAVU_80_LATIN_EXT_B != 0
    FONT_DEJAVU_80_LATIN_EXT_B,
#endif

#if USE_FONT_DEJAVU_80_CYRILLIC != 0
    FONT_DEJAVU_80_CYRILLIC,
#endif

    /*DEJAVU 100*/
#if USE_FONT_DEJAVU_100 != 0
    FONT_DEJAVU_100,
#endif

#if USE_FONT_DEJAVU_100_SUP != 0
    FONT_DEJAVU_100_SUP,
#endif

#if USE_FONT_DEJAVU_100_LATIN_EXT_A != 0
    FONT_DEJAVU_100_LATIN_EXT_A,
#endif

#if USE_FONT_DEJAVU_100_LATIN_EXT_B != 0
    FONT_DEJAVU_100_LATIN_EXT_B,
#endif

#if USE_FONT_DEJAVU_100_CYRILLIC != 0
    FONT_DEJAVU_100_CYRILLIC,
#endif

    /*DEJAVU 120*/
#if USE_FONT_DEJAVU_120 != 0
    FONT_DEJAVU_120,
#endif

#if USE_FONT_DEJAVU_120_SUP != 0
    FONT_DEJAVU_120_SUP,
#endif

#if USE_FONT_DEJAVU_120_LATIN_EXT_A != 0
    FONT_DEJAVU_120_LATIN_EXT_A,
#endif

#if USE_FONT_DEJAVU_120_LATIN_EXT_B != 0
    FONT_DEJAVU_120_LATIN_EXT_B,
#endif

#if USE_FONT_DEJAVU_120_CYRILLIC != 0
    FONT_DEJAVU_120_CYRILLIC,
#endif



    /*SYMBOL FONTS*/
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
    uint32_t first_ascii;
    uint32_t last_ascii;
    uint8_t height_row;
    const uint8_t * bitmap;
    const uint32_t * map;
    const uint8_t * width;
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
