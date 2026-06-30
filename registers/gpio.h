#ifndef REGISTERS_GPIO_H_
#define REGISTERS_GPIO_H_

#include <stdint.h>

typedef enum
{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F
} GPIO_PORTS;

typedef struct
{
    volatile uint8_t DATA[1024];
} GPIODATA;

typedef struct
{
    volatile uint8_t DIR : 8;
    volatile uint32_t _reserved : 24;
} GPIODIR;

typedef struct
{
    volatile uint8_t IS : 8;
    volatile uint32_t _reserved : 24;
} GPIOIS;

typedef struct
{
    volatile uint8_t IBE : 8;
    volatile uint32_t _reserved : 24;
} GPIOIBE;

typedef struct
{
    volatile uint8_t IEV : 8;
    volatile uint32_t _reserved : 24;
} GPIOIEV;

typedef struct
{
    volatile uint8_t IME : 8;
    volatile uint32_t _reserved : 24;
} GPIOIM;

typedef struct
{
    volatile uint8_t RIS : 8;
    volatile uint32_t _reserved : 24;
} GPIORIS;

typedef struct
{
    volatile uint8_t MIS : 8;
    volatile uint32_t _reserved : 24;
} GPIOMIS;

typedef struct
{
    volatile uint8_t IC : 8;
    volatile uint32_t _reserved : 24;
} GPIOICR;

typedef struct
{
    volatile uint8_t AFSEL : 8;
    volatile uint32_t _reserved : 24;
} GPIOAFSEL;


// 224 byte buffer

typedef struct
{
    volatile uint8_t DRV2 : 8;
    volatile uint32_t _reserved : 24;
} GPIODR2R;

typedef struct
{
    volatile uint8_t DRV4 : 8;
    volatile uint32_t _reserved : 24;
} GPIODR4R;

typedef struct
{
    volatile uint8_t DRV8 : 8;
    volatile uint32_t _reserved : 24;
} GPIODR8R;

typedef struct
{
    volatile uint8_t ODE : 8;
    volatile uint32_t _reserved : 24;
} GPIOODR;

typedef struct
{
    volatile uint8_t PUE : 8;
    volatile uint32_t _reserved : 24;
} GPIOPUR;

typedef struct
{
    volatile uint8_t PDE : 8;
    volatile uint32_t _reserved : 24;
} GPIOPDR;

typedef struct
{
    volatile uint8_t SRL : 8;
    volatile uint32_t _reserved : 24;
} GPIOSLR;

typedef struct
{
    volatile uint8_t DEN : 8;
    volatile uint32_t _reserved : 24;
} GPIODEN;

typedef struct
{
    volatile uint32_t LOCK;
} GPIOLOCK;

typedef struct
{
    volatile uint8_t CR : 8;
    volatile uint32_t _reserved : 24;
} GPIOCR;

typedef struct
{
    volatile uint8_t AMSEL : 8;
    volatile uint32_t _reserved : 24;
} GPIOAMSEL;

typedef struct
{
    volatile uint8_t PMC0 : 4;
    volatile uint8_t PMC1 : 4;
    volatile uint8_t PMC2 : 4;
    volatile uint8_t PMC3 : 4;
    volatile uint8_t PMC4 : 4;
    volatile uint8_t PMC5 : 4;
    volatile uint8_t PMC6 : 4;
    volatile uint8_t PMC7 : 4;
} GPIOPCTL;

typedef struct
{
    volatile uint8_t ADCEN : 8;
    volatile uint32_t _reserved : 24;
} GPIOADCCTL;

typedef struct
{
    volatile uint8_t DMAEN : 8;
    volatile uint32_t _reserved : 24;
} GPIODMACTL;

typedef struct
{
    GPIODATA data;
    GPIODIR direction;
    GPIOIS interrupt_sense;
    GPIOIBE interrupt_both_edges;
    GPIOIEV interrupt_event;
    GPIOIM interrupt_mask;
    GPIORIS raw_interrupt_status;
    GPIOMIS masked_interrupt_status;
    GPIOICR interrupt_clear;
    GPIOAFSEL alt_function_select;
    uint8_t _reserved[220];
    GPIODR2R drive_select_2mA;
    GPIODR4R drive_select_4mA;
    GPIODR8R drive_select_8mA;
    GPIOODR open_drain_select;
    GPIOPUR pull_up_select;
    GPIOPDR pull_down_select;
    GPIOSLR slew_rate_ctrl_select;
    GPIODEN digital_enable;
    GPIOLOCK lock;
    GPIOCR commit;
    GPIOAMSEL analog_mode_select;
    GPIOPCTL port_control;
    GPIOADCCTL adc_control;
    GPIODMACTL dma_control;
} GPIO_t;

#endif /* REGISTERS_GPIO_H_ */
