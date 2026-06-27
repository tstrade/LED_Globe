#include <stdint.h>
#include <stdlib.h>
#include "macros.h"
#include "system_ctrl.h"
#include "dma_registers.h"
#include "dma_driver.h"
#include "dblalock_align.h"

static DMA_t * const DMA_BASE_ADDR = (DMA_t *)0x400FF000;

void
dma_init (DMA_CONFIGS * configs)
{
    enable_clock (DMA, 0);

    DMA_t * dma_mod = DMA_BASE_ADDR;

    dma_mod->configuration.MASTEN = ENABLED;
    
    DMA_CTRLTABLE_t * primary_ctrltable = (DMA_CTRLTABLE_t *)aligned_alloc (1024, sizeof (DMA_CTRLTABLE_t), true);
    if (primary_ctrltable == NULL)
        return;

    DMA_CTRLTABLE_t * alternate_ctrltable = (DMA_CTRLTABLE_t *)calloc (1, sizeof (DMA_CTRLTABLE_t));
    if (alternate_ctrltable == NULL)
        return;

    dma_mod->channel_control_base_ptr = primary_ctrltable;
    dma_mod->alt_channel_control_base_ptr = alternate_ctrltable;

    if (configs->priority_state == CLEAR)
        dma_mod->channel_priority_clear = configs->channel_priority;
    else
        dma_mod->channel_priority_set = configs->channel_priority;

    if (configs->alternate_state == CLEAR)
        dma_mod->channel_alternate_clear = configs->channel_alternate;
    else
        dma_mod->channel_alternate_set = configs->channel_alternate;

    if (configs->useburst_state == CLEAR)
        dma_mod->channel_useburst_clear = configs->channel_useburst;
    else
        dma_mod->channel_useburst_set = configs->channel_useburst;

    if (configs->reqmask_state == CLEAR)
        dma_mod->channel_req_mask_clear = configs->channel_reqmask;
    else
        dma_mod->channel_req_mask_set = configs->channel_reqmask;
}

