#ifndef SYMBOL_DEF_H
#define SYMBOL_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "misc_conf.h"

/*
 * With no UTF-8 support (128-255)
 * - Basic symbols: 0x80..0x9F
 * - File symbols:  0xA0..0xBF
 * - Basic symbols: 0xC0..0xDF
 * - Reserved:      0xE0..0xFF
 *
 * With UTF-8 support (in Supplemental Private Use Area-A)
 * - Basic symbols:     0xE000..0xE01F
 * - File symbols:      0xE020..0xE03F
 * - Feedback symbols:  0xE040..0xE05F
 * - Reserved:          0xE060..0xE07F
 */

#if TXT_UTF8 == 0
#define SYMBOL_GLYPH_FIRST  0x80
#define SYMBOL_GLYPH_LAST   0xFF
#else
#define SYMBOL_GLYPH_FIRST  0xE000
#define SYMBOL_GLYPH_LAST   0xE080
#endif

/*Basic symbols*/
extern const char symbol_list[];
extern const char symbol_ok[];
extern const char symbol_close[];
extern const char symbol_shutdown[];
extern const char symbol_settings[];
extern const char symbol_home[];
extern const char symbol_refresh[];
extern const char symbol_left[];
extern const char symbol_right[];
extern const char symbol_plus[];
extern const char symbol_minus[];
extern const char symbol_up[];
extern const char symbol_down[];
extern const char symbol_keyboard[];

/*File symbols*/
extern const char symbol_audio[];
extern const char symbol_video[];
extern const char symbol_trash[];
extern const char symbol_download[];
extern const char symbol_drive[];
extern const char symbol_image[];
extern const char symbol_prev[];
extern const char symbol_play[];
extern const char symbol_pause[];
extern const char symbol_stop[];
extern const char symbol_next[];
extern const char symbol_eject[];
extern const char symbol_shuffle[];
extern const char symbol_loop[];
extern const char symbol_directory[];
extern const char symbol_upload[];
extern const char symbol_cut[];
extern const char symbol_copy[];
extern const char symbol_save[];
extern const char symbol_file[];

/*Feedback symbols*/
extern const char symbol_mute[];
extern const char symbol_volume_mid[];
extern const char symbol_volume_max[];
extern const char symbol_warning[];
extern const char symbol_call[];
extern const char symbol_charge[];
extern const char symbol_bell[];
extern const char symbol_gps[];
extern const char symbol_wifi[];
extern const char symbol_battery_full[];
extern const char symbol_battery_3[];
extern const char symbol_battery_2[];
extern const char symbol_battery_1[];
extern const char symbol_battery_empty[];
extern const char symbol_bluetooth[];


#ifdef __cplusplus
} /* extern "C" */
#endif


#endif /*SYMBOL_DEF_H*/
