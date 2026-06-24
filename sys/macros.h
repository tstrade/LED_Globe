#ifndef __MACROS_H__
#define __MACROS_H__

#include "system_ctrl.h"

#ifndef NULL
#define NULL ((void *)0)
#endif /* NULL */

typedef enum { false, true } bool;
typedef enum { DISABLED, ENABLED } mode_t;

#ifndef __USE_LEGACY_GPIO_APERATURE__
#define __USE_LEGACY_GPIO_APERATURE__ true
#endif /* __USE_LEGACY_GPIO_APERATURE__ */

#ifndef enable_clock
#define enable_clock(periph,module) \
    {       \
        *(volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + RCGC##periph) |= (0x1 << module); \
        while ( !(*(volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PR##periph) & (0x1 << module)) ); \
    }
#endif /* enable_clock */



#endif /* __MACROS_H__ */
