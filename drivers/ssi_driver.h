#ifndef __SSI_DRIVER_H__
#define __SSI_DRIVER_H__

#include <stdint.h>
#include "gpio_registers.h"

typedef enum
{
    SSI0,
    SSI1,
    SSI2,
    SSI3
} SSI_MODULE;

typedef enum
{
    DISABLE_LOOPBACK,
    ENABLE_LOOPBACK
} SSI_LOOPBACK;

typedef enum
{
    SYSTEM = 0,
    PIOSC = 5
} SSI_CLKSRC;

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

typedef enum
{
    DISABLE_TXDMA,
    ENABLE_TXDMA
} SSI_TXDMA;

typedef enum
{
    DISABLE_RXDMA,
    ENABLE_RXDMA
} SSI_RXDMA;

typedef struct
{
    SSI_LOOPBACK loopback;
    SSI_CTRL master_slave;
    SSI_CLKSRC clock_source;
    SSI_CLKPHASE clock_phase;
    SSI_POLARITY polarity;
    SSI_FRAMEFORMAT frame_format;
    uint8_t data_size;
    uint32_t bit_rate;
    uint8_t prescale_divisor;
    SSI_TXDMA transmit_dma;
    SSI_RXDMA receive_dma;
} SSI_CONFIGS;

void ssi_init (SSI_MODULE module, GPIO_PORTS port, const SSI_CONFIGS * configs);
uint16_t ssi_read (SSI_MODULE module);
void ssi_write (SSI_MODULE module, uint16_t data);

#endif /* __SSI_DRIVER_H__ */
