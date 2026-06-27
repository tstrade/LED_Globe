#ifndef __DMA_REGISTERS_H__
#define __DMA_REGISTERS_H__

#include <stdint.h>

typedef enum
{
    CH0 = 0x1, CH1 = 0x2, CH2 = 0x4, CH3 = 0x8U, 
    CH4 = 0x10, CH5 = 0x20, CH6 = 0x40, CH7 = 0x80U,
    CH8 = 0x100, CH9 = 0x200, CH10 = 0x400, CH11 = 0x800U, 
    CH12 = 0x1000, CH13 = 0x2000, CH14 = 0x4000, CH15 = 0x8000U,
    CH16 = 0x10000, CH17 = 0x20000, CH18 = 0x40000, CH19 = 0x80000U, 
    CH20 = 0x100000, CH21 = 0x200000, CH22 = 0x400000, CH23 = 0x800000U,
    CH24 = 0x1000000, CH25 = 0x2000000, CH26 = 0x4000000, CH27 = 0x8000000U, 
    CH28 = 0x10000000, CH29 = 0x20000000, CH30 = 0x400000000, CH31 = 0x80000000U
} DMA_CHANNELS;

typedef struct
{
    volatile uint8_t MASTEN : 1;
    volatile uint8_t _reserved_1 : 3;
    volatile uint8_t STATE : 4;
    volatile uint8_t _reserved_2;
    volatile uint8_t DMAWAITREQ_CHANS : 5;
    volatile uint16_t _reserved_3 : 11;
} DMASTAT;

typedef struct
{
    volatile uint8_t MASTEN : 1;
    volatile uint32_t _reserved : 31;
} DMACFG;

typedef struct
{
    volatile uint16_t _reserved : 10;
    volatile uint32_t ADDR : 22;
} DMACTLBASE;

typedef struct
{
    volatile uint32_t ADDR;
} DMAALTBASE;

typedef union
{
    struct
    {
        uint32_t WAITREQ;
    };
    struct
    {
        volatile uint8_t WAITREQ_CH0 : 1;
        volatile uint8_t WAITREQ_CH1 : 1;
        volatile uint8_t WAITREQ_CH2 : 1;
        volatile uint8_t WAITREQ_CH3 : 1;
        volatile uint8_t WAITREQ_CH4 : 1;
        volatile uint8_t WAITREQ_CH5 : 1;
        volatile uint8_t WAITREQ_CH6 : 1;
        volatile uint8_t WAITREQ_CH7 : 1;
        volatile uint8_t WAITREQ_CH8 : 1;
        volatile uint8_t WAITREQ_CH9 : 1;
        volatile uint8_t WAITREQ_CH10 : 1;
        volatile uint8_t WAITREQ_CH11 : 1;
        volatile uint8_t WAITREQ_CH12 : 1;
        volatile uint8_t WAITREQ_CH13 : 1;
        volatile uint8_t WAITREQ_CH14 : 1;
        volatile uint8_t WAITREQ_CH15 : 1;
        volatile uint8_t WAITREQ_CH16 : 1;
        volatile uint8_t WAITREQ_CH17 : 1;
        volatile uint8_t WAITREQ_CH18 : 1;
        volatile uint8_t WAITREQ_CH19 : 1;
        volatile uint8_t WAITREQ_CH20 : 1;
        volatile uint8_t WAITREQ_CH21 : 1;
        volatile uint8_t WAITREQ_CH22 : 1;
        volatile uint8_t WAITREQ_CH23 : 1;
        volatile uint8_t WAITREQ_CH24 : 1;
        volatile uint8_t WAITREQ_CH25 : 1;
        volatile uint8_t WAITREQ_CH26 : 1;
        volatile uint8_t WAITREQ_CH27 : 1;
        volatile uint8_t WAITREQ_CH28 : 1;
        volatile uint8_t WAITREQ_CH29 : 1;
        volatile uint8_t WAITREQ_CH30 : 1;
        volatile uint8_t WAITREQ_CH31 : 1;
    };
} DMAWAITSTAT;

