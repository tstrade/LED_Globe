#ifndef __GPIO_DRIVER_H__
#define __GPIO_DRIVER_H__

#include <stdint.h>
#include "tm4c123gh6pm_registers.h"

typedef enum 
{
    PORT_A = 0,
    PORT_B = 1,
    PORT_C = 2,
    PORT_D = 3,
    PORT_E = 4,
    PORT_F = 5
} GPIO_PORT __attribute__ ((packed));

typedef enum 
{
    INPUT = 0,
    OUTPUT = 1,
    INPUT_PULLUP = 2,
    INPUT_PULLDOWN = 3
} PIN_DIR __attribute__ ((packed));

typedef struct 
{
    volatile uint32_t DR[256];      //0x000 to 0x3FC
    volatile uint32_t DIR;          //0x400
    volatile uint32_t IS;           //0x404
    volatile uint32_t IBE;          //0x408
    volatile uint32_t IEV;          //0x40C
    volatile uint32_t IM;           //0x410
    volatile uint32_t RIS;          //0x414
    volatile uint32_t MIS;          //0x418
    volatile uint32_t ICR;          //0x41C
    volatile uint32_t AFSEL;        //0x420
    volatile uint32_t _reserved[55];// padding to 0x500
    volatile uint32_t DR2R;         //0x500
    volatile uint32_t DR4R;         //0x504
    volatile uint32_t DR8R;         //0x508
    volatile uint32_t ODR;          //0x50C
    volatile uint32_t PUR;          //0x510
    volatile uint32_t PDR;          //0x514
    volatile uint32_t SLR;          //0x518
    volatile uint32_t DEN;          //0x51C
    volatile uint32_t LOCK;         //0x520
    volatile uint32_t CR;           //0x524
    volatile uint32_t AMSEL;        //0x528
    volatile uint32_t PCTL;         //0x52C
    volatile uint32_t ADCCTL;       //0x530
    volatile uint32_t DMACTL;       //0x534
} gpio_t;

void gpio_init (GPIO_PORT port, port_t type, uint8_t pin, PIN_DIR direction);
void gpio_interrupt_init (GPIO_PORT port);

// DEFAULT AHB PORTS
uint8_t read_pin (GPIO_PORT port, uint8_t pin);

uint8_t read_field (GPIO_PORT port, uint8_t mask);
uint8_t read_port (GPIO_PORT port);

uint8_t read_pin_APB (GPIO_PORT port, uint8_t pin);
uint8_t read_field_APB (GPIO_PORT port, uint8_t mask);
uint8_t read_port_APB (GPIO_PORT port);  


//DEFAULT AHB PORTS

//  output_pin: output 0 if val is 0, 1 if otherwise
void output_pin (GPIO_PORT port, uint8_t pin, uint8_t val);

//output_field: mask to pick which pins being affected, 
//                 output 0 if val is 0, 1 if otherwise
void output_field (GPIO_PORT port, uint8_t mask, uint8_t val);

//output_port: for funsies, no one will ever use this
//            This is prolly the most useless function of them all
void output_port (GPIO_PORT port, uint8_t val);

//APB PORTS BECAUSE WHY NOT
void output_pin_APB (GPIO_PORT port, uint8_t pin, uint8_t val);
void output_field_APB (GPIO_PORT port, uint8_t mask, uint8_t val);
void output_port_APB (GPIO_PORT port, uint8_t val);

#endif /* __GPIO_DRIVER_H__ */