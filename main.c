#include <stdint.h>
#include "macros.h"
#include "ssi_driver.h"
#include "gpio_driver.h"
#include "led_driver.h"

int main(void)
{
    SSI_CONFIGS ssi_mod_confs =
    {
         .loopback = DISABLE_LOOPBACK,
         .master_slave = MASTER,
         .clock_source = SYSTEM,
         .clock_phase = FIRST_EDGE,
         .polarity = STEADY_STATE_HIGH,
         .frame_format = FREESCALE,
         .data_size = 16,
         .bit_rate = 10e6,
         .prescale_divisor = 2,
         .transmit_dma = DISABLE_TXDMA,
         .receive_dma = DISABLE_RXDMA
    };

    ssi_init (SSI0, PORT_A, &ssi_mod_confs);
    while (1)
    {
        send_frame_buffer (SSI0);
    }

    return 0;
}