typedef union
{
    struct
    {
        volatile uint32_t SWREQ;
    };
    struct
    {
        volatile uint8_t SWREQ_CH0 : 1;
        volatile uint8_t SWREQ_CH1 : 1;
        volatile uint8_t SWREQ_CH2 : 1;
        volatile uint8_t SWREQ_CH3 : 1;
        volatile uint8_t SWREQ_CH4 : 1;
        volatile uint8_t SWREQ_CH5 : 1;
        volatile uint8_t SWREQ_CH6 : 1;
        volatile uint8_t SWREQ_CH7 : 1;
        volatile uint8_t SWREQ_CH8 : 1;
        volatile uint8_t SWREQ_CH9 : 1;
        volatile uint8_t SWREQ_CH10 : 1;
        volatile uint8_t SWREQ_CH11 : 1;
        volatile uint8_t SWREQ_CH12 : 1;
        volatile uint8_t SWREQ_CH13 : 1;
        volatile uint8_t SWREQ_CH14 : 1;
        volatile uint8_t SWREQ_CH15 : 1;
        volatile uint8_t SWREQ_CH16 : 1;
        volatile uint8_t SWREQ_CH17 : 1;
        volatile uint8_t SWREQ_CH18 : 1;
        volatile uint8_t SWREQ_CH19 : 1;
        volatile uint8_t SWREQ_CH20 : 1;
        volatile uint8_t SWREQ_CH21 : 1;
        volatile uint8_t SWREQ_CH22 : 1;
        volatile uint8_t SWREQ_CH23 : 1;
        volatile uint8_t SWREQ_CH24 : 1;
        volatile uint8_t SWREQ_CH25 : 1;
        volatile uint8_t SWREQ_CH26 : 1;
        volatile uint8_t SWREQ_CH27 : 1;
        volatile uint8_t SWREQ_CH28 : 1;
        volatile uint8_t SWREQ_CH29 : 1;
        volatile uint8_t SWREQ_CH30 : 1;
        volatile uint8_t SWREQ_CH31 : 1;
    };
} DMASWREQ;

typedef union
{
    struct
    {
        volatile uint32_t SET;
    };
    struct
    {
        volatile uint8_t SET_CH0 : 1;
        volatile uint8_t SET_CH1 : 1;
        volatile uint8_t SET_CH2 : 1;
        volatile uint8_t SET_CH3 : 1;
        volatile uint8_t SET_CH4 : 1;
        volatile uint8_t SET_CH5 : 1;
        volatile uint8_t SET_CH6 : 1;
        volatile uint8_t SET_CH7 : 1;
        volatile uint8_t SET_CH8 : 1;
        volatile uint8_t SET_CH9 : 1;
        volatile uint8_t SET_CH10 : 1;
        volatile uint8_t SET_CH11 : 1;
        volatile uint8_t SET_CH12 : 1;
        volatile uint8_t SET_CH13 : 1;
        volatile uint8_t SET_CH14 : 1;
        volatile uint8_t SET_CH15 : 1;
        volatile uint8_t SET_CH16 : 1;
        volatile uint8_t SET_CH17 : 1;
        volatile uint8_t SET_CH18 : 1;
        volatile uint8_t SET_CH19 : 1;
        volatile uint8_t SET_CH20 : 1;
        volatile uint8_t SET_CH21 : 1;
        volatile uint8_t SET_CH22 : 1;
        volatile uint8_t SET_CH23 : 1;
        volatile uint8_t SET_CH24 : 1;
        volatile uint8_t SET_CH25 : 1;
        volatile uint8_t SET_CH26 : 1;
        volatile uint8_t SET_CH27 : 1;
        volatile uint8_t SET_CH28 : 1;
        volatile uint8_t SET_CH29 : 1;
        volatile uint8_t SET_CH30 : 1;
        volatile uint8_t SET_CH31 : 1;
    };
} DMAUSEBURSTSET;

