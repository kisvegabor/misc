#ifndef DEJAVU_80_H
#define DEJAVU_80_H

/*Use UTF-8 encoding in the IDE*/

#include "misc_conf.h"

#if  USE_FONT_DEJAVU_80 != 0

#include <stdint.h>
#include "misc/gfx/font.h"

font_t * dejavu_80_get_dsc(void);

#endif   /*USE_FONT_DEJAVU_80 != 0*/

#endif   /*DEJAVU_80_H*/