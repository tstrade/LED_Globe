#ifndef __SSI_DRIVER_H__
#define __SSI_DRIVER_H__

//TM4C123GH6PM SSI Peripheral Header File
//TM4C123GH6PM Reference Manual: https://www.ti.com/lit/pdf/spms376

#include "tm4c123gh6pm_registers.h"

typedef enum
{
    SSI_MODULE_0 = 0,
    SSI_MODULE_1 = 1,
    SSI_MODULE_2 = 2,
    SSI_MODULE_3 = 3
} SSI_MODULE __attribute__ ((packed));

typedef enum
{
    SYSTEM = 0,
    PIOSC = 1
} SSI_CLKSRC __attribute__ ((packed));

typedef enum
{
    FIRST_EDGE = 0,
    SECOND_EDGE = 1
} SSI_CLKPHASE __attribute__ ((packed));

typedef enum
{
    MASTER = 0,
    SLAVE = 1
} SSI_CTRL __attribute__ ((packed));

typedef enum
{
    STEADY_STATE_LOW = 0,
    STEADY_STATE_HIGH = 1
} SSI_POLARITY __attribute__ ((packed));

typedef enum
{
    FREESCALE = 0,
    TI = 1,
    MICROWIRE = 2
} SSI_FRAMEFORMAT __attribute__ ((packed));

typedef enum
{
    TFE = 0,
    TNF = 1,
    RNE = 2,
    RFF = 3,
    BSY = 4
} SSI_STATUS __attribute__ ((packed));

typedef struct
{
    mode_t loopback;
    SSI_CTRL master_slave;
    SSI_CLKSRC clock_source;
    uint8_t clock_multiplier;
    SSI_CLKPHASE clock_phase;
    SSI_POLARITY polarity;
    SSI_FRAMEFORMAT frame_format;
    uint8_t data_size;
} SSI_CONFIGS __attribute__ ((packed));

typedef struct
{
    volatile uint32_t CR0;      // 0x000
    volatile uint32_t CR1;      // 0x004
    volatile uint32_t DR;       // 0x008
    volatile uint32_t SR;       // 0x00C
    volatile uint32_t CPSR;     // 0x010
    volatile uint32_t IM;       // 0x014
    volatile uint32_t RIS;      // 0x018
    volatile uint32_t MIS;      // 0x01C
    volatile uint32_t ICR;      // 0x020
    volatile uint32_t DMACTL;   // 0x024
} ssi_t;

void ssi_init (SSI_MODULE module, SSI_CONFIGS * config);
uint16_t ssi_read (SSI_MODULE module);
void ssi_write (SSI_MODULE module, uint16_t data);
bool query_ssi_status (SSI_MODULE module, SSI_STATUS query);


#endif /* __SSI_DRIVER_H__ */