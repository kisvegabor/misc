#ifndef SYMBOL_60_H
#define SYMBOL_60_H

#ifdef __cplusplus
extern "C" {
#endif


/*Use ISO8859-1 encoding in the IDE*/
#include "../../../misc_conf.h"
#if  USE_FONT_SYMBOL_60 != 0

#include <stdint.h>
#include "../font.h"

const font_t * symbol_60_get_dsc(void);

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif
