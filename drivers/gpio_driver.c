#include <stdint.h>
#include <stdarg.h>
#include "macros.h"
#include "system_ctrl.h"
#include "gpio_registers.h"
#include "gpio_driver.h"


static GPIO_t * const LEGACY_GPIO_TABLE[] =
{
    [PORT_A] = (GPIO_t *)0x40004000,
    [PORT_B] = (GPIO_t *)0x40005000,
    [PORT_C] = (GPIO_t *)0x40006000,
    [PORT_D] = (GPIO_t *)0x40007000,
    [PORT_E] = (GPIO_t *)0x40024000,
    [PORT_F] = (GPIO_t *)0x40025000
};

static GPIO_t * const HIGHPERF_GPIO_TABLE[] =
{
    [PORT_A] = (GPIO_t *)0x40058000,
    [PORT_C] = (GPIO_t *)0x4005A000,
    [PORT_B] = (GPIO_t *)0x40059000,
    [PORT_D] = (GPIO_t *)0x4005B000,
    [PORT_E] = (GPIO_t *)0x4005C000,
    [PORT_F] = (GPIO_t *)0x4005D000
};

static inline GPIO_t *
get_gpio_base_addr (GPIO_PORTS port)
{
    if (__USE_LEGACY_GPIO_APERATURE__ == true)
        return LEGACY_GPIO_TABLE[port];
    else
        return HIGHPERF_GPIO_TABLE[port];
}

void
gpio_init (GPIO_PORTS port, const GPIO_CONFIGS * configs, ...)
{
    enable_clock (GPIO, port);

    GPIODIR _dir = {};
    GPIOAFSEL _afsel = {};
    GPIOPUR _pue = {};
    GPIOPDR _pde = {};
    GPIODEN _den = {};
    GPIOAMSEL _amsel = {};
    GPIOPCTL _pctl = {};
    GPIOADCCTL _adcen = {};
    GPIODMACTL _dmaen = {};

    const GPIO_CONFIGS * curr = configs;
    uint8_t pin;

    va_list args;
    va_start (args, configs);

    while (curr != NULL)
    {
        pin = curr->pin;
        if (pin >= 8)
        {
            curr = va_arg (args, const GPIO_CONFIGS *);
            continue;
        }

        _dir.DIR |= (curr->direction << pin);
        _afsel.AFSEL |= (curr->alternate_function << pin);
        _pue.PUE |= (curr->pullup_resistor << pin);
        _pde.PDE |= (curr->pulldown_resistor << pin);
        _den.DEN |= (curr->digital << pin);
        _amsel.AMSEL |= (curr->analog << pin);
        switch (pin)
        {
        case 0: _pctl.PMC0 |= curr->port_control; break;
        case 1: _pctl.PMC1 |= curr->port_control; break;
        case 2: _pctl.PMC2 |= curr->port_control; break;
        case 3: _pctl.PMC3 |= curr->port_control; break;
        case 4: _pctl.PMC4 |= curr->port_control; break;
        case 5: _pctl.PMC5 |= curr->port_control; break;
        case 6: _pctl.PMC6 |= curr->port_control; break;
        case 7: _pctl.PMC7 |= curr->port_control; break;
        default: break;
        }
        _adcen.ADCEN |= (curr->adc << pin);
        _dmaen.DMAEN |= (curr->dma << pin);

        curr = va_arg (args, const GPIO_CONFIGS *);
    }

    va_end (args);

    GPIO_t * gpio_port = get_gpio_base_addr (port);

    gpio_port->direction = _dir;
    gpio_port->alt_function_select = _afsel;
    gpio_port->pull_up_select = _pue;
    gpio_port->pull_down_select = _pde;
    gpio_port->digital_enable = _den;
    gpio_port->analog_mode_select = _amsel;
    gpio_port->port_control = _pctl;
    gpio_port->adc_control = _adcen;
    gpio_port->dma_control = _dmaen;
}

uint8_t
gpio_read (GPIO_PORTS port, uint16_t pin_mask)
{
    GPIO_t * gpio_port = get_gpio_base_addr (port);
    return gpio_port->data.DATA[(pin_mask << 2)];
}

void
gpio_write (GPIO_PORTS port, uint16_t pin_mask, uint8_t data)
{
    GPIO_t * gpio_port = get_gpio_base_addr (port);
    gpio_port->data.DATA[(pin_mask << 2)] = data;
}




