#ifndef __HIBERNATION_REGISTERS_H__
#define __HIBERNATION_REGISTERS_H__

#include <stdint.h>

typedef volatile uint32_t HIBRTCC;

typedef volatile uint32_t HIBRTCM0;

typedef volatile uint32_t HIBRTCLD;

typedef struct
{
    volatile uint8_t RTCEN : 1;
    volatile uint8_t HIBREQ : 1;
    volatile uint8_t _reserved_1 : 1;
    volatile uint8_t RTCWEN : 1;
    volatile uint8_t PINWEN : 1;
    volatile uint8_t _reserved_2 : 1;
    volatile uint8_t CLK32EN : 1;
    volatile uint8_t VABORT : 1;
    volatile uint8_t VDD3ON : 1;
    volatile uint8_t BATWKEN : 1;
    volatile uint8_t BATCHK : 1;
    volatile uint8_t _reserved_3 : 2;
    volatile uint8_t VBATSEL : 2;
    volatile uint8_t _reserved_4 : 1;
    volatile uint8_t OSCBYP : 1;
    volatile uint8_t OSCDRV : 1;
    volatile uint16_t _reserved_5 : 13;
    volatile uint8_t WRC : 1;
} HIBCTL;

typedef struct
{
    volatile uint8_t RTCALT0 : 1;
    volatile uint8_t _reserved_1 : 1;
    volatile uint8_t LOWBAT : 1;
    volatile uint8_t EXTW : 1;
    volatile uint8_t WC : 1;
    volatile uint32_t _reserved_2 : 27
} HIBIM;

typedef struct
{
    volatile uint8_t RTCALT0 : 1;
    volatile uint8_t _reserved_1 : 1;
    volatile uint8_t LOWBAT : 1;
    volatile uint8_t EXTW : 1;
    volatile uint8_t WC : 1;
    volatile uint32_t _reserved_2 : 27
} HIBRIS;

typedef struct
{
    volatile uint8_t RTCALT0 : 1;
    volatile uint8_t _reserved_1 : 1;
    volatile uint8_t LOWBAT : 1;
    volatile uint8_t EXTW : 1;
    volatile uint8_t WC : 1;
    volatile uint32_t _reserved_2 : 27
} HIBMIS;

typedef struct
{
    volatile uint8_t RTCALT0 : 1;
    volatile uint8_t _reserved_1 : 1;
    volatile uint8_t LOWBAT : 1;
    volatile uint8_t EXTW : 1;
    volatile uint8_t WC : 1;
    volatile uint32_t _reserved_2 : 27
} HIBIC;

typedef struct
{
    volatile uint16_t TRIM;
    volatile uint16_t _reserved;
} HIBRTCT;

typedef struct
{
    volatile uint16_t RTCSSC : 15;
    volatile uint8_t _reserved_1 : 1;
    volatile uint16_t RTCSSM : 15;
    volatile uint8_t _reserved_2 : 1;
} HIBRTCSS;

typedef struct
{
    volatile uint32_t RTD;
} HIBDATA;

typedef struct
{
    HIBRTCC rtc_counter;
    HIBRTCM0 rtc_match_0;
    volatile uint8_t _reserved_1;
    HIBRTCLD rtc_load;
    HIBCTL control;
    HIBIM interrupt_mask;
    HIBRIS raw_interrupt_status;
    HIBMIS masked_interrupt_status;
    HIBIC interrupt_clear;
    HIBRTCT rtc_trim;
    HIBRTCSS rtc_subseconds;
    volatile uint8_t _reserved_2;
    HIBDATA data[0x3F];
}

#endif /* __HIBERNATION_REGISTERS_H__ */