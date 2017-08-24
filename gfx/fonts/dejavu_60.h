#ifndef DEJAVU_60_H
#define DEJAVU_60_H

#ifdef __cplusplus
extern "C" {
#endif


/*Use ISO8859-1 encoding in the IDE*/

#include "misc_conf.h"
#if USE_FONT_DEJAVU_60 != 0


#include <stdint.h>
#include "../font.h"


const font_t * dejavu_60_get_dsc(void);

#endif

#endif
