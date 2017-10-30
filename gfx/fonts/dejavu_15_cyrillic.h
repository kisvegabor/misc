#ifndef DEJAVU_15_CYRILLIC_H
#define DEJAVU_15_CYRILLIC_H

/*Use UTF-8 encoding in the IDE*/

#include "misc_conf.h"

#if  USE_FONT_DEJAVU_15_CYRILLIC != 0

#include <stdint.h>
#include "misc/gfx/font.h"

font_t * dejavu_15_cyrillic_get_dsc(void);

#endif   /*USE_FONT_DEJAVU_15_CYRILLIC != 0*/

#endif   /*DEJAVU_15_CYRILLIC_H*/