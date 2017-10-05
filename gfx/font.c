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

#include "fonts/dejavu_10.h"
#include "fonts/dejavu_10_sup.h"
#include "fonts/dejavu_10_latin_ext_a.h"
#include "fonts/dejavu_10_latin_ext_b.h"
#include "fonts/dejavu_10_cyrillic.h"

#include "fonts/dejavu_15.h"
#include "fonts/dejavu_15_sup.h"
#include "fonts/dejavu_15_latin_ext_a.h"
#include "fonts/dejavu_15_latin_ext_b.h"
#include "fonts/dejavu_15_cyrillic.h"

#include "fonts/dejavu_20.h"
#include "fonts/dejavu_20_sup.h"
#include "fonts/dejavu_20_latin_ext_a.h"
#include "fonts/dejavu_20_latin_ext_b.h"
#include "fonts/dejavu_20_cyrillic.h"

#include "fonts/dejavu_25.h"
#include "fonts/dejavu_25_sup.h"
#include "fonts/dejavu_25_latin_ext_a.h"
#include "fonts/dejavu_25_latin_ext_b.h"
#include "fonts/dejavu_25_cyrillic.h"

#include "fonts/dejavu_30.h"
#include "fonts/dejavu_30_sup.h"
#include "fonts/dejavu_30_latin_ext_a.h"
#include "fonts/dejavu_30_latin_ext_b.h"
#include "fonts/dejavu_30_cyrillic.h"

#include "fonts/dejavu_40.h"
#include "fonts/dejavu_40_sup.h"
#include "fonts/dejavu_40_latin_ext_a.h"
#include "fonts/dejavu_40_latin_ext_b.h"
#include "fonts/dejavu_40_cyrillic.h"

#include "fonts/dejavu_50.h"
#include "fonts/dejavu_50_sup.h"
#include "fonts/dejavu_50_latin_ext_a.h"
#include "fonts/dejavu_50_latin_ext_b.h"
#include "fonts/dejavu_50_cyrillic.h"

#include "fonts/dejavu_60.h"
#include "fonts/dejavu_60_sup.h"
#include "fonts/dejavu_60_latin_ext_a.h"
#include "fonts/dejavu_60_latin_ext_b.h"
#include "fonts/dejavu_60_cyrillic.h"

#include "fonts/dejavu_80.h"
#include "fonts/dejavu_80_sup.h"
#include "fonts/dejavu_80_latin_ext_a.h"
#include "fonts/dejavu_80_latin_ext_b.h"
#include "fonts/dejavu_80_cyrillic.h"

#include "fonts/dejavu_100.h"
#include "fonts/dejavu_100_sup.h"
#include "fonts/dejavu_100_latin_ext_a.h"
#include "fonts/dejavu_100_latin_ext_b.h"
#include "fonts/dejavu_100_cyrillic.h"

#include "fonts/dejavu_120.h"
#include "fonts/dejavu_120_sup.h"
#include "fonts/dejavu_120_latin_ext_a.h"
#include "fonts/dejavu_120_latin_ext_b.h"
#include "fonts/dejavu_120_cyrillic.h"


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

    /*DEJAVU 10*/
