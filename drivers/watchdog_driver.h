#ifndef __WATCHDOG_DRIVER_H__
#define __WATCHDOG_DRIVER_H__

#include <stdint.h>
#include "macros.h"
#include "watchdog_registers.h"

typedef enum
{
    WDT_STANDARD_INTERRUPT,
    WDT_NONMASKABLE_INTERRUPT
} WDT_INTTYPE;

typedef struct
{
    WDTLOAD load_value;
    WDT_INTTYPE interrupt_type;
    mode_t reset_enable;
    mode_t debug_stall_enable;
} WDT_CONFIGS;

void watchdog_init (WATCHDOG_MODULE module, WDT_CONFIGS * configs);

#endif /* __WATCHDOG_DRIVER_H__ */