typedef union
{
    struct
    {
        volatile uint32_t CLR;
    };
    struct
    {
        volatile uint8_t CLR_CH0 : 1;
        volatile uint8_t CLR_CH1 : 1;
        volatile uint8_t CLR_CH2 : 1;
        volatile uint8_t CLR_CH3 : 1;
        volatile uint8_t CLR_CH4 : 1;
        volatile uint8_t CLR_CH5 : 1;
        volatile uint8_t CLR_CH6 : 1;
        volatile uint8_t CLR_CH7 : 1;
        volatile uint8_t CLR_CH8 : 1;
        volatile uint8_t CLR_CH9 : 1;
        volatile uint8_t CLR_CH10 : 1;
        volatile uint8_t CLR_CH11 : 1;
        volatile uint8_t CLR_CH12 : 1;
        volatile uint8_t CLR_CH13 : 1;
        volatile uint8_t CLR_CH14 : 1;
        volatile uint8_t CLR_CH15 : 1;
        volatile uint8_t CLR_CH16 : 1;
        volatile uint8_t CLR_CH17 : 1;
        volatile uint8_t CLR_CH18 : 1;
        volatile uint8_t CLR_CH19 : 1;
        volatile uint8_t CLR_CH20 : 1;
        volatile uint8_t CLR_CH21 : 1;
        volatile uint8_t CLR_CH22 : 1;
        volatile uint8_t CLR_CH23 : 1;
        volatile uint8_t CLR_CH24 : 1;
        volatile uint8_t CLR_CH25 : 1;
        volatile uint8_t CLR_CH26 : 1;
        volatile uint8_t CLR_CH27 : 1;
        volatile uint8_t CLR_CH28 : 1;
        volatile uint8_t CLR_CH29 : 1;
        volatile uint8_t CLR_CH30 : 1;
        volatile uint8_t CLR_CH31 : 1;
    };
} DMAUSEBURSTCLR;

typedef union
{
    struct
    {
        volatile uint32_t SET;
    }
    struct {
        volatile uint8_t SET_CH0 : 1;
        volatile uint8_t SET_CH1 : 1;
        volatile uint8_t SET_CH2 : 1;
        volatile uint8_t SET_CH3 : 1;
        volatile uint8_t SET_CH4 : 1;
        volatile uint8_t SET_CH5 : 1;
        volatile uint8_t SET_CH6 : 1;
        volatile uint8_t SET_CH7 : 1;
        volatile uint8_t SET_CH8 : 1;
        volatile uint8_t SET_CH9 : 1;
        volatile uint8_t SET_CH10 : 1;
        volatile uint8_t SET_CH11 : 1;
        volatile uint8_t SET_CH12 : 1;
        volatile uint8_t SET_CH13 : 1;
        volatile uint8_t SET_CH14 : 1;
        volatile uint8_t SET_CH15 : 1;
        volatile uint8_t SET_CH16 : 1;
        volatile uint8_t SET_CH17 : 1;
        volatile uint8_t SET_CH18 : 1;
        volatile uint8_t SET_CH19 : 1;
        volatile uint8_t SET_CH20 : 1;
        volatile uint8_t SET_CH21 : 1;
        volatile uint8_t SET_CH22 : 1;
        volatile uint8_t SET_CH23 : 1;
        volatile uint8_t SET_CH24 : 1;
        volatile uint8_t SET_CH25 : 1;
        volatile uint8_t SET_CH26 : 1;
        volatile uint8_t SET_CH27 : 1;
        volatile uint8_t SET_CH28 : 1;
        volatile uint8_t SET_CH29 : 1;
        volatile uint8_t SET_CH30 : 1;
        volatile uint8_t SET_CH31 : 1;
    };
} DMAREQMASKSET;

