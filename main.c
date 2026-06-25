#include <stdint.h>
#include "macros.h"
#include "ssi_driver.h"
#include "gpio_driver.h"
#include "led_driver.h"

int main(void)
{
    SSI_CONFIGS ssi_mod_confs =
    {
         .loopback = DISABLED,
         .master_slave = MASTER,
         .clock_source = SYSTEM,
         .clock_phase = SECOND_EDGE,
         .polarity = STEADY_STATE_LOW,
         .frame_format = FREESCALE,
         .data_size = 16,
         .bit_rate = 1e6,
         .prescale_divisor = 2,
         .transmit_dma = DISABLED,
         .receive_dma = DISABLED
    };


    ssi_init (SSI2, PORT_B, &ssi_mod_confs);

    while (1)
    {
        send_frame_buffer (SSI2);
    };


    return 0;
}
