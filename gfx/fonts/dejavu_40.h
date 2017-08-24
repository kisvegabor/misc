#ifndef DEJAVU_40_H
#define DEJAVU_40_H

#ifdef __cplusplus
extern "C" {
#endif


/*Use ISO8859-1 encoding in the IDE*/

#include "misc_conf.h"
#if USE_FONT_DEJAVU_40 != 0


#include <stdint.h>
#include "../font.h"


const font_t * dejavu_40_get_dsc(void);

#endif

#endif