typedef union
{
    struct
    {
        volatile uint32_t CLR;
    };
    struct 
    {
        volatile uint8_t CLR_CH0 : 1;
        volatile uint8_t CLR_CH1 : 1;
        volatile uint8_t CLR_CH2 : 1;
        volatile uint8_t CLR_CH3 : 1;
        volatile uint8_t CLR_CH4 : 1;
        volatile uint8_t CLR_CH5 : 1;
        volatile uint8_t CLR_CH6 : 1;
        volatile uint8_t CLR_CH7 : 1;
        volatile uint8_t CLR_CH8 : 1;
        volatile uint8_t CLR_CH9 : 1;
        volatile uint8_t CLR_CH10 : 1;
        volatile uint8_t CLR_CH11 : 1;
        volatile uint8_t CLR_CH12 : 1;
        volatile uint8_t CLR_CH13 : 1;
        volatile uint8_t CLR_CH14 : 1;
        volatile uint8_t CLR_CH15 : 1;
        volatile uint8_t CLR_CH16 : 1;
        volatile uint8_t CLR_CH17 : 1;
        volatile uint8_t CLR_CH18 : 1;
        volatile uint8_t CLR_CH19 : 1;
        volatile uint8_t CLR_CH20 : 1;
        volatile uint8_t CLR_CH21 : 1;
        volatile uint8_t CLR_CH22 : 1;
        volatile uint8_t CLR_CH23 : 1;
        volatile uint8_t CLR_CH24 : 1;
        volatile uint8_t CLR_CH25 : 1;
        volatile uint8_t CLR_CH26 : 1;
        volatile uint8_t CLR_CH27 : 1;
        volatile uint8_t CLR_CH28 : 1;
        volatile uint8_t CLR_CH29 : 1;
        volatile uint8_t CLR_CH30 : 1;
        volatile uint8_t CLR_CH31 : 1;
    };
} DMAREQMASKCLR;

typedef union
{
    struct
    {
        volatile uint32_t SET;
    };
    struct
    {
        volatile uint8_t SET_CH0 : 1;
        volatile uint8_t SET_CH1 : 1;
        volatile uint8_t SET_CH2 : 1;
        volatile uint8_t SET_CH3 : 1;
        volatile uint8_t SET_CH4 : 1;
        volatile uint8_t SET_CH5 : 1;
        volatile uint8_t SET_CH6 : 1;
        volatile uint8_t SET_CH7 : 1;
        volatile uint8_t SET_CH8 : 1;
        volatile uint8_t SET_CH9 : 1;
        volatile uint8_t SET_CH10 : 1;
        volatile uint8_t SET_CH11 : 1;
        volatile uint8_t SET_CH12 : 1;
        volatile uint8_t SET_CH13 : 1;
        volatile uint8_t SET_CH14 : 1;
        volatile uint8_t SET_CH15 : 1;
        volatile uint8_t SET_CH16 : 1;
        volatile uint8_t SET_CH17 : 1;
        volatile uint8_t SET_CH18 : 1;
        volatile uint8_t SET_CH19 : 1;
        volatile uint8_t SET_CH20 : 1;
        volatile uint8_t SET_CH21 : 1;
        volatile uint8_t SET_CH22 : 1;
        volatile uint8_t SET_CH23 : 1;
        volatile uint8_t SET_CH24 : 1;
        volatile uint8_t SET_CH25 : 1;
        volatile uint8_t SET_CH26 : 1;
        volatile uint8_t SET_CH27 : 1;
        volatile uint8_t SET_CH28 : 1;
        volatile uint8_t SET_CH29 : 1;
        volatile uint8_t SET_CH30 : 1;
        volatile uint8_t SET_CH31 : 1;
    };
} DMAENASET;

