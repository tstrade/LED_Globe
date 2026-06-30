#ifndef __UART_DRIVER_H__
#define __UART_DRIVER_H__

#include <stdint.h>
#include "sys/macros.h"
#include "registers/gpio.h"

typedef enum
{
    UART_0,
    UART_1,
    UART_2,
    UART_3,
    UART_4,
    UART_5,
    UART_6,
    UART_7
} UART_MODULE;

typedef enum{
    SYSTEM = 0,
    PIOSC = 5
} UART_CLKSRC;

typedef enum {
    ODD,
    EVEN
} UART_PARITY;

typedef enum {
    ONE,
    TWO
} UART_STOPBIT;

typedef enum {
    RX_ONE_EIGHTH = 0,
    RX_ONE_FOURTH = 1,
    RX_DEFAULT = 2,
    RX_THREE_FOURTH = 3,
    RX_SEVEN_EIGHTH = 4
} UART_RX_FIFO_LEVEL;

typedef enum {
    TX_ONE_EIGHTH = 0,
    TX_ONE_FOURTH = 1,
    TX_DEFAULT = 2,
    TX_THREE_FOURTH = 3,
    TX_SEVEN_EIGHTH = 4
} UART_TX_FIFO_LEVEL;

typedef enum {
    DATA_5BIT = 0,
    DATA_6BIT = 1,
    DATA_7BIT = 2,
    DATA_8BIT = 3,
} UART_DATABIT;

typedef struct
{
    mode_t loopback;
    mode_t parity_enable;
    mode_t fifo_enable;
    mode_t stick_parity;
    mode_t flow_control;
    mode_t high_speed;
    UART_DATABIT data_bits;
    uint32_t baud_rate;
    UART_STOPBIT stop_bits;
    UART_PARITY parity_select;
    UART_CLKSRC clock_source;
    UART_TX_FIFO_LEVEL tx_fifo_level;
    UART_RX_FIFO_LEVEL rx_fifo_level;
    mode_t transmit_dma;
    mode_t receive_dma;
} UART_CONFIGS;

void uart_init(UART_MODULE module, GPIO_PORTS port, const UART_CONFIGS * configs);
void uart_output(UART_MODULE module, uint8_t data);
uint8_t uart_read(UART_MODULE module);

#endif
