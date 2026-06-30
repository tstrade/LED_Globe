#ifndef __WATCHDOG_REGISTERS_H__
#define __WATCHDOG_REGISTERS_H__

#include <stdint.h>

#define UNLOCK_WDT_REGISTERS 0x1ACCE551

typedef enum
{
    WDT0,
    WDT1
} WATCHDOG_MODULE;

typedef volatile uint32_t WDTLOAD;

typedef volatile uint32_t WDTVALUE;

typedef struct
{
    volatile uint8_t INTEN : 1;
    volatile uint8_t RESEN : 1;
    volatile uint8_t INTTYPE : 1;
    volatile uint32_t _reserved : 28;
    volatile uint8_t WRC : 1;
} WDTCTL;

typedef struct
{
    volatile uint32_t WDTINTCLR;
} WDTICR;

typedef struct
{
    volatile uint8_t WDTRIS : 1;
    volatile uint32_t _reserved : 31;
} WDTRIS;

typedef struct
{
    volatile uint8_t WDTMIS : 1;
    volatile uint32_t _reserved : 31;
} WDTMIS;

typedef struct
{
    volatile uint8_t _reserved_1;
    volatile uint8_t STALL : 1;
    volatile uint32_t _reserved_2 : 23;
} WDTTEST;

typedef volatile uint32_t WDTLOCK;

typedef struct
{
    WDTLOAD load;
    WDTVALUE value;
    WDTCTL control;
    WDTICR interrupt_clear;
    WDTRIS raw_interrupt_status;
    WDTMIS masked_interrupt_status;
    volatile uint8_t _reserved_1[0x400];
    WDTTEST test;
    volatile uint8_t _reserved_2[0x7E4];
    WDTLOCK lock;
} WATCHDOG_t;

#endif /* __WATCHDOG_REGISTERS_H__ */