typedef union
{
    struct
    {
        volatile uint32_t CLR;
    };
    struct
    {
        volatile uint8_t CLR_CH0 : 1;
        volatile uint8_t CLR_CH1 : 1;
        volatile uint8_t CLR_CH2 : 1;
        volatile uint8_t CLR_CH3 : 1;
        volatile uint8_t CLR_CH4 : 1;
        volatile uint8_t CLR_CH5 : 1;
        volatile uint8_t CLR_CH6 : 1;
        volatile uint8_t CLR_CH7 : 1;
        volatile uint8_t CLR_CH8 : 1;
        volatile uint8_t CLR_CH9 : 1;
        volatile uint8_t CLR_CH10 : 1;
        volatile uint8_t CLR_CH11 : 1;
        volatile uint8_t CLR_CH12 : 1;
        volatile uint8_t CLR_CH13 : 1;
        volatile uint8_t CLR_CH14 : 1;
        volatile uint8_t CLR_CH15 : 1;
        volatile uint8_t CLR_CH16 : 1;
        volatile uint8_t CLR_CH17 : 1;
        volatile uint8_t CLR_CH18 : 1;
        volatile uint8_t CLR_CH19 : 1;
        volatile uint8_t CLR_CH20 : 1;
        volatile uint8_t CLR_CH21 : 1;
        volatile uint8_t CLR_CH22 : 1;
        volatile uint8_t CLR_CH23 : 1;
        volatile uint8_t CLR_CH24 : 1;
        volatile uint8_t CLR_CH25 : 1;
        volatile uint8_t CLR_CH26 : 1;
        volatile uint8_t CLR_CH27 : 1;
        volatile uint8_t CLR_CH28 : 1;
        volatile uint8_t CLR_CH29 : 1;
        volatile uint8_t CLR_CH30 : 1;
        volatile uint8_t CLR_CH31 : 1;
    };
} DMAENACLR;

typedef union
{
    struct 
    {
        volatile uint32_t SET;
    };
    struct
    {
        volatile uint8_t SET_CH0 : 1;
        volatile uint8_t SET_CH1 : 1;
        volatile uint8_t SET_CH2 : 1;
        volatile uint8_t SET_CH3 : 1;
        volatile uint8_t SET_CH4 : 1;
        volatile uint8_t SET_CH5 : 1;
        volatile uint8_t SET_CH6 : 1;
        volatile uint8_t SET_CH7 : 1;
        volatile uint8_t SET_CH8 : 1;
        volatile uint8_t SET_CH9 : 1;
        volatile uint8_t SET_CH10 : 1;
        volatile uint8_t SET_CH11 : 1;
        volatile uint8_t SET_CH12 : 1;
        volatile uint8_t SET_CH13 : 1;
        volatile uint8_t SET_CH14 : 1;
        volatile uint8_t SET_CH15 : 1;
        volatile uint8_t SET_CH16 : 1;
        volatile uint8_t SET_CH17 : 1;
        volatile uint8_t SET_CH18 : 1;
        volatile uint8_t SET_CH19 : 1;
        volatile uint8_t SET_CH20 : 1;
        volatile uint8_t SET_CH21 : 1;
        volatile uint8_t SET_CH22 : 1;
        volatile uint8_t SET_CH23 : 1;
        volatile uint8_t SET_CH24 : 1;
        volatile uint8_t SET_CH25 : 1;
        volatile uint8_t SET_CH26 : 1;
        volatile uint8_t SET_CH27 : 1;
        volatile uint8_t SET_CH28 : 1;
        volatile uint8_t SET_CH29 : 1;
        volatile uint8_t SET_CH30 : 1;
        volatile uint8_t SET_CH31 : 1;
    };
} DMAALTSET;

