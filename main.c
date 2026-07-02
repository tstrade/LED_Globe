#include <stdint.h>
#include "sys/macros.h"
#include "drivers/led_driver.h"
#include "drivers/uart_driver.h"
#include "drivers/gpio_driver.h"

static const uint8_t __START_FRAME__ = 0;
static const uint8_t __STOP_FRAME__ = 145;

frame_t frame_buffer[146] =
{
 {
  .flag = 0,
  .brightness = 0,
  .blue = 0,
  .red = 0,
  .green = 0,
 },
 [1 ... 144] =
 {
  .flag = 0x7,
  .brightness = 0x1F,
  .blue = 0x00,
  .red = 0x00,
  .green = 0x00
 },
 {
  .flag = 0x7,
  .brightness = 0x1F,
  .blue = 0xFF,
  .red = 0xFF,
  .green = 0xFF,
 }
};

void delay(uint32_t count) {
    volatile uint32_t i = count;
    while (i--);
}

void main(void)
{
    UART_CONFIGS uart_mod_configs =
    {
         .loopback = DISABLED,
         .parity_enable = DISABLED,
         .fifo_enable = DISABLED,
         .stick_parity = DISABLED,
         .flow_control = DISABLED,
         .data_bits = DATA_8BIT,
         .baud_rate = 115200,
         .stop_bits = ONE,
         .parity_select = EVEN,
         .clock_source = PIOSC,
         .high_speed = DISABLED,
         .tx_fifo_level = TX_DEFAULT,
         .rx_fifo_level = RX_DEFAULT,
         .transmit_dma = DISABLED,
         .receive_dma = DISABLED
    };
    uart_init(UART_0, PORT_A, &uart_mod_configs);

    frame_t pix =
    {
         .flag = 0x7,
         .brightness = 0x1F,
         .blue = 0x00,
         .red = 0x00,
         .green = 0xFF
    };

    frame_t clear =
    {
         .flag = 0x7,
         .brightness = 0x0,
         .blue = 0x00,
         .red = 0x00,
         .green = 0x00
    };

    sk9822_init(SSI2, PORT_B);
    char to_print[] = "THIGMABOB\n\r";
    uart_print(UART_0, (uint8_t *)to_print);

    uint8_t count = 1;
    uint8_t direction = 1;

    while (1){
        delay(100);
        frame_buffer[count] = clear;
        count += direction;

        if (count >= 144) direction = -1;
        if (count <= 1)   direction =  1;

        frame_buffer[count] = pix;
        send_frame_buffer(SSI2, frame_buffer, 146);
    }
}
