#include <stdint.h>
#include "macros.h"
#include "system_ctrl.h"
#include "gptm_registers.h"
#include "gptm_driver.h"

static GPTM_t * const GPTM_TABLE[] =
{
    [TIMER0] = (GPTM_t *)0x40030000,
    [TIMER1] = (GPTM_t *)0x40031000,
    [TIMER2] = (GPTM_t *)0x40032000,
    [TIMER3] = (GPTM_t *)0x40033000,
    [TIMER4] = (GPTM_t *)0x40034000,
    [TIMER5] = (GPTM_t *)0x40035000,
    [WIDE_TIMER0] = (GPTM_t *)0x40036000,
    [WIDE_TIMER0] = (GPTM_t *)0x40037000,
    [WIDE_TIMER0] = (GPTM_t *)0x4004C000,
    [WIDE_TIMER0] = (GPTM_t *)0x4004D000,
    [WIDE_TIMER0] = (GPTM_t *)0x4004E000,
    [WIDE_TIMER0] = (GPTM_t *)0x4004F000
};