typedef union
{
    struct
    {
        volatile uint32_t CLR;
    };
    struct
    {
        volatile uint8_t CLR_CH0 : 1;
        volatile uint8_t CLR_CH1 : 1;
        volatile uint8_t CLR_CH2 : 1;
        volatile uint8_t CLR_CH3 : 1;
        volatile uint8_t CLR_CH4 : 1;
        volatile uint8_t CLR_CH5 : 1;
        volatile uint8_t CLR_CH6 : 1;
        volatile uint8_t CLR_CH7 : 1;
        volatile uint8_t CLR_CH8 : 1;
        volatile uint8_t CLR_CH9 : 1;
        volatile uint8_t CLR_CH10 : 1;
        volatile uint8_t CLR_CH11 : 1;
        volatile uint8_t CLR_CH12 : 1;
        volatile uint8_t CLR_CH13 : 1;
        volatile uint8_t CLR_CH14 : 1;
        volatile uint8_t CLR_CH15 : 1;
        volatile uint8_t CLR_CH16 : 1;
        volatile uint8_t CLR_CH17 : 1;
        volatile uint8_t CLR_CH18 : 1;
        volatile uint8_t CLR_CH19 : 1;
        volatile uint8_t CLR_CH20 : 1;
        volatile uint8_t CLR_CH21 : 1;
        volatile uint8_t CLR_CH22 : 1;
        volatile uint8_t CLR_CH23 : 1;
        volatile uint8_t CLR_CH24 : 1;
        volatile uint8_t CLR_CH25 : 1;
        volatile uint8_t CLR_CH26 : 1;
        volatile uint8_t CLR_CH27 : 1;
        volatile uint8_t CLR_CH28 : 1;
        volatile uint8_t CLR_CH29 : 1;
        volatile uint8_t CLR_CH30 : 1;
        volatile uint8_t CLR_CH31 : 1;
    };
} DMAALTCLR;

typedef union
{
    struct
    {
        volatile uint32_t SET;
    };
    struct
    {
        volatile uint8_t SET_CH0 : 1;
        volatile uint8_t SET_CH1 : 1;
        volatile uint8_t SET_CH2 : 1;
        volatile uint8_t SET_CH3 : 1;
        volatile uint8_t SET_CH4 : 1;
        volatile uint8_t SET_CH5 : 1;
        volatile uint8_t SET_CH6 : 1;
        volatile uint8_t SET_CH7 : 1;
        volatile uint8_t SET_CH8 : 1;
        volatile uint8_t SET_CH9 : 1;
        volatile uint8_t SET_CH10 : 1;
        volatile uint8_t SET_CH11 : 1;
        volatile uint8_t SET_CH12 : 1;
        volatile uint8_t SET_CH13 : 1;
        volatile uint8_t SET_CH14 : 1;
        volatile uint8_t SET_CH15 : 1;
        volatile uint8_t SET_CH16 : 1;
        volatile uint8_t SET_CH17 : 1;
        volatile uint8_t SET_CH18 : 1;
        volatile uint8_t SET_CH19 : 1;
        volatile uint8_t SET_CH20 : 1;
        volatile uint8_t SET_CH21 : 1;
        volatile uint8_t SET_CH22 : 1;
        volatile uint8_t SET_CH23 : 1;
        volatile uint8_t SET_CH24 : 1;
        volatile uint8_t SET_CH25 : 1;
        volatile uint8_t SET_CH26 : 1;
        volatile uint8_t SET_CH27 : 1;
        volatile uint8_t SET_CH28 : 1;
        volatile uint8_t SET_CH29 : 1;
        volatile uint8_t SET_CH30 : 1;
        volatile uint8_t SET_CH31 : 1;
    };
} DMAPRIOSET;

typedef union
{
    struct
    {
        volatile uint32_t CLR;
    };
    struct
    {
        volatile uint8_t CLR_CH0 : 1;
        volatile uint8_t CLR_CH1 : 1;
        volatile uint8_t CLR_CH2 : 1;
        volatile uint8_t CLR_CH3 : 1;
        volatile uint8_t CLR_CH4 : 1;
        volatile uint8_t CLR_CH5 : 1;
        volatile uint8_t CLR_CH6 : 1;
        volatile uint8_t CLR_CH7 : 1;
        volatile uint8_t CLR_CH8 : 1;
        volatile uint8_t CLR_CH9 : 1;
        volatile uint8_t CLR_CH10 : 1;
        volatile uint8_t CLR_CH11 : 1;
        volatile uint8_t CLR_CH12 : 1;
        volatile uint8_t CLR_CH13 : 1;
        volatile uint8_t CLR_CH14 : 1;
        volatile uint8_t CLR_CH15 : 1;
        volatile uint8_t CLR_CH16 : 1;
        volatile uint8_t CLR_CH17 : 1;
        volatile uint8_t CLR_CH18 : 1;
        volatile uint8_t CLR_CH19 : 1;
        volatile uint8_t CLR_CH20 : 1;
        volatile uint8_t CLR_CH21 : 1;
        volatile uint8_t CLR_CH22 : 1;
        volatile uint8_t CLR_CH23 : 1;
        volatile uint8_t CLR_CH24 : 1;
        volatile uint8_t CLR_CH25 : 1;
        volatile uint8_t CLR_CH26 : 1;
        volatile uint8_t CLR_CH27 : 1;
        volatile uint8_t CLR_CH28 : 1;
        volatile uint8_t CLR_CH29 : 1;
        volatile uint8_t CLR_CH30 : 1;
        volatile uint8_t CLR_CH31 : 1;
    };
} DMAPRIOCLR;

