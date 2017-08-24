#ifndef DEJAVU_80_H
#define DEJAVU_80_H

#ifdef __cplusplus
extern "C" {
#endif


/*Use ISO8859-1 encoding in the IDE*/
#include "misc_conf.h"
#if USE_FONT_DEJAVU_80 != 0


#include <stdint.h>
#include "../font.h"
const font_t * dejavu_80_get_dsc(void);

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif
