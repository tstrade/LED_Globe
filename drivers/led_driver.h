#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__

#include <stdint.h>
#include "ssi_driver.h"
#include "gpio_driver.h"

typedef struct {
    uint8_t brightness : 5;
    uint8_t flag       : 3;
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} frame_t;

void sk9822_init(SSI_MODULE module, GPIO_PORTS port);
void send_frame_buffer (SSI_MODULE module, frame_t * buffer, uint16_t buffer_size);

#endif
