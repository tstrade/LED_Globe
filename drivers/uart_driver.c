#include <stdint.h>
#include "sys/macros.h"
#include "sys/system_ctrl.h"
#include "registers/uart.h"
#include "uart_driver.h"
#include "gpio_driver.h"


static UART_Typedef* const UART_TABLE[] = {
    [UART_0] = (UART_Typedef *)0x4000C000,
    [UART_1] = (UART_Typedef *)0x4000D000,
    [UART_2] = (UART_Typedef *)0x4000E000,
    [UART_3] = (UART_Typedef *)0x4000F000,
    [UART_4] = (UART_Typedef *)0x40010000,
    [UART_5] = (UART_Typedef *)0x40011000,
    [UART_6] = (UART_Typedef *)0x40012000,
    [UART_7] = (UART_Typedef *)0x40013000
};

static inline UART_Typedef *
get_uart_base_addr (UART_MODULE module){
    return UART_TABLE[module];
}

static void uart_gpio_init(UART_MODULE module, GPIO_PORTS port);
static void flow_control_gpio_init(UART_MODULE module, GPIO_PORTS port);

void
uart_init(UART_MODULE module, GPIO_PORTS port, const UART_CONFIGS * configs)
{
    enable_clock (UART, module);
    uart_gpio_init(module, port);
    UART_Typedef * uart_mod = get_uart_base_addr (module);

    //DISABLE
    uart_mod->ctl.UARTEN = DISABLED;

    //FIND CLK RATE
    uint32_t clk;
    UART_CLKSRC clk_src = configs->clock_source;

    //SET SYSTEM CLOCK RATE
    if (clk_src == PIOSC){
        clk = PIOSC_CLK_RATE;
    } else {
        clk = SYS_CLK_RATE;
    }

    uint32_t clkdiv;
    //ClkDiv
    if (configs->high_speed == ENABLED){
        clkdiv = 8;
    } else {
        clkdiv = 16;
    }

    //IBRD and FBRD Calculation
    uint16_t IBRD, FBRD;
    IBRD = clk / (clkdiv * configs->baud_rate);
    FBRD = ((clk * 4)/(clkdiv * configs->baud_rate)) & 0x3F;
    uart_mod->ibrd.DIVINT = IBRD;
    uart_mod->fbrd.DIVFRAC = FBRD;

    if (configs->flow_control == ENABLED){
        flow_control_gpio_init(module, port);
    }

    //LCRH WRITING
    uart_mod->lcrh =
    (UARTLCRH){
        .PEN = configs->parity_enable,
        .EPS = configs->parity_select,
        .FEN = configs->fifo_enable,
        .SPS = configs->stick_parity,
        .WLEN = configs->data_bits,
        .STP2 = configs->stop_bits
    };


    //UART_CC configuration
    if (clk_src == PIOSC){
        uart_mod->cc.CS = PIOSC;
    } else {
        uart_mod->cc.CS = SYSTEM;
    }


    uart_mod->ifls =
    (UARTIFLS){
        .TXIFLSEL = configs->tx_fifo_level,
        .RXIFLSEL = configs->rx_fifo_level
    };

    uart_mod->dmactl =
    (UARTDMACTL){
        .TXDMAE = configs->transmit_dma,
        .RXDMAE = configs->receive_dma
    };


    uart_mod->ctl =
    (UARTCTL){
        .LBE = configs->loopback,
        .HSE = configs->high_speed,
        .UARTEN = ENABLED,
        .TXE = ENABLED,
        .RXE = ENABLED
    };
}

static void
uart_gpio_init (UART_MODULE module, GPIO_PORTS port)
{
    uint8_t pctl = 1;
    uint8_t rx, tx;

    switch (port)
    {
    case PORT_A:
        if (module == UART_0)
        {
            rx = 0;
            tx = 1;
        }
        break;

    case PORT_B:
        if (module == UART_1)
        {
            rx = 0;
            tx = 1;
        }
        break;

    case PORT_C:
        if (module == UART_4)
        {
            rx = 4;
            tx = 5;
        } else if (module == UART_3)
        {
            rx = 6;
            tx = 7;
        }
        break;

    case PORT_D:
        if (module == UART_6)
        {
            rx = 4;
            tx = 5;
        } else if (module == UART_2)
        {
            rx = 6;
            tx = 7;
        }
        break;

    case PORT_E:
        if (module == UART_7)
        {
            rx = 0;
            tx = 1;
        } else if (module == UART_5)
        {
            rx = 4;
            tx = 5;
        }
        break;

    default:
        break;
    }

    GPIO_CONFIGS uart_rx_configs =
    {
         .direction = GP_INPUT,
         .alternate_function = GPIO_ALTERNATE_FUNCTION,
         .pulldown_resistor = DISABLED,
         .pullup_resistor = DISABLED,
         .digital = ENABLED,
         .analog = DISABLED,
         .adc = DISABLED,
         .dma = DISABLED,
         .port_control = pctl,
         .pin = rx
    };

    GPIO_CONFIGS uart_tx_configs =
        {
             .direction = GP_OUTPUT,
             .alternate_function = GPIO_ALTERNATE_FUNCTION,
             .pulldown_resistor = DISABLED,
             .pullup_resistor = DISABLED,
             .digital = ENABLED,
             .analog = DISABLED,
             .adc = DISABLED,
             .dma = DISABLED,
             .port_control = pctl,
             .pin = tx
        };

    gpio_init (port, &uart_rx_configs, &uart_tx_configs, NULL);
}

static void
flow_control_gpio_init(UART_MODULE module, GPIO_PORTS port){
    if (module == UART_1 && port == PORT_A){
        GPIO_CONFIGS uart_rts_configs =
        {
         .direction = GP_INPUT,
        .alternate_function = GPIO_ALTERNATE_FUNCTION,
        .pulldown_resistor = DISABLED,
        .pullup_resistor = DISABLED,
        .digital = ENABLED,
        .analog = DISABLED,
        .adc = DISABLED,
        .dma = DISABLED,
        .port_control = 1,
        .pin = 0
       };

       GPIO_CONFIGS uart_cts_configs =
       {
        .direction = GP_INPUT,
        .alternate_function = GPIO_ALTERNATE_FUNCTION,
        .pulldown_resistor = DISABLED,
        .pullup_resistor = DISABLED,
        .digital = ENABLED,
        .analog = DISABLED,
        .adc = DISABLED,
        .dma = DISABLED,
        .port_control = 1,
        .pin = 1
       };

       gpio_init (port, &uart_cts_configs, &uart_rts_configs, NULL);
    }
}

void
uart_output(UART_MODULE module, uint8_t data){
    UART_Typedef *uart_mod = get_uart_base_addr(module);
    while (uart_mod->fr.TxFF);
    uart_mod->data.DATA = (uint8_t) data;
}

uint8_t
uart_read(UART_MODULE module){
    UART_Typedef *uart_mod = get_uart_base_addr(module);
    while (uart_mod->fr.RxFE);
    return (uint8_t)uart_mod->data.DATA;
}
