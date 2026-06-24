#ifndef __SSI_REGISTERS_H__
#define __SSI_REGISTERS_H__

#include <stdint.h>

typedef struct
{
    volatile uint8_t DSS : 4;
    volatile uint8_t FRF : 2;
    volatile uint8_t SPO : 1;
    volatile uint8_t SPH : 1;
    volatile uint8_t SRC : 8;
    volatile uint16_t _reserved : 16;
} SSICR0;

typedef struct
{
    volatile uint8_t LBM : 1;
    volatile uint8_t SSE : 1;
    volatile uint8_t MS : 1;
    volatile uint8_t _reserved_1 : 1;
    volatile uint8_t EOT : 1;
    volatile uint32_t _reserved_2 : 27;
} SSICR1;

typedef struct
{
    volatile uint16_t DATA : 16;
    volatile uint16_t _reserved : 16;
} SSIDR;

typedef struct
{
    volatile uint8_t TFE : 1;
    volatile uint8_t TNF : 1;
    volatile uint8_t RNE : 1;
    volatile uint8_t RFF : 1;
    volatile uint8_t BSY : 1;
    volatile uint32_t _reserved : 27;
} SSISR;

typedef struct
{
    volatile uint8_t CPSDVSR : 8;
    volatile uint32_t _reserved : 24;
} SSICPSR;

typedef struct
{
    volatile uint8_t RORIM : 1;
    volatile uint8_t RTIM : 1;
    volatile uint8_t RXIM : 1;
    volatile uint8_t TXIM : 1;
    volatile uint32_t _reserved : 28;
} SSIIM;

typedef struct
{
    volatile uint8_t RORRIS : 1;
    volatile uint8_t RTRIS : 1;
    volatile uint8_t RXRIS : 1;
    volatile uint8_t TXRIS : 1;
    volatile uint32_t _reserved : 28;
} SSIRIS;

typedef struct
{
    volatile uint8_t RORMIS : 1;
    volatile uint8_t RTMIS : 1;
    volatile uint8_t RXMIS : 1;
    volatile uint32_t TXMIS : 28;
} SSIMIS;

typedef struct
{
    volatile uint8_t RORIC : 1;
    volatile uint8_t RTIC : 1;
    volatile uint32_t _reserved : 30;
} SSIICR;

typedef struct
{
    volatile uint8_t RXDMAE : 1;
    volatile uint8_t TXDMAE : 1;
    volatile uint32_t _reserved : 30;
} SSIDMACTL;

typedef struct
{
    volatile uint8_t CS : 4;
    volatile uint32_t _reserved : 28;
} SSICC;

typedef struct
{
    SSICR0 ctrl_0;
    SSICR1 ctrl_1;
    SSIDR data;
    SSISR status;
    SSICPSR clock_prescale;
    SSIIM interrupt_mask;
    SSIRIS raw_interrupt_status;
    SSIMIS masked_interrupt_status;
    SSIICR interrupt_clear;
    SSIDMACTL dma_ctrl;
    uint8_t _reserved[4000];
    SSICC clock_config;
} SSI_t;

#endif
