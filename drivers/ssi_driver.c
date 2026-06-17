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

#define get_ssi_base(module) ( (ssi_t *)SSI_TABLE[module] )

void 
ssi_init (SSI_MODULE module, SSI_CONFIGS * config)
{
    enable_clock (SSI, module);
    
    ssi_t * ssi_mod = get_ssi_base(module);
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

    // Clk mult
    ssi_mod->CR0 |= ((uint32_t)(config->clock_multiplier) << 8);

    // Clk phase
    if (config->clock_phase == FIRST_EDGE)
        ssi_mod->CR0 &= 0xFFFFFF7F;
    else if (config->clock_phase == SECOND_EDGE)
        ssi_mod->CR0 |= 0x080;

    // Clk polarity
    if (config->polarity == STEADY_STATE_LOW)
        ssi_mod->CR0 &= 0xFFFFFFBF;
    else if (config->polarity == STEADY_STATE_HIGH)
        ssi_mod->CR0 |= 0x40;

    // Frame format
    if (config->frame_format == FREESCALE)
        ssi_mod->CR0 &= 0xFFFFFFCF;
    else if (config->frame_format == TI)
        ssi_mod->CR0 |= 0x10;
    else if (config->frame_format == MICROWIRE)
        ssi_mod->CR0 |= 0x20;

    // Datasize
    if (config->data_size >= 4 && config->data_size <= 16)
        ssi_mod->CR0 |= (config->data_size - 1);
    else
        ssi_mod->CR0 |= 0x0F; // 16-bit if config invalid

    // Enable
    ssi_mod->CR1 |= 0x2;
}