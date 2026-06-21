#ifndef __GPIO_DRIVER_H__
#define __GPIO_DRIVER_H__

#include <stdint.h>
#include <stdarg.h>
#include "macros.h"
#include "gpio_registers.h"


typedef enum
{
    GP_INPUT,
    GP_OUTPUT
} GPIO_DIRECTION;

typedef enum
{
    GPIO_DEFAULT_FUNCTION,
    GPIO_ALTERNATE_FUNCTION
} GPIO_ALT_SELECT;

typedef struct
{
    GPIO_DIRECTION direction;
    GPIO_ALT_SELECT alternate_function;
    mode_t pulldown_resistor;
    mode_t pullup_resistor;
    mode_t digital;
    mode_t analog;
    mode_t adc;
    mode_t dma;
    uint8_t port_control : 4;
    uint8_t pin : 4;
} GPIO_CONFIGS;


void gpio_init (GPIO_PORTS port, const GPIO_CONFIGS * configs, ...);
uint8_t gpio_read (GPIO_PORTS port, uint16_t pin_mask);
void gpio_write (GPIO_PORTS port, uint16_t pin_mask, uint8_t data);

#endif /* __GPIO_DRIVER_H__ */
