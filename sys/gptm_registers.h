#ifndef __GPTM_REGISTERS_H__
#define __GPTM_REGISTERS_H__

#include <stdint.h>

typedef enum
{
    TIMER0,
    TIMER1,
    TIMER2,
    TIMER3,
    TIMER4,
    TIMER5,
    WIDE_TIMER0,
    WIDE_TIMER1,
    WIDE_TIMER2,
    WIDE_TIMER3,
    WIDE_TIMER4,
    WIDE_TIMER5
} GPTM_MODULES;

typedef struct
{
    volatile uint8_t GPTMCFG : 3;
    volatile uint32_t _reserved : 29;
} GPTMCFG;

typedef struct
{
    volatile uint8_t TAMR : 2;
    volatile uint8_t TACMR : 1;
    volatile uint8_t TAMMS : 1;
    volatile uint8_t TACDIR : 1;
    volatile uint8_t TAMIE : 1;
    volatile uint8_t TAWOT : 1;
    volatile uint8_t TASNAPS : 1;
    volatile uint8_t TAILD : 1;
    volatile uint8_t TAPWMIE : 1;
    volatile uint8_t TAMRSU : 1;
    volatile uint8_t TAPLO : 1;
    volatile uint32_t _reserved : 20;
} GPTMTAMR;

typedef struct
{
    volatile uint8_t TBMR : 2;
    volatile uint8_t TBCMR : 1;
    volatile uint8_t TBMMS : 1;
    volatile uint8_t TBCDIR : 1;
    volatile uint8_t TBMIE : 1;
    volatile uint8_t TBWOT : 1;
    volatile uint8_t TBSNAPS : 1;
    volatile uint8_t TBILD : 1;
    volatile uint8_t TBPWMIE : 1;
    volatile uint8_t TBMRSU : 1;
    volatile uint8_t TBPLO : 1;
    volatile uint32_t _reserved : 20;
} GPTMTBMR;

typedef struct
{
    volatile uint8_t TAEN : 1;
    volatile uint8_t TASTALL : 1;
    volatile uint8_t TAEVENT : 2;
    volatile uint8_t RTCEN : 1;
    volatile uint8_t TAOTE : 1;
    volatile uint8_t TAPWML : 1;
    volatile uint8_t _reserved_1 : 1;
    volatile uint8_t TBEN : 1;
    volatile uint8_t TBSTALL : 1;
    volatile uint8_t TBEVENT : 2;
    volatile uint8_t _reserved_2 : 1;
    volatile uint8_t TBOTE : 1;
    volatile uint8_t TBPWML : 1;
    volatile uint32_t _reserved_3 : 17;
} GPTMCTL;

typedef struct
{
    volatile uint8_t SYNCT0 : 2;
    volatile uint8_t SYNCT1 : 2;
    volatile uint8_t SYNCT2 : 2;
    volatile uint8_t SYNCT3 : 2;
    volatile uint8_t SYNCT4 : 2;
    volatile uint8_t SYNCT5 : 2;
    volatile uint8_t SYNCWT0 : 2;
    volatile uint8_t SYNCWT1 : 2;
    volatile uint8_t SYNCWT2 : 2;
    volatile uint8_t SYNCWT3 : 2;
    volatile uint8_t SYNCWT4 : 2;
    volatile uint8_t SYNCWT5 : 2;
    volatile uint8_t _reserved;
} GPTMSYNC;

typedef struct
{
    volatile uint8_t TATOIM : 1;
    volatile uint8_t CAMIM : 1;
    volatile uint8_t CAEIM : 1;
    volatile uint8_t RTCIM : 1;
    volatile uint8_t TAMIM : 1;
    volatile uint8_t _reserved_1 : 3;
    volatile uint8_t TBTOIM : 1;
    volatile uint8_t CBMIM : 1;
    volatile uint8_t CBEIM : 1;
    volatile uint8_t TBMIM : 1;
    volatile uint8_t _reserved_2 : 4;
    volatile uint8_t WUEIM : 1;
    volatile uint16_t _reserved_3 : 15;
} GPTMIMR;

typedef struct
{
    volatile uint8_t TATORIS : 1;
    volatile uint8_t CAMRIS : 1;
    volatile uint8_t CAERIS : 1;
    volatile uint8_t RTCRIS : 1;
    volatile uint8_t TAMRIS : 1;
    volatile uint8_t _reserved_1 : 3;
    volatile uint8_t TBTORIS : 1;
    volatile uint8_t CBMRIS : 1;
    volatile uint8_t CBERIS : 1;
    volatile uint8_t TBMRIS : 1;
    volatile uint8_t _reserved_2 : 4;
    volatile uint8_t WUERIS : 1;
    volatile uint16_t _reserved_3 : 15;
} GPTMRIS;

