#include <stdint.h>
#include "macros.h"
#include "system_ctrl.h"
#include "watchdog_registers.h"
#include "watchdog_driver.h"

static WATCHDOG_t * const WATCHDOG_TABLE[] =
{
    [WDT0] = (WATCHDOG_t *)0x40000000,
    [WDT2] = (WATCHDOG_t *)0x40001000
};

static inline WATCHDOG_t *
get_wdt_base_addr (WATCHDOG_MODULE module)
{
    return WATCHDOG_TABLE[module];
}

void
watchdog_init (WATCHDOG_MODULE module, WDT_CONFIGS * configs)
{
    enable_clock (WD, module);

    WATCHDOG_t * wdt_mod = get_wdt_base_addr (module);

    wdt_mod->load = configs->load_value;
    while (wdt_mod->control.WRC != module);

    wdt_mod->control.RESEN = configs->reset_enable;
    while (wdt_mod->control.WRC != module);

    wdt_mod->control.INTTYPE = configs->interrupt_type;
    while (wdt_mod->control.WRC != module);

    wdt_mod->test.STALL = configs->debug_stall_enable;
    while (wdt_mod->control.WRC != module);

    wdt_mod->control.INTEN = ENABLED;
}