#if USE_FONT_DEJAVU_10 != 0
    font_add(FONT_DEJAVU_10, dejavu_10_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_10_SUP != 0
    font_add(FONT_DEJAVU_10_SUP, dejavu_10_sup_get_dsc, dejavu_10_get_dsc());
#endif

#if USE_FONT_DEJAVU_10_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_10_LATIN_EXT_A, dejavu_10_latin_ext_a_get_dsc, dejavu_10_get_dsc());
#endif

#if USE_FONT_DEJAVU_10_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_10_LATIN_EXT_B, dejavu_10_latin_ext_b_get_dsc, dejavu_10_get_dsc());
#endif

#if USE_FONT_DEJAVU_10_CYRILLIC != 0
    font_add(FONT_DEJAVU_10_CYRILLIC, dejavu_10_cyrillic_get_dsc, dejavu_10_get_dsc());
#endif

    /*DEJAVU 15*/
#if USE_FONT_DEJAVU_15 != 0
    font_add(FONT_DEJAVU_15, dejavu_15_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_15_SUP != 0
    font_add(FONT_DEJAVU_15_SUP, dejavu_15_sup_get_dsc, dejavu_15_get_dsc());
#endif

#if USE_FONT_DEJAVU_15_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_15_LATIN_EXT_A, dejavu_15_latin_ext_a_get_dsc, dejavu_15_get_dsc());
#endif

#if USE_FONT_DEJAVU_15_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_15_LATIN_EXT_B, dejavu_15_latin_ext_b_get_dsc, dejavu_15_get_dsc());
#endif

#if USE_FONT_DEJAVU_15_CYRILLIC != 0
    font_add(FONT_DEJAVU_15_CYRILLIC, dejavu_15_cyrillic_get_dsc, dejavu_15_get_dsc());
#endif

    /*DEJAVU 20*/
#if USE_FONT_DEJAVU_20 != 0
    font_add(FONT_DEJAVU_20, dejavu_20_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_20_SUP != 0
    font_add(FONT_DEJAVU_20_SUP, dejavu_20_sup_get_dsc, dejavu_20_get_dsc());
#endif

#if USE_FONT_DEJAVU_20_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_20_LATIN_EXT_A, dejavu_20_latin_ext_a_get_dsc, dejavu_20_get_dsc());
#endif

#if USE_FONT_DEJAVU_20_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_20_LATIN_EXT_B, dejavu_20_latin_ext_b_get_dsc, dejavu_20_get_dsc());
#endif

#if USE_FONT_DEJAVU_20_CYRILLIC != 0
    font_add(FONT_DEJAVU_20_CYRILLIC, dejavu_20_cyrillic_get_dsc, dejavu_20_get_dsc());
#endif

    /*DEJAVU 25*/
#if USE_FONT_DEJAVU_25 != 0
    font_add(FONT_DEJAVU_25, dejavu_25_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_25_SUP != 0
    font_add(FONT_DEJAVU_25_SUP, dejavu_25_sup_get_dsc, dejavu_25_get_dsc());
#endif

#if USE_FONT_DEJAVU_25_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_25_LATIN_EXT_A, dejavu_25_latin_ext_a_get_dsc, dejavu_25_get_dsc());
#endif

#if USE_FONT_DEJAVU_25_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_25_LATIN_EXT_B, dejavu_25_latin_ext_b_get_dsc, dejavu_25_get_dsc());
#endif

#if USE_FONT_DEJAVU_25_CYRILLIC != 0
    font_add(FONT_DEJAVU_25_CYRILLIC, dejavu_25_cyrillic_get_dsc, dejavu_25_get_dsc());
#endif

    /*DEJAVU 30*/
#if USE_FONT_DEJAVU_30 != 0
    font_add(FONT_DEJAVU_30, dejavu_30_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_30_SUP != 0
    font_add(FONT_DEJAVU_30_SUP, dejavu_30_sup_get_dsc, dejavu_30_get_dsc());
#endif

#if USE_FONT_DEJAVU_30_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_30_LATIN_EXT_A, dejavu_30_latin_ext_a_get_dsc, dejavu_30_get_dsc());
#endif

#if USE_FONT_DEJAVU_30_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_30_LATIN_EXT_B, dejavu_30_latin_ext_b_get_dsc, dejavu_30_get_dsc());
#endif

#if USE_FONT_DEJAVU_30_CYRILLIC != 0
    font_add(FONT_DEJAVU_30_CYRILLIC, dejavu_30_cyrillic_get_dsc, dejavu_30_get_dsc());
#endif

    /*DEJAVU 40*/
#if USE_FONT_DEJAVU_40 != 0
    font_add(FONT_DEJAVU_40, dejavu_40_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_40_SUP != 0
    font_add(FONT_DEJAVU_40_SUP, dejavu_40_sup_get_dsc, dejavu_40_get_dsc());
#endif

#if USE_FONT_DEJAVU_40_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_40_LATIN_EXT_A, dejavu_40_latin_ext_a_get_dsc, dejavu_40_get_dsc());
#endif

#if USE_FONT_DEJAVU_40_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_40_LATIN_EXT_B, dejavu_40_latin_ext_b_get_dsc, dejavu_40_get_dsc());
#endif

#if USE_FONT_DEJAVU_40_CYRILLIC != 0
    font_add(FONT_DEJAVU_40_CYRILLIC, dejavu_40_cyrillic_get_dsc, dejavu_40_get_dsc());
#endif

    /*DEJAVU 50*/
#if USE_FONT_DEJAVU_50 != 0
    font_add(FONT_DEJAVU_50, dejavu_50_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_50_SUP != 0
    font_add(FONT_DEJAVU_50_SUP, dejavu_50_sup_get_dsc, dejavu_50_get_dsc());
#endif

#if USE_FONT_DEJAVU_50_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_50_LATIN_EXT_A, dejavu_50_latin_ext_a_get_dsc, dejavu_50_get_dsc());
#endif

#if USE_FONT_DEJAVU_50_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_50_LATIN_EXT_B, dejavu_50_latin_ext_b_get_dsc, dejavu_50_get_dsc());
#endif

#if USE_FONT_DEJAVU_50_CYRILLIC != 0
    font_add(FONT_DEJAVU_50_CYRILLIC, dejavu_50_cyrillic_get_dsc, dejavu_50_get_dsc());
#endif

    /*DEJAVU 60*/
#if USE_FONT_DEJAVU_60 != 0
    font_add(FONT_DEJAVU_60, dejavu_60_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_60_SUP != 0
    font_add(FONT_DEJAVU_60_SUP, dejavu_60_sup_get_dsc, dejavu_60_get_dsc());
#endif

#if USE_FONT_DEJAVU_60_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_60_LATIN_EXT_A, dejavu_60_latin_ext_a_get_dsc, dejavu_60_get_dsc());
#endif

#if USE_FONT_DEJAVU_60_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_60_LATIN_EXT_B, dejavu_60_latin_ext_b_get_dsc, dejavu_60_get_dsc());
#endif

#if USE_FONT_DEJAVU_60_CYRILLIC != 0
    font_add(FONT_DEJAVU_60_CYRILLIC, dejavu_60_cyrillic_get_dsc, dejavu_60_get_dsc());
#endif

    /*DEJAVU 80*/
#if USE_FONT_DEJAVU_80 != 0
    font_add(FONT_DEJAVU_80, dejavu_80_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_80_SUP != 0
    font_add(FONT_DEJAVU_80_SUP, dejavu_80_sup_get_dsc, dejavu_80_get_dsc());
#endif

#if USE_FONT_DEJAVU_80_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_80_LATIN_EXT_A, dejavu_80_latin_ext_a_get_dsc, dejavu_80_get_dsc());
#endif

#if USE_FONT_DEJAVU_80_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_80_LATIN_EXT_B, dejavu_80_latin_ext_b_get_dsc, dejavu_80_get_dsc());
#endif

#if USE_FONT_DEJAVU_80_CYRILLIC != 0
    font_add(FONT_DEJAVU_80_CYRILLIC, dejavu_80_cyrillic_get_dsc, dejavu_80_get_dsc());
#endif

    /*DEJAVU 100*/
#if USE_FONT_DEJAVU_100 != 0
    font_add(FONT_DEJAVU_100, dejavu_100_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_100_SUP != 0
    font_add(FONT_DEJAVU_100_SUP, dejavu_100_sup_get_dsc, dejavu_100_get_dsc());
#endif

#if USE_FONT_DEJAVU_100_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_100_LATIN_EXT_A, dejavu_100_latin_ext_a_get_dsc, dejavu_100_get_dsc());
#endif

#if USE_FONT_DEJAVU_100_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_100_LATIN_EXT_B, dejavu_100_latin_ext_b_get_dsc, dejavu_100_get_dsc());
#endif

#if USE_FONT_DEJAVU_100_CYRILLIC != 0
    font_add(FONT_DEJAVU_100_CYRILLIC, dejavu_100_cyrillic_get_dsc, dejavu_100_get_dsc());
#endif

    /*DEJAVU 120*/
#if USE_FONT_DEJAVU_120 != 0
    font_add(FONT_DEJAVU_120, dejavu_120_get_dsc, NULL);
#endif

#if USE_FONT_DEJAVU_120_SUP != 0
    font_add(FONT_DEJAVU_120_SUP, dejavu_120_sup_get_dsc, dejavu_120_get_dsc());
#endif

#if USE_FONT_DEJAVU_120_LATIN_EXT_A != 0
    font_add(FONT_DEJAVU_120_LATIN_EXT_A, dejavu_120_latin_ext_a_get_dsc, dejavu_120_get_dsc());
#endif

#if USE_FONT_DEJAVU_120_LATIN_EXT_B != 0
    font_add(FONT_DEJAVU_120_LATIN_EXT_B, dejavu_120_latin_ext_b_get_dsc, dejavu_120_get_dsc());
#endif

#if USE_FONT_DEJAVU_120_CYRILLIC != 0
    font_add(FONT_DEJAVU_120_CYRILLIC, dejavu_120_cyrillic_get_dsc, dejavu_120_get_dsc());
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
        if(letter >= font_i->first_ascii && letter <= font_i->last_ascii) {
            uint32_t index = (letter - font_i->first_ascii);
            return &font_i->bitmap[font_i->map[index]];
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
        if(letter >= font_i->first_ascii && letter <= font_i->last_ascii) {
            uint32_t index = (letter - font_i->first_ascii);
            return font_i->width[index];
        }
        font_i = font_i->next_page;
    }

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
         
#endif /*USE_FONT*/
