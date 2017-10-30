#ifndef SYMBOL_40_FILE_H
#define SYMBOL_40_FILE_H

/*Use UTF-8 encoding in the IDE*/

#include "misc_conf.h"

#if  USE_FONT_SYMBOL_40_FILE != 0

#include <stdint.h>
#include "misc/gfx/font.h"

font_t * symbol_40_file_get_dsc(void);

#endif   /*USE_FONT_SYMBOL_40_FILE != 0*/

#endif   /*SYMBOL_40_FILE_H*/