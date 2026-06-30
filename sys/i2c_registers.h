#ifndef __I2C_REGISTERS_H__
#define __I2C_REGISTERS_H__

#include <stdint.h>

typedef struct
{
    volatile uint8_t R_S : 1;
    volatile uint8_t SA : 7;
    volatile uint32_t _reserved : 24;
} I2CMSA;

typedef union
{
    struct
    {
        volatile uint8_t BUSY : 1;
        volatile uint8_t ERROR : 1;
        volatile uint8_t ADRACK : 1;
        volatile uint8_t DATACK : 1;
        volatile uint8_t ARBLST : 1;
        volatile uint8_t IDLE : 1;
        volatile uint8_t BUSBSY : 1;
        volatile uint8_t CLKTO : 1;
        volatile uint32_t _reserved : 24;
    } RO;

    struct
    {
        volatile uint8_t RUN : 1;
        volatile uint8_t START : 1;
        volatile uint8_t STOP : 1;
        volatile uint8_t ACK : 1;
        volatile uint8_t HS : 1;
        volatile uint32_t _reserved : 27;
    } WO;
} I2CMCS;

typedef struct
{
    volatile uint8_t DATA;
    volatile uint32_t _reserved : 24;
} I2CMDR;

typedef struct
{
    volatile uint8_t TPR : 7;
    volatile uint8_t HS : 1;
    volatile uint32_t _reserved : 24;
} I2CMTPR;

typedef struct
{
    volatile uint8_t IM : 1;
    volatile uint8_t CLKIM : 1;
    volatile uint32_t _reserved : 30;
} I2CMIMR;

typedef struct
{
    volatile uint8_t RIS : 1;
    volatile uint8_t CLKRIS : 1;
    volatile uint32_t _reserved : 30;
} I2CMRIS;

typedef struct
{
    volatile uint8_t MIS : 1;
    volatile uint8_t CLKMIS : 1;
    volatile uint32_t _reserved : 30;
} I2CMMIS;

typedef struct
{
    volatile uint8_t IC : 1;
    volatile uint8_t CLKIC : 1;
    volatile uint32_t _reserved : 30;
} I2CMICR;

typedef struct
{
    volatile uint8_t LPBK : 1;
    volatile uint8_t _reserved_1 : 3;
    volatile uint8_t MFE : 1;
    volatile uint8_t SFE : 1;
    volatile uint8_t GFE : 1;
    volatile uint32_t _reserved_2 : 25;
} I2CMCR;

typedef struct
{
    volatile uint8_t CNTL;
    volatile uint32_t _reserved : 24;
} I2CMCLKOCNT;

typedef struct
{
    volatile uint8_t SCL : 1;
    volatile uint8_t SDA : 1;
    volatile uint32_t _reserved : 30;
} I2CMBMON;

typedef struct
{
    volatile uint8_t _reserved_1 : 4;
    volatile uint8_t GFPW : 3;
    volatile uint32_t _reserved_2 : 25;
} I2CMCR2;

typedef struct
{
    volatile uint8_t OAR : 7;
    volatile uint32_t _reserved : 25;
} I2CSOAR;

typedef union
{
    struct
    {
        volatile uint8_t RREQ : 1;
        volatile uint8_t TREQ : 1;
        volatile uint8_t FBR : 1;
        volatile uint8_t OAR2SEL : 1;
        volatile uint32_t _reserved : 28;
    } RO;

    struct
    {
        volatile uint8_t DA : 1;
        volatile uint32_t _reserved : 31;
    } WO;
} I2CSCSR;

typedef struct
{
    volatile uint8_t DATA;
    volatile uint32_t _reserved : 24;
} I2CSDR;

typedef struct
{
    volatile uint8_t DATAIM : 1;
    volatile uint8_t STARTIM : 1;
    volatile uint8_t STOPIM : 1;
    volatile uint32_t _reserved : 29;
} I2CSIMR;

typedef struct
{
    volatile uint8_t DATARIS : 1;
    volatile uint8_t STARTRIS : 1;
    volatile uint8_t STOPRIS : 1;
    volatile uint32_t _reserved : 29;
} I2CSRIS;

typedef struct
{
    volatile uint8_t DATAMIS : 1;
    volatile uint8_t STARTMIS : 1;
    volatile uint8_t STOPMIS : 1;
    volatile uint32_t _reserved : 29;
} I2CSMIS;

typedef struct
{
    volatile uint8_t DATAIC : 1;
    volatile uint8_t STARTIC : 1;
    volatile uint8_t STOPIC : 1;
    volatile uint32_t _reserved : 29;
} I2CSICR;

typedef struct
{
    volatile uint8_t OAR2 : 7;
    volatile uint8_t OAR2EN : 1;
    volatile uint32_t _reserved : 24;
} I2CSOAR2;

typedef struct
{
    volatile uint8_t ACKOEN : 1;
    volatile uint8_t ACKOVAL : 1;
    volatile uint32_t _reserved : 30;
} I2CSACKCTL;

typedef struct
{
    volatile uint8_t HS : 1;
    volatile uint32_t _reserved : 31;
} I2CPP;

typedef struct
{
    volatile uint8_t HS : 1;
    volatile uint32_t _reserved : 31;
} I2CPC;

typedef struct
{
    I2CMSA master_slave_addr;
    I2CMCS master_control_status;
    I2CMDR master_data;
    I2CMTPR master_timer_period;
    I2CMIMR master_interrupt_mask;
    I2CMRIS master_raw_interrupt_status;
    I2CMMIS master_masked_interrupt_status;
    I2CMICR master_interrupt_clear;
    I2CMCR master_configuration;
    I2CMCLKOCNT master_clock_low_timeout_count;
    I2CMBMON master_bus_monitor;
    volatile uint8_t _reserved_1[2];
    I2CMCR2 master_configuration_2;
    volatile uint8_t _reserved_2[0x7C4];
    I2CSOAR slave_own_addr;
    I2CSCSR slave_control_status;
    I2CSDR slave_data;
    I2CSIMR slave_interrupt_mask;
    I2CSRIS slave_raw_interrupt_status;
    I2CSMIS slave_masked_interrupt_status;
    I2CSICR slave_interrupt_clear;
    I2CSOAR2 slave_own_addr_2;
    I2CSACKCTL slave_ack_control;
    volatile uint8_t _reserved_3[0x79C];
    I2CPP periperal_properties;
    I2CPC peripheral_configuration;
} I2C_t;

#endif /* __I2C_REGISTERS_H__ */