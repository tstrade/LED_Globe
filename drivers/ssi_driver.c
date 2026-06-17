#include <stdint.h>
#include <assert.h>
#include "ssi_driver.h"
#include "tm4c123gh6pm_registers.h"

static ssi_t * const SSI_TABLE[] =
{
    [SSI_MODULE_0] = SYNC_SIMOD0_BASE_ADDR,
    [SSI_MODULE_1] = SYNC_SIMOD1_BASE_ADDR,
    [SSI_MODULE_2] = SYNC_SIMOD2_BASE_ADDR,
    [SSI_MODULE_3] = SYNC_SIMOD3_BASE_ADDR
};

static inline
get_ssi_base (SSI_MODULE module) 
{
    return SSI_TABLE[module];
}

void 
ssi_init (SSI_MODULE module, SSI_CONFIGS * config)
{
    enable_clock (SSI, module);

    ssi_t * ssi_mod = get_ssi_base (module);

    // Disable 
    ssi_mod->CR1 &= 0xFFFFFFFD;

    // Ctrl type
    if (config->master_slave == MASTER)
        ssi_mod->CR1 &= 0xFFFFFFFB;
    else if (config->master_slave == SLAVE)
        ssi_mod->CR1 |= 0x4;

    // Clk source
    if (config->clock_source == SYSTEM)
        *(volatile uint32_t *)(ssi_mod + SSICC) = 0;
    else if (config->clock_source == PIOSC)
        *(volatile uint32_t *)(ssi_mod + SSICC) = 0x5;

    // Clk prescale divisor 
    ssi_mod->CPSR = (uint32_t)config->prescale_divisor;
    // Bit Rate = SysClk / (CPSDVSR * (1 + SRC))
    //  -> SRC = (SysClk / CPSDVSR * Bit Rate) - 1
    uint8_t src = (SYS_CLK_RATE / (config->bit_rate * config->prescale_divisor)) - 1;
    ssi_mod->CR0 |= ((uint32_t)(src) << 8);

    // Clk polarity
    if (config->polarity == STEADY_STATE_LOW)
        ssi_mod->CR0 &= 0xFFFFFFBF;
    else if (config->polarity == STEADY_STATE_HIGH)
        ssi_mod->CR0 |= 0x40;

    // Frame format
    if (config->frame_format == FREESCALE)
    {
        ssi_mod->CR0 &= 0xFFFFFFCF;
        // Clk phase
        if (config->clock_phase == FIRST_EDGE)
            ssi_mod->CR0 &= 0xFFFFFF7F;
        else if (config->clock_phase == SECOND_EDGE)
            ssi_mod->CR0 |= 0x080;
    }
    else if (config->frame_format == TI)
    {
        ssi_mod->CR0 |= 0x10;
    }
    else if (config->frame_format == MICROWIRE)
    {
        ssi_mod->CR0 |= 0x20;
    }

    // Datasize
    if (config->data_size >= 4 && config->data_size <= 16)
        ssi_mod->CR0 |= (config->data_size - 1);
    else
        ssi_mod->CR0 |= 0x0F; // 16-bit if config invalid

    // DMA control
    if (config->transmit_dma == ENABLED)
        ssi_mod->DMACTL |= 0x2;
    else if (config->transmit_dma == DISABLED)
        ssi_mod->DMACTL &= 0xFFFFFFFD;

    if (config->receive_dma == ENABLED)
        ssi_mod->DMACTL |= 0x1;
    else if (config->receive_dma == DISABLED)
        ssi_mod->DMACTL &= 0xFFFFFFFE;

    // Enable
    ssi_mod->CR1 |= 0x2;
}

uint16_t 
ssi_read (SSI_MODULE module)
{
    ssi_t * ssi_mod = get_ssi_base (module);
    bool busy;
    do
    {
        busy = query_ssi_status (module, BSY);
    } 
    while (busy);

    return ssi_mod->DR & 0x00FF;
}

void 
ssi_write (SSI_MODULE module, uint16_t data)
{
    ssi_t * ssi_mod = get_ssi_base (module);
    bool busy;
    do
    {
        busy = query_ssi_status (module, BSY);
    }
    while (busy);

    ssi_mod->DR = data;
}

bool 
query_ssi_status (SSI_MODULE module, SSI_STATUS query)
{
    ssi_t * ssi_mod = get_ssi_base (module);
    if (ssi_mod->SR & (1U << query) != 0)
        return true;

    return false;
}