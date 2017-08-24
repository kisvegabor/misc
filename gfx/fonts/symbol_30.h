#ifndef SYMBOL_30_H
#define SYMBOL_30_H

#ifdef __cplusplus
extern "C" {
#endif


/*Use ISO8859-1 encoding in the IDE*/
#include "misc_conf.h"
#if  USE_FONT_SYMBOL_30 != 0

#include <stdint.h>
#include "../font.h"

const font_t * symbol_30_get_dsc(void);

#endif

#endif
