#ifndef __SYSTEM_CTRL_H__
#define __SYSTEM_CTRL_H__

static const uint32_t SYS_CLK_RATE = (uint32_t)0x0F42400;


static const uint32_t SYS_CONTROL_BASE_ADDR = (uint32_t)(0x400FE000);
static const uint32_t RCC                   = (uint32_t)(0x060); // Run-Mode Clock Configuration
static const uint32_t RCC2                  = (uint32_t)(0x070); // Run-Mode Clock Configuration 2

static const uint32_t PPWD     = (uint32_t)(0x300); // Watchdog Timer Peripheral Present
static const uint32_t PPTIMER  = (uint32_t)(0x304); // 16/32-Bit General-Purpose Timer Peripheral Present
static const uint32_t PPGPIO   = (uint32_t)(0x308); // General-Pupose Input/Output Peripheral Present
static const uint32_t PPDMA    = (uint32_t)(0x30C); // Micro Direct Memory Access Peripheral Present
static const uint32_t PPHIB    = (uint32_t)(0x314); // Hibernation Peripheral Present
static const uint32_t PPUART   = (uint32_t)(0x318); // Universal Asynchronous Receiver/Transmitter Peripheral Present
static const uint32_t PPSSI    = (uint32_t)(0x31C); // Synchronous Serial Interface Peripheral Present
static const uint32_t PPI2C    = (uint32_t)(0x320); // Inter-Integrated Circuit Peripheral Present
static const uint32_t PPUSB    = (uint32_t)(0x328); // Universal Serial Bus Peripheral Present
static const uint32_t PPCAN    = (uint32_t)(0x334); // Controller Area Network Peripheral Present
static const uint32_t PPADC    = (uint32_t)(0x338); // Analog-to-Digital Converter Peripheral Present
static const uint32_t PPACMP   = (uint32_t)(0x33C); // Analog Comparator Peripheral Present
static const uint32_t PPPWM    = (uint32_t)(0x340); // Pulse Width Modulator Peripheral Present
static const uint32_t PPQUI    = (uint32_t)(0x344); // Quadrature Encoder Interface Peripheral Present
static const uint32_t PPEEPROM = (uint32_t)(0x358); // EEPROM Peripheral Present
static const uint32_t PPWTIMER = (uint32_t)(0x35C); // 32/64-Bit Wide General-Purpose Timer Peripheral Present

static const uint32_t RCGCWD                = (uint32_t)(0x600); // Watchdog Timer Run Mode Clock Gating Control
static const uint32_t RCGCTIMER             = (uint32_t)(0x604); // 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control
static const uint32_t RCGCGPIO              = (uint32_t)(0x608); // General-Purpose Input/Output Run Mode Clock Gating Control
static const uint32_t RCGCDMA               = (uint32_t)(0x60C); // Micro Direct Memory Access Run Mode Clock Gating Control
static const uint32_t RCGCHIB               = (uint32_t)(0x614); // Hibernation Run Mode Clock Gating Control
static const uint32_t RCGCUART              = (uint32_t)(0x618); // Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control
static const uint32_t RCGCSSI               = (uint32_t)(0x61C); // Synchronous Serial Interface Run Mode Clock Gating Control
static const uint32_t RCGCI2C               = (uint32_t)(0x620); // Inter-Integrated Circuit Run Mode Clock Gating Control
static const uint32_t RCGCUSB               = (uint32_t)(0x628); // Universal Serial Bus Run Mode Clock Gating Control
static const uint32_t RCGCCAN               = (uint32_t)(0x634); // Controller Area Network Run Mode Clock Gating Control
static const uint32_t RCGCADC               = (uint32_t)(0x638); // Analog-to-Digital Converter Run Mode Clock Gating Control
static const uint32_t RCGCACMP              = (uint32_t)(0x63C); // Analog Comparator Run Mode Clock Gating Control
static const uint32_t RCGCPWM               = (uint32_t)(0x640); // Pulse Width Modulation Run Mode Clock Gating Control
static const uint32_t RCGCQEI               = (uint32_t)(0x644); // Quadrature Encoder Interface Run Mode Clock Gating Control
static const uint32_t RCGCEEPROM            = (uint32_t)(0x658); // EEPROM Run Mode Clock Gating Control
static const uint32_t RCGCWTIMER            = (uint32_t)(0x65C); // 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control

static const uint32_t PRGPIO                = (uint32_t)(0xA08); // General-Purpose Input-Output Peripheral Ready
static const uint32_t PRSSI                 = (uint32_t)(0xA1C); // Synchronous Serial Interface Peripheral Ready


static const uint32_t NVI_CONTROL_BASE_ADDR = (uint32_t)(0xE000E000);
static const uint32_t EN0                   = (uint32_t)(0x100); // Interrupt 0-31 Set Enable


#endif /* __SYSTEM_CTRL_H__ */