typedef struct
{
    volatile uint8_t TATOMIS : 1;
    volatile uint8_t CAMMIS : 1;
    volatile uint8_t CAEMIS : 1;
    volatile uint8_t RTCMIS : 1;
    volatile uint8_t TAMMIS : 1;
    volatile uint8_t _reserved_1 : 3;
    volatile uint8_t TBTOMIS : 1;
    volatile uint8_t CBMMIS : 1;
    volatile uint8_t CBEMIS : 1;
    volatile uint8_t TBMMIS : 1;
    volatile uint8_t _reserved_2 : 4;
    volatile uint8_t WUEMIS : 1;
    volatile uint16_t _reserved_3 : 15;
} GPTMMIS;

typedef struct
{
    volatile uint8_t TATOINT : 1;
    volatile uint8_t CAMINT : 1;
    volatile uint8_t CAEINT : 1;
    volatile uint8_t RTCINT : 1;
    volatile uint8_t TAMINT : 1;
    volatile uint8_t _reserved_1 : 3;
    volatile uint8_t TBTOINT : 1;
    volatile uint8_t CBMINT : 1;
    volatile uint8_t CBEINT : 1;
    volatile uint8_t TBMINT : 1;
    volatile uint8_t _reserved_2 : 4;
    volatile uint8_t WUEINT : 1;
    volatile uint16_t _reserved_3 : 15;
} GPTMICR;

typedef struct
{
    volatile uint32_t TAILR;
} GPTMTAILR;

typedef struct
{
    volatile uint32_t TBILR;
} GPTMTBILR;

typedef struct
{
    volatile uint32_t TAMR;
} GPTMTAMATCHR;

typedef struct
{
    volatile uint32_t TBMR;
} GPTMTBMATCHR;

typedef struct
{
    volatile uint8_t TAPSR;
    volatile uint8_t TAPSRH;
    uint16_t _reserved;
} GPTMTAPR;

typedef struct
{
    volatile uint8_t TBPSR;
    volatile uint8_t TBPSRH;
    uint16_t _reserved;
} GPTMTBPR;

typedef struct
{
    volatile uint8_t TAPSMR;
    volatile uint8_t TAPSMRH;
    volatile uint16_t _reserved;
} GPTMTAPMR;

typedef struct
{
    volatile uint8_t TBPSMR;
    volatile uint8_t TBPSMRH;
    volatile uint16_t _reserved;
} GPTMTBPMR;

typedef struct
{
    volatile uint32_t TAR;
} GPTMTAR;

typedef struct
{
    volatile uint32_t TBR;
} GPTMTBR;

typedef struct
{
    volatile uint32_t TAV;
} GPTMTAV;

typedef struct
{
    volatile uint32_t TBV;
} GPTMTBV;

typedef struct
{
    volatile uint16_t RTCPD;
    volatile uint16_t _reserved;
} GPTMRTCPD;

typedef struct
{
    volatile uint16_t PSS;
    volatile uint16_t _reserved;
} GPTMTAPS;

typedef struct
{
    volatile uint16_t PSS;
    volatile uint16_t _reserved;
} GPTMTBPS;

typedef struct
{
    volatile uint16_t PSV;
    volatile uint16_t _reserved;
} GPTMTAPV;

typedef struct
{
    volatile uint16_t PSV;
    volatile uint16_t _reserved;
} GPTMTBPV;

typedef struct
{
    volatile uint8_t SIZE : 4;
    volatile uint32_t _reserved : 28;
} GPTMPP;

typedef struct
{
    GPTMCFG configuration;
    GPTMTAMR timer_A_mode;
    GPTMTBMR timer_B_mode;
    GPTMCTL control;
    GPTMSYNC synchronize;
    GPTMIMR interrupt_mask;
    GPTMRIS raw_interrupt_status;
    GPTMMIS masked_interrupt_status;
    GPTMICR interrupt_clear;
    GPTMTAILR timer_A_interval_load;
    GPTMTBILR timer_B_interval_load;
    GPTMTAMATCHR timer_A_match;
    GPTMTBMATCHR timer_B_match;
    GPTMTAPR timer_A_prescale;
    GPTMTBPR timer_B_prescale;
    GPTMTAPMR timer_A_prescale_match;
    GPTMTBPMR timer_B_prescale_match;
    GPTMTAR timer_A;
    GPTMTBR timer_B;
    GPTMTAV timer_A_value;
    GPTMTBV timer_B_value;
    GPTMRTCPD rtc_predivide;
    GPTMTAPS timer_A_prescale_snapshot;
    GPTMTBPS timer_B_prescale_snapshot;
    GPTMTAPV timer_A_prescale_value;
    GPTMTBPV timer_B_prescale_value;
    volatile uint8_t _reserved[0xF54];
    GPTMPP peripheral_properties;
} GPTM_t;

#endif /* __GPTM_REGISTERS_H__ */