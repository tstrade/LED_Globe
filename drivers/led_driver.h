#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__

#include "ssi_driver.h"

typedef struct
{
    uint8_t red : 8;
    uint8_t green : 8;
    uint8_t blue : 8;
    uint8_t brightness : 5;
    uint8_t flag : 3;
} frame_t;


extern frame_t frame_buffer[146];

#define update_frame_field(idx,field,val) frame_buffer[idx].##field = val

void send_frame_buffer (SSI_MODULE module);

#endif /* __LED_DRIVER_H__ */