typedef struct
{
    volatile uint8_t ERRCLR : 1;
    volatile uint32_t _reserved : 31;
} DMAERRCLR;

typedef union
{
    struct
    {
        volatile uint32_t CHASGN;
    };
    struct
    {
        volatile uint8_t CHASGN_CH0 : 1;
        volatile uint8_t CHASGN_CH1 : 1;
        volatile uint8_t CHASGN_CH2 : 1;
        volatile uint8_t CHASGN_CH3 : 1;
        volatile uint8_t CHASGN_CH4 : 1;
        volatile uint8_t CHASGN_CH5 : 1;
        volatile uint8_t CHASGN_CH6 : 1;
        volatile uint8_t CHASGN_CH7 : 1;
        volatile uint8_t CHASGN_CH8 : 1;
        volatile uint8_t CHASGN_CH9 : 1;
        volatile uint8_t CHASGN_CH10 : 1;
        volatile uint8_t CHASGN_CH11 : 1;
        volatile uint8_t CHASGN_CH12 : 1;
        volatile uint8_t CHASGN_CH13 : 1;
        volatile uint8_t CHASGN_CH14 : 1;
        volatile uint8_t CHASGN_CH15 : 1;
        volatile uint8_t CHASGN_CH16 : 1;
        volatile uint8_t CHASGN_CH17 : 1;
        volatile uint8_t CHASGN_CH18 : 1;
        volatile uint8_t CHASGN_CH19 : 1;
        volatile uint8_t CHASGN_CH20 : 1;
        volatile uint8_t CHASGN_CH21 : 1;
        volatile uint8_t CHASGN_CH22 : 1;
        volatile uint8_t CHASGN_CH23 : 1;
        volatile uint8_t CHASGN_CH24 : 1;
        volatile uint8_t CHASGN_CH25 : 1;
        volatile uint8_t CHASGN_CH26 : 1;
        volatile uint8_t CHASGN_CH27 : 1;
        volatile uint8_t CHASGN_CH28 : 1;
        volatile uint8_t CHASGN_CH29 : 1;
        volatile uint8_t CHASGN_CH30 : 1;
        volatile uint8_t CHASGN_CH31 : 1;
    };
} DMACHASGN;

typedef union
{
    struct
    {
        volatile uint32_t CHIS;
    };
    struct
    {
        volatile uint8_t CHIS_CH0 : 1;
        volatile uint8_t CHIS_CH1 : 1;
        volatile uint8_t CHIS_CH2 : 1;
        volatile uint8_t CHIS_CH3 : 1;
        volatile uint8_t CHIS_CH4 : 1;
        volatile uint8_t CHIS_CH5 : 1;
        volatile uint8_t CHIS_CH6 : 1;
        volatile uint8_t CHIS_CH7 : 1;
        volatile uint8_t CHIS_CH8 : 1;
        volatile uint8_t CHIS_CH9 : 1;
        volatile uint8_t CHIS_CH10 : 1;
        volatile uint8_t CHIS_CH11 : 1;
        volatile uint8_t CHIS_CH12 : 1;
        volatile uint8_t CHIS_CH13 : 1;
        volatile uint8_t CHIS_CH14 : 1;
        volatile uint8_t CHIS_CH15 : 1;
        volatile uint8_t CHIS_CH16 : 1;
        volatile uint8_t CHIS_CH17 : 1;
        volatile uint8_t CHIS_CH18 : 1;
        volatile uint8_t CHIS_CH19 : 1;
        volatile uint8_t CHIS_CH20 : 1;
        volatile uint8_t CHIS_CH21 : 1;
        volatile uint8_t CHIS_CH22 : 1;
        volatile uint8_t CHIS_CH23 : 1;
        volatile uint8_t CHIS_CH24 : 1;
        volatile uint8_t CHIS_CH25 : 1;
        volatile uint8_t CHIS_CH26 : 1;
        volatile uint8_t CHIS_CH27 : 1;
        volatile uint8_t CHIS_CH28 : 1;
        volatile uint8_t CHIS_CH29 : 1;
        volatile uint8_t CHIS_CH30 : 1;
        volatile uint8_t CHIS_CH31 : 1;
    };
} DMACHIS;

