#ifndef DEJAVU_30_H
#define DEJAVU_30_H

#ifdef __cplusplus
extern "C" {
#endif


/*Use ISO8859-1 encoding in the IDE*/

#include "../../../misc_conf.h"
#if  USE_FONT_DEJAVU_30 != 0


#include <stdint.h>
#include "../font.h"


font_t * dejavu_30_get_dsc(void);

#endif

#endif
