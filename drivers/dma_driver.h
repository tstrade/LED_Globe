#ifndef __DMA_DRIVER_H__
#define __DMA_DRIVER_H__

#include <stdint.h>
#include "macros.h"

typedef struct
{
    volatile uint32_t ADDR;
} DMASCRENDP;

typedef struct
{
    volatile uint32_t ADDR;
} DMADSTENDP;

typedef struct
{
    volatile uint8_t XFERMODE : 3;
    volatile uint8_t NXTUSEBURST : 1;
    volatile uint16_t XFERSIZE : 10;
    volatile uint8_t ARBSIZE : 4;
    volatile uint8_t _reserved : 6;
    volatile uint8_t SRCSIZE : 2;
    volatile uint8_t SRCINC : 2;
    volatile uint8_t DSTSIZE : 2;
    volatile uint8_t DSTINC : 2;
} DMACHCTL;

typedef struct
{
    DMASCRENDP channel_src_addr_end_ptr;
    DMADSTENDP channel_dst_addr_end_ptr;
    DMACHCTL channel_control_word;
} DMA_CTRLTABLE_t;

typedef struct
{
    DMA_CTRLTABLE_t channel_control_table;
    DMA_CTRLTABLE_t alt_channel_control_table;
    state_t priority_state;
    uint32_t channel_priority;
    state_t alternate_state;
    uint32_t channel_alternate;
    state_t useburst_state;
    uint32_t channel_useburst;
    state_t reqmask_state;
    uint32_t channel_reqmask;
} DMA_CONFIGS;

void dma_init (const DMA_CONFIGS * configs);

#endif /* __DMA_DRIVER_H__ */