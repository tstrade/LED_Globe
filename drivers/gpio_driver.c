#include <stdint.h>
#include <assert.h>
#include "gpio_driver.h"
#include "tm4c123gh6pm_registers.h"

static gpio_t * const APB_TABLE[] = 
{
    [PORT_A] = GPIO_PORTAP_BASE_ADDR,
    [PORT_B] = GPIO_PORTBP_BASE_ADDR,
    [PORT_C] = GPIO_PORTCP_BASE_ADDR,
    [PORT_D] = GPIO_PORTDP_BASE_ADDR,
    [PORT_E] = GPIO_PORTEP_BASE_ADDR,
    [PORT_F] = GPIO_PORTFP_BASE_ADDR,
};


static gpio_t* const AHB_TABLE[] = 
{
    [PORT_A] = GPIO_PORTAH_BASE_ADDR,
    [PORT_B] = GPIO_PORTBH_BASE_ADDR,
    [PORT_C] = GPIO_PORTCH_BASE_ADDR,
    [PORT_D] = GPIO_PORTDH_BASE_ADDR,
    [PORT_E] = GPIO_PORTEH_BASE_ADDR,
    [PORT_F] = GPIO_PORTFH_BASE_ADDR,
};

#define get_gpio_base(type,port) ( (gpio_t *) type##_TABLE[port] )

void
gpio_init (GPIO_PORT port, port_t type, uint8_t pin, PIN_DIR direction)
{
    enable_clock (GPIO, port);

    gpio_t * gpio_port = GET_GPIO_BASE(type, port);
    gpio_port->DEN |= (1U << pin);

    if (direction != OUTPUT){
        if (direction == INPUT){
            //Configure the pin as Input
            gpio_port->DIR &= ~(1U << pin); 
        } else {
            gpio_port->DIR &= ~(1U << pin);
            if (direction == INPUT_PULLUP){
                //Configure PULL_UP
                gpio_port -> PUR |= (1U << pin);
            } else if (direction == INPUT_PULLDOWN){
                //COnfigure PULL_DOWN
                gpio_port -> PDR |= (1U << pin);
            }
        }
    } else {
        // Configure the pin as Output
        gpio_port->DIR |= (1U << pin);
    }
    return;
}

//TODO
//not finished
void 
gpio_interrupt_init (GPIO_PORT port)
{
    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0     && "Check PORT Initialization");
}


//AHB READ
uint8_t 
read_pin (GPIO_PORT port, uint8_t pin)
{
    assert(port <= PORT_F   && "GPIO_PORT port input is out of range");
    assert(pin <= 7         && "pin value is out of range");

    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0     && "Check PORT Initialization");

    gpio_t *gpio_port = GET_GPIO_BASE(AHB, port);
    return (uint8_t)(((gpio_port->DR[1U<<pin]) >> pin) & 0x1);
}

uint8_t 
read_port(GPIO_PORT port)
{
    assert(port <= PORT_F       && "GPIO_PORT port input is out of range");
    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0         && "Check PORT Initialization");
    
    gpio_t *gpio_port = GET_GPIO_BASE(AHB, port);
    return (uint8_t)(gpio_port->DR[255]);
}

uint8_t 
read_field (GPIO_PORT port, uint8_t mask)
{
    assert(port <= PORT_F       && "GPIO_PORT port input is out of range");
    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0         && "Check PORT Initialization");

    gpio_t *gpio_port = GET_GPIO_BASE(AHB, port);
    return (uint8_t)(gpio_port->DR[mask]);
}

//APB READ
uint8_t read_pin_APB (GPIO_PORT port, uint8_t pin)
{
    assert(port <= PORT_F   && "GPIO_PORT port input is out of range");
    assert(pin <= 7         && "pin value is out of range");

    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0     && "Check PORT Initialization");

    gpio_t *gpio_port = GET_GPIO_BASE(APB, port);
    return (uint8_t)(((gpio_port->DR[1U<<pin]) >> pin) & 0x1);
}

uint8_t 
read_port_APB (GPIO_PORT port)
{
    assert(port <= PORT_F       && "GPIO_PORT port input is out of range");
    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0         && "Check PORT Initialization");
    
    gpio_t *gpio_port = GET_GPIO_BASE(APB, port);
    return (uint8_t)(gpio_port->DR[255]);
}

uint8_t 
read_field_APB (GPIO_PORT port, uint8_t mask)
{
    assert(port <= PORT_F       && "GPIO_PORT port input is out of range");
    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0         && "Check PORT Initialization");

    gpio_t *gpio_port = GET_GPIO_BASE(APB, port);
    return (uint8_t)(gpio_port->DR[mask]);
}


void 
output_pin (GPIO_PORT port, uint8_t pin, uint8_t val)
{
    assert(port <= PORT_F   && "GPIO_PORT port input is out of range");
    assert(pin <= 7         && "pin value is out of range");

    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0     && "Check PORT Initialization");

    gpio_t *gpio_port = GET_GPIO_BASE(AHB, port);
    if (val == 0){
        gpio_port->DR[1U << pin] = 0x00;
    } else {
        gpio_port->DR[1U << pin] = 0xFF;
    }    
}


void 
output_port (GPIO_PORT port, uint8_t val)
{
    assert(port <= PORT_F       && "GPIO_PORT port input is out of range");
    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0         && "Check PORT Initialization");

    gpio_t *gpio_port = GET_GPIO_BASE(AHB, port);
    gpio_port->DR[255] = 0x00;
    gpio_port->DR[255] |= val;
}


void
output_field (GPIO_PORT port, uint8_t mask, uint8_t val)
{
    assert(port <= PORT_F       && "GPIO_PORT port input is out of range");
    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0         && "Check PORT Initialization");

    gpio_t *gpio_port = GET_GPIO_BASE(AHB, port);
    if (val == 0){
        gpio_port->DR[mask] = 0x00;
    } else {
        gpio_port->DR[mask] = 0xFF;
    }    
}



void 
output_pin_APB (GPIO_PORT port, uint8_t pin, uint8_t val)
{
    assert(port <= PORT_F   && "GPIO_PORT port input is out of range");
    assert(pin <= 7         && "pin value is out of range");

    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0     && "Check PORT Initialization");

    gpio_t *gpio_port = GET_GPIO_BASE(APB, port);
    if (val == 0){
        gpio_port->DR[1U << pin] = 0x00;
    } else {
        gpio_port->DR[1U << pin] = 0xFF;
    }    
}


void 
output_port (GPIO_PORT port, uint8_t val)
{
    assert(port <= PORT_F       && "GPIO_PORT port input is out of range");
    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0         && "Check PORT Initialization");

    gpio_t *gpio_port = GET_GPIO_BASE(APB, port);
    gpio_port->DR[255] = 0x00;
    gpio_port->DR[255] |= val;
}


void
output_field (GPIO_PORT port, uint8_t mask, uint8_t val)
{
    assert(port <= PORT_F       && "GPIO_PORT port input is out of range");
    uint32_t port_PR = (*((volatile uint32_t *)(SYS_CONTROL_BASE_ADDR + PRGPIO))) & (1U << port);
    assert(port_PR != 0         && "Check PORT Initialization");

    gpio_t *gpio_port = GET_GPIO_BASE(APB, port);
    if (val == 0){
        gpio_port->DR[mask] = 0x00;
    } else {
        gpio_port->DR[mask] = 0xFF;
    }    
}