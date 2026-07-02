#include <stdint.h>

#include "led_driver.h"
#include "ssi_driver.h"

void
sk9822_init(SSI_MODULE module, GPIO_PORTS port){
    SSI_CONFIGS ssi_mod_confs =
        {
         .loopback = DISABLED,
         .master_slave = MASTER,
         .clock_source = SYSTEM,
         .clock_phase = SECOND_EDGE,
         .polarity = STEADY_STATE_LOW,
         .frame_format = FREESCALE,
         .data_size = 8,
         .bit_rate = 1e6,
         .prescale_divisor = 2,
         .transmit_dma = DISABLED,
         .receive_dma = DISABLED
    };
    ssi_init (module, port, &ssi_mod_confs);
}


void send_frame_buffer (SSI_MODULE module, frame_t * buffer, uint16_t buffer_size){
    void * frame = (void *) buffer;
    uint16_t i;
    for (i = 0; i < buffer_size; i++){

        ssi_write(module, (*(uint8_t *) frame));
        frame = (char *)frame + sizeof (uint8_t);
        ssi_write(module, (*(uint8_t *) frame));
        frame = (char *)frame + sizeof (uint8_t);
        ssi_write(module, (*(uint8_t *) frame));
        frame = (char *)frame + sizeof (uint8_t);
        ssi_write(module, (*(uint8_t *) frame));
        frame = (char *)frame + sizeof (uint8_t);

    }
}