typedef struct
{
    volatile uint32_t CH0SEL : 4;
    volatile uint32_t CH1SEL : 4;
    volatile uint32_t CH2SEL : 4;
    volatile uint32_t CH3SEL : 4;
    volatile uint32_t CH4SEL : 4;
    volatile uint32_t CH5SEL : 4;
    volatile uint32_t CH6SEL : 4;
    volatile uint32_t CH7SEL : 4;
} DMACHMAP0;

typedef struct
{
    volatile uint32_t CH8SEL : 4;
    volatile uint32_t CH9SEL : 4;
    volatile uint32_t CH10SEL : 4;
    volatile uint32_t CH11SEL : 4;
    volatile uint32_t CH12SEL : 4;
    volatile uint32_t CH13SEL : 4;
    volatile uint32_t CH14SEL : 4;
    volatile uint32_t CH15SEL : 4;
} DMACHMAP1;

typedef struct
{
    volatile uint32_t CH16SEL : 4;
    volatile uint32_t CH17SEL : 4;
    volatile uint32_t CH18SEL : 4;
    volatile uint32_t CH19SEL : 4;
    volatile uint32_t CH20SEL : 4;
    volatile uint32_t CH21SEL : 4;
    volatile uint32_t CH22SEL : 4;
    volatile uint32_t CH23SEL : 4;
} DMACHMAP2;

typedef struct
{
    volatile uint32_t CH24SEL : 4;
    volatile uint32_t CH25SEL : 4;
    volatile uint32_t CH26SEL : 4;
    volatile uint32_t CH27SEL : 4;
    volatile uint32_t CH28SEL : 4;
    volatile uint32_t CH29SEL : 4;
    volatile uint32_t CH30SEL : 4;
    volatile uint32_t CH31SEL : 4;
} DMACHMAP3;

typedef struct
{
    DMASTAT status;
    DMACFG configuration;
    DMACTLBASE channel_control_base_ptr;
    DMAALTBASE alt_channel_control_base_ptr;
    DMAWAITSTAT channel_wait_on_req_status;
    DMASWREQ channel_software_req;
    DMAUSEBURSTSET channel_useburst_set;
    DMAUSEBURSTCLR channel_useburst_clear;
    DMAREQMASKSET channel_req_mask_set;
    DMAREQMASKCLR channel_req_mask_clear;
    DMAENASET channel_enable_set;
    DMAENACLR channel_enable_clear;
    DMAALTSET channel_primary_alt_set;
    DMAALTCLR channel_primary_alt_clear;
    DMAPRIOSET channel_priority_set;
    DMAPRIOCLR channel_priority_clear;
    DMAERRCLR bus_error_clear;
    DMACHASGN channel_assignment;
    DMACHIS channel_interrupt_status;
    DMACHMAP0 channel_map_select_0;
    DMACHMAP1 channel_map_select_1;
    DMACHMAP2 channel_map_select_2;
    DMACHMAP3 channel_map_select_3;
} DMA_t;

#endif /* __DMA_REGISTERS_H__ */