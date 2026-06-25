#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__

#include "ssi_driver.h"

#define __USE_SSI_REVERSE_ORDER__ 1

typedef struct
{
    uint8_t red : 8;
    uint8_t green : 8;
    uint8_t blue : 8;
    uint8_t brightness : 5;
    uint8_t flag : 3;
} FWD_frame_t;

typedef struct
{
    uint8_t blue;
    uint8_t brightness : 5;
    uint8_t flag : 3;
    uint8_t red;
    uint8_t green;
} RVS_frame_t;

typedef union
{
    FWD_frame_t f;
    RVS_frame_t r;
} frame_t;

static const uint8_t __START_FRAME__ = 0;
static const uint8_t __STOP_FRAME__ = 145;
extern frame_t frame_buffer[146];

void send_frame_buffer (SSI_MODULE module);

#endif /* __LED_DRIVER_H__ */
