#include <stdint.h>
#include "macros.h"
#include "system_ctrl.h"
#include "ssi_registers.h"
#include "ssi_driver.h"
#include "gpio_driver.h"

static SSI_t * const SSI_TABLE[] =
{
    [SSI0] = (SSI_t *)0x40008000,
    [SSI1] = (SSI_t *)0x40009000,
    [SSI2] = (SSI_t *)0x4000A000,
    [SSI3] = (SSI_t *)0x4000B000
};

static inline SSI_t *
get_ssi_base_addr (SSI_MODULE module)
{
    return SSI_TABLE[module];
}

static void ssi_gpio_init (SSI_MODULE module, GPIO_PORTS port);

void
ssi_init (SSI_MODULE module, GPIO_PORTS port, const SSI_CONFIGS * configs)
{
    enable_clock (SSI, module);

    ssi_gpio_init (module, port);

    SSI_t * ssi_mod = get_ssi_base_addr (module);

    // Disable
    ssi_mod->ctrl_1.SSE = DISABLED;

    // Control Type
    ssi_mod->ctrl_1.MS = configs->master_slave;

    // Clock Source
    ssi_mod->clock_config.CS = configs->clock_source;

    // Prescale Divisor
    ssi_mod->clock_prescale.CPSDVSR = configs->prescale_divisor;

    {
        uint8_t src;
        if (configs->clock_source == SYSTEM)
        {
            src = (uint8_t)((SYS_CLK_RATE / (configs->bit_rate * configs->prescale_divisor)) - 1);
        }
        else
        {
            src = (uint8_t)((PIOSC_CLK_RATE / (configs->bit_rate * configs->prescale_divisor)) - 1);

        }

        // Clock Polarity
        uint8_t spo = configs->polarity;

        // Frame Format
        uint8_t frf = configs->frame_format;
        uint8_t sph = 0;
        if (configs->frame_format == FREESCALE)
            sph = configs->clock_phase;

        // Data Size
        uint8_t dss;
        if (configs->data_size >= 4 && configs->data_size <= 16)
            dss = (uint8_t)configs->data_size - 1;
        else
            dss = 0x0F; // Default 16-bit data

        ssi_mod->ctrl_0 =
        (SSICR0){
             .DSS = dss,
             .FRF = frf,
             .SPH = sph,
             .SPO = spo,
             .SRC = src
        };
    }

    // DMA Control
    ssi_mod->dma_ctrl =
    (SSIDMACTL){
          .RXDMAE = configs->receive_dma,
          .TXDMAE = configs->transmit_dma
    };

    // Enable
    ssi_mod->ctrl_1.SSE = ENABLED;
}

static void
ssi_gpio_init (SSI_MODULE module, GPIO_PORTS port)
{
    uint8_t pctl = 2;
    uint8_t clk_pin, fss_pin, rx_pin, tx_pin;

    switch (port)
    {
    case PORT_A:
        if (module == SSI0)
        {
            clk_pin = 2;
            fss_pin = 3;
            rx_pin = 4;
            tx_pin = 5;
        }
        break;

    case PORT_B:
        if (module == SSI2)
        {
            clk_pin = 4;
            fss_pin = 5;
            rx_pin = 6;
            tx_pin = 7;
        }
        break;

    case PORT_D:
        switch (module)
        {
        case SSI3:
            pctl = 1;
        case SSI1:
            clk_pin= 0;
            fss_pin = 1;
            rx_pin = 2;
            tx_pin = 3;
        default:
            break;
        }
        break;

    case PORT_F:
        if (module == SSI1)
        {
            clk_pin = 2;
            fss_pin = 3;
            rx_pin = 0;
            tx_pin = 1;
        }
        break;

    default:
        break;
    }

    GPIO_CONFIGS ssi_clk_confs =
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
         .pin = clk_pin
    };

    GPIO_CONFIGS ssi_fss_confs =
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
         .pin = fss_pin
    };

    GPIO_CONFIGS ssi_rx_confs =
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
         .pin = rx_pin
    };

    GPIO_CONFIGS ssi_tx_confs =
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
         .pin = tx_pin
    };

    gpio_init (port, &ssi_clk_confs, &ssi_fss_confs, &ssi_rx_confs, &ssi_tx_confs, NULL);
}

uint16_t
ssi_read (SSI_MODULE module)
{
    SSI_t * ssi_mod = get_ssi_base_addr (module);
    while (ssi_mod->status.RFF == 0);
    return ssi_mod->data.DATA;
}

void
ssi_write (SSI_MODULE module, uint16_t data)
{
    SSI_t * ssi_mod = get_ssi_base_addr (module);
    while (ssi_mod->status.TFE == 0);
    ssi_mod->data.DATA = data;
}
