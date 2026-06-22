#include <stdint.h>
#include "led_driver.h"
#include "ssi_driver.h"

frame_t frame_buffer[146] =
{
    {
        .red = 0,
        .green = 0,
        .blue = 0,
        .brightness = 0,
        .flag = 0
    },
    [1 ... 144] =
    {
        .red = 0,
        .green = 0,
        .blue = 255,
        .brightness = 0x10,
        .flag = 0x7
    },
    {
        .red = 0xFF,
        .green = 0xFF,
        .blue = 0xFF,
        .brightness = 0x1F,
        .flag = 0x7
    }
};

void
send_frame_buffer (SSI_MODULE module)
{
    void * frame = (void *)frame_buffer;
    uint8_t i;

    for (i = 0; i < 146; i++)
    {
        ssi_write (module, (*(uint16_t *)frame));
        frame = (char *)frame + sizeof (uint16_t);
        ssi_write (module, (*(uint16_t *)frame));
    }
}

