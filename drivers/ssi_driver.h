#ifndef __SSI_DRIVER_H__
#define __SSI_DRIVER_H__

#include <stdint.h>
#include "sys/macros.h"
#include "sys/system_ctrl.h"
#include "registers/gpio.h"

typedef enum
{
    SSI0,
    SSI1,
    SSI2,
    SSI3
} SSI_MODULE;

typedef enum
{
    FIRST_EDGE = 0,
    SECOND_EDGE = 1
} SSI_CLKPHASE;

typedef enum
{
    MASTER = 0,
    SLAVE = 1
} SSI_CTRL;

typedef enum
{
    STEADY_STATE_LOW = 0,
    STEADY_STATE_HIGH = 1
} SSI_POLARITY;

typedef enum
{
    FREESCALE = 0,
    TI = 1,
    MICROWIRE = 2
} SSI_FRAMEFORMAT;

typedef struct
{
    mode_t loopback;
    SSI_CTRL master_slave;
    CLKSRC clock_source;
    SSI_CLKPHASE clock_phase;
    SSI_POLARITY polarity;
    SSI_FRAMEFORMAT frame_format;
    uint8_t data_size;
    uint32_t bit_rate;
    uint8_t prescale_divisor;
    mode_t transmit_dma;
    mode_t receive_dma;
} SSI_CONFIGS;

void ssi_init (SSI_MODULE module, GPIO_PORTS port, const SSI_CONFIGS * configs);
uint16_t ssi_read (SSI_MODULE module);
void ssi_write (SSI_MODULE module, uint16_t data);

#endif /* __SSI_DRIVER_H__ */
