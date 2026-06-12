#ifndef __TM4C123GH6PM_REGISTERS_H__
#define __TM4C123GH6PM_REGISTERS_H__

#include <inttypes.h>



/****************************************************************/
const uint32_t  CM4_PERIPHS_BASE_ADDR = (uint32_t)(0xE000E000);
const uint32_t  EN0                   = (uint32_t)(0x100); // Interrupt 0-31 Set Enable
const uint32_t  EN1                   = (uint32_t)(0x104); // Interrupt 32-63 Set Enable
const uint32_t  EN2                   = (uint32_t)(0x108); // Interrupt 64-95 Set Enable
const uint32_t  EN3                   = (uint32_t)(0x10C); // Interrupt 96-127 Set Enable
const uint32_t  EN4                   = (uint32_t)(0x110); // Interrupt 128-138 Set Enable
const uint32_t  DIS0                  = (uint32_t)(0x180); // Interrupt 0-31 Clear Enable
const uint32_t  DIS1                  = (uint32_t)(0x184); // Interrupt 32-63 Clear Enable
const uint32_t  DIS2                  = (uint32_t)(0x188); // Interrupt 64-95 Clear Enable
const uint32_t  DIS3                  = (uint32_t)(0x18C); // Interrupt 96-127 Clear Enable
const uint32_t  DIS4                  = (uint32_t)(0x190); // Interrupt 128-138 Clear Enable
const uint32_t  CPAC                  = (uint32_t)(0xD88); // Coprocessor Access Control
const uint32_t  FPCC                  = (uint32_t)(0xF34); // Floating-Point Context Control
const uint32_t  FPCA                  = (uint32_t)(0xF38); // Floating-Point Context Address
const uint32_t  FPDSC                 = (uint32_t)(0xF3C); // Floating-Point Default Status Control
/****************************************************************/


/****************************************************************/
const uint32_t  SYS_CONTROL_BASE_ADDR = (uint32_t)(0x400FE000);
const uint32_t  RCC                   = (uint32_t)(0x060); // Run-Mode Clock Configuration
const uint32_t  PPTIMER               = (uint32_t)(0x304); // 16/32-Bit General-Purpose Timer Peripheral Present
const uint32_t  PPGPIO                = (uint32_t)(0x308); // General-Pupose Input/Output Peripheral Present
const uint32_t  PPDMA                 = (uint32_t)(0x30C); // Micro Direct Memory Access Peripheral Present
const uint32_t  PPUART                = (uint32_t)(0x318); // Universal Asynchronous Receiver/Transmitter Peripheral Present
const uint32_t  PPSSI                 = (uint32_t)(0x31C); // Synchronous Serial Interface Peripheral Present
const uint32_t  PPI2C                 = (uint32_t)(0x320); // Inter-Integrated Circuit Peripheral Present
const uint32_t  PPUSB                 = (uint32_t)(0x328); // Universal Serial Bus Peripheral Present
const uint32_t  RCGCTIMER             = (uint32_t)(0x604); // 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control
const uint32_t  RCGCGPIO              = (uint32_t)(0x608); // General-Purpose Input/Output Run Mode Clock Gating Control
const uint32_t  RCGCDMA               = (uint32_t)(0x60C); // Micro Direct Memory Access Run Mode Clock Gating Control
const uint32_t  RCGCUART              = (uint32_t)(0x618); // Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control
const uint32_t  RCGCSSI               = (uint32_t)(0x61C); // Synchronous Serial Interface Run Mode Clock Gating Control
const uint32_t  RCGCUSB               = (uint32_t)(0x628); // Universal Serial Bus Run Mode Clock Gating Control
const uint32_t  RCGCPWM               = (uint32_t)(0x640); // Pulse Width Modulation Run Mode Clock Gating Control
const uint32_t  PRSSI                 = (uint32_t)(0xA1C); // Synchronous Serial Interface Peripheral Ready
/****************************************************************/


/****************************************************************/
const uint32_t  DMASRCENDP            = (uint32_t)(0x000); // Channel Source End Pointer
const uint32_t  DMADSTENDP            = (uint32_t)(0x004); // Channel Destination Address End Pointer
const uint32_t  DMACHCTL              = (uint32_t)(0x008); // Channel Control Word

const uint32_t  UDIR_MEMACC_BASE_ADDR = (uint32_t)(0x400FF000);
const uint32_t  DMACFG                = (uint32_t)(0x004); // Configuration
const uint32_t  DMACTLBASE            = (uint32_t)(0x008); // Channel Control Base Pointer
const uint32_t  DMASWREQ              = (uint32_t)(0x014); // Channel Software Request
const uint32_t  DMAUSEBURSTSET        = (uint32_t)(0x018); // Channel Useburst Set
const uint32_t  DMAUSEBURSTCLR        = (uint32_t)(0x01C); // Channel Useburst Clear
const uint32_t  DMAREQMASKSET         = (uint32_t)(0x020); // Channel Request Mask Set
const uint32_t  DMAREQMASKCLR         = (uint32_t)(0x024); // Channel Request Mask Clear
const uint32_t  DMAENASET             = (uint32_t)(0x028); // Channel Enable Set
const uint32_t  DMAALTSET             = (uint32_t)(0x030); // Channel Primary Alternate Set
const uint32_t  DMAALTCLR             = (uint32_t)(0x034); // Channel Primary Alternate Clear
const uint32_t  DMAPRIOSET            = (uint32_t)(0x038); // Channel Priority Set
const uint32_t  DMAPRIOCLR            = (uint32_t)(0x03C); // Channel Priority Clear
const uint32_t  DMACHMAP0             = (uint32_t)(0x510); // Channel Map Select 0
const uint32_t  DMACHMAP1             = (uint32_t)(0x514); // Channel Map Select 1
const uint32_t  DMACHMAP2             = (uint32_t)(0x518); // Channel Map Select 2
const uint32_t  DMACHMAP3             = (uint32_t)(0x51C); // Channel Map Select 3
/****************************************************************/


/****************************************************************/
const uint32_t  GPIO_PORTAP_BASE_ADDR = (uint32_t)(0x40004000);
const uint32_t  GPIO_PORTAH_BASE_ADDR = (uint32_t)(0x40058000);
const uint32_t  GPIO_PORTBP_BASE_ADDR = (uint32_t)(0x40005000);
const uint32_t  GPIO_PORTBH_BASE_ADDR = (uint32_t)(0x40059000);
const uint32_t  GPIO_PORTCP_BASE_ADDR = (uint32_t)(0x40006000);
const uint32_t  GPIO_PORTCH_BASE_ADDR = (uint32_t)(0x4005A000);
const uint32_t  GPIO_PORTDP_BASE_ADDR = (uint32_t)(0x40007000);
const uint32_t  GPIO_PORTDH_BASE_ADDR = (uint32_t)(0x4005B000);
const uint32_t  GPIO_PORTEP_BASE_ADDR = (uint32_t)(0x40024000);
const uint32_t  GPIO_PORTEH_BASE_ADDR = (uint32_t)(0x4005C000);
const uint32_t  GPIO_PORTFP_BASE_ADDR = (uint32_t)(0x40025000);
const uint32_t  GPIO_PORTFH_BASE_ADDR = (uint32_t)(0x4005D000);
const uint32_t  GPIODIR               = (uint32_t)(0x400); // Direction
const uint32_t  GPIOIS                = (uint32_t)(0x404); // Interrupt Sense
const uint32_t  GPIOIBE               = (uint32_t)(0x408); // Interrupt Both Edges
const uint32_t  GPIOIEV               = (uint32_t)(0x40C); // Interrupt Event
const uint32_t  GPIOIM                = (uint32_t)(0x410); // Interrupt Mask
const uint32_t  GPIORIS               = (uint32_t)(0x414); // Raw Interrupt Status
const uint32_t  GPIOICR               = (uint32_t)(0x41C); // Interrupt Clear
const uint32_t  GPIOAFSEL             = (uint32_t)(0x420); // Alternate Function Select
const uint32_t  GPIOPUR               = (uint32_t)(0x510); // Pull-Up Select
const uint32_t  GPIOPDR               = (uint32_t)(0x514); // Pull-Down Select
const uint32_t  GPIODEN               = (uint32_t)(0x51C); // Digital Enable
const uint32_t  GPIOPCTL              = (uint32_t)(0x52C); // Port Control
const uint32_t  GPIODMACTL            = (uint32_t)(0x534); // DMA Control
/****************************************************************/


/****************************************************************/
const uint32_t  GPTM_TIMER0_BASE_ADDR = (uint32_t)(0x40030000);
const uint32_t  GPTM_TIMER1_BASE_ADDR = (uint32_t)(0x40031000);
const uint32_t  GPTM_TIMER2_BASE_ADDR = (uint32_t)(0x40032000);
const uint32_t  GPTM_TIMER3_BASE_ADDR = (uint32_t)(0x40033000);
const uint32_t  GPTM_TIMER4_BASE_ADDR = (uint32_t)(0x40034000);
const uint32_t  GPTM_TIMER5_BASE_ADDR = (uint32_t)(0x40035000);
const uint32_t  GPTM_WIDET0_BASE_ADDR = (uint32_t)(0x40036000);
const uint32_t  GPTM_WIDET1_BASE_ADDR = (uint32_t)(0x40037000);
const uint32_t  GPTM_WIDET2_BASE_ADDR = (uint32_t)(0x4004C000);
const uint32_t  GPTM_WIDET3_BASE_ADDR = (uint32_t)(0x4004D000);
const uint32_t  GPTM_WIDET4_BASE_ADDR = (uint32_t)(0x4004E000);
const uint32_t  GPTM_WIDET5_BASE_ADDR = (uint32_t)(0x4004F000);
const uint32_t  GPTMCFG               = (uint32_t)(0x000); // Configuration
const uint32_t  GPTMTAMR              = (uint32_t)(0x004); // Timer A Mode
const uint32_t  GPTMTBMR              = (uint32_t)(0x008); // Timer B Mode
const uint32_t  GPTMCTL               = (uint32_t)(0x00C); // Control
const uint32_t  GPTMIMR               = (uint32_t)(0x018); // Interrump Mask
const uint32_t  GPTMICR               = (uint32_t)(0x024); // Interrupt Clear
const uint32_t  GPTMTAILR             = (uint32_t)(0x028); // Timer A Interval Load
const uint32_t  GPTMTBILR             = (uint32_t)(0x02C); // Timer B Interval Load
const uint32_t  GPTMTAMATCHR          = (uint32_t)(0x030); // Timer A Match
const uint32_t  GPTMTBMATCHR          = (uint32_t)(0x034); // Timer B Match
const uint32_t  GPTMTAPR              = (uint32_t)(0x038); // Timer A Prescale
const uint32_t  GPTMTBPR              = (uint32_t)(0x03C); // Timer B Prescale
const uint32_t  GPTMTAR               = (uint32_t)(0x048); // Timer A
const uint32_t  GPTMTBR               = (uint32_t)(0x04C); // Timer B
/****************************************************************/



/****************************************************************/
const uint32_t  UART_MODUL0_BASE_ADDR = (uint32_t)(0x4000C000);
const uint32_t  UARTDR                = (uint32_t)(0x000); // Data
const uint32_t  UARTIBRD              = (uint32_t)(0x024); // Integer Baud-Rate Divisor
const uint32_t  UARTFBRD              = (uint32_t)(0x028); // Fractional Baud-Rate Divisor
const uint32_t  UARTLCRH              = (uint32_t)(0x02C); // Line Control
const uint32_t  UARTCTL               = (uint32_t)(0x030); // Control
const uint32_t  UARTCC                = (uint32_t)(0xFC8); // Clock Configuration
/****************************************************************/



/****************************************************************/
const uint32_t  SYNC_SIMOD0_BASE_ADDR = (uint32_t)(0x40008000);
const uint32_t  SYNC_SIMOD1_BASE_ADDR = (uint32_t)(0x40009000);
const uint32_t  SYNC_SIMOD2_BASE_ADDR = (uint32_t)(0x4000A000);
const uint32_t  SYNC_SIMOD3_BASE_ADDR = (uint32_t)(0x4000B000);
const uint32_t  SSICR0                = (uint32_t)(0x000); // SSI Control 0
const uint32_t  SSICR1                = (uint32_t)(0x004); // SSI Control 1
const uint32_t  SSIDR                 = (uint32_t)(0x008); // SSI Data
const uint32_t  SSISR                 = (uint32_t)(0x00C); // SSI Status
const uint32_t  SSICPSR               = (uint32_t)(0x010); // SSI Clock Peripheral
const uint32_t  SSIIM                 = (uint32_t)(0x014); // SSI Interrupt Mask
const uint32_t  SSIRIS                = (uint32_t)(0x018); // SSI Raw Interrupt Status
const uint32_t  SSIMIS                = (uint32_t)(0x01C); // SSI Masked Interrupt Status
const uint32_t  SSIICR                = (uint32_t)(0x020); // SSI Interrupt Clear
const uint32_t  SSIDMACTL             = (uint32_t)(0x024); // SSI DMA Control
const uint32_t  SSICC                 = (uint32_t)(0xFC8); // SSI Clock Configuration
const uint32_t  SSIPeriphID4          = (uint32_t)(0xFD0); // Peripheral Identification 4
const uint32_t  SSIPeriphID5          = (uint32_t)(0xFD4); // Peripheral Identification 5
const uint32_t  SSIPeriphID6          = (uint32_t)(0xFD8); // Peripheral Identification 6
const uint32_t  SSIPeriphID7          = (uint32_t)(0xFDC); // Peripheral Identification 7
const uint32_t  SSIPeriphID0          = (uint32_t)(0xFE0); // Peripheral Identification 0
const uint32_t  SSIPeriphID1          = (uint32_t)(0xFE4); // Peripheral Identification 1
const uint32_t  SSIPeriphID2          = (uint32_t)(0xFE8); // Peripheral Identification 2
const uint32_t  SSIPeriphID3          = (uint32_t)(0xFEC); // Peripheral Identification 3
const uint32_t  SSIPCellID0           = (uint32_t)(0xFF0); // PrimeCell Identification 0
const uint32_t  SSIPCellID1           = (uint32_t)(0xFF4); // PrimeCell Identification 1
const uint32_t  SSIPCellID2           = (uint32_t)(0xFF8); // PrimeCell Identification 2
const uint32_t  SSIPCellID3           = (uint32_t)(0xFFC); // PrimeCell Identification 3
/****************************************************************/



/****************************************************************/
const uint32_t  USB_CONTROL_BASE_ADDR = (uint32_t)(0x40050000);
const uint32_t  USBPOWER              = (uint32_t)(0x001); // Power
const uint32_t  USBTXIS               = (uint32_t)(0x002); // Transmit Interrupt Status
const uint32_t  USBRXIS               = (uint32_t)(0x004); // Receive Interrupt Status
const uint32_t  USBTXIE               = (uint32_t)(0x006); // Transmit Interrupt Enable
const uint32_t  USBRXIE               = (uint32_t)(0x008); // Receive Interrupt Enable
const uint32_t  USBIS                 = (uint32_t)(0x00A); // General Interrupt Status
const uint32_t  USBIE                 = (uint32_t)(0x00B); // General Interrupt Enable
const uint32_t  USBFRAME              = (uint32_t)(0x00C); // Frame Value
const uint32_t  USBEPIDX              = (uint32_t)(0x00E); // Endpoint Index
const uint32_t  USBTEST               = (uint32_t)(0x00F); // Test Mode

const uint32_t  USBFIFO0              = (uint32_t)(0x020); // FIFO Endpoint 0
const uint32_t  USBFIFO1              = (uint32_t)(0x024); // FIFO Endpoint 1
const uint32_t  USBFIFO2              = (uint32_t)(0x028); // FIFO Endpoint 2
const uint32_t  USBFIFO3              = (uint32_t)(0x02C); // FIFO Endpoint 3
const uint32_t  USBFIFO4              = (uint32_t)(0x030); // FIFO Endpoint 4
const uint32_t  USBFIFO5              = (uint32_t)(0x034); // FIFO Endpoint 5
const uint32_t  USBFIFO6              = (uint32_t)(0x038); // FIFO Endpoint 6
const uint32_t  USBFIFO7              = (uint32_t)(0x03C); // FIFO Endpoint 7

const uint32_t  USBDEVCTL             = (uint32_t)(0x060); // Device Control
const uint32_t  USBTXFIFOSZ           = (uint32_t)(0x062); // Transmit Dynamic FIFO Sizing
const uint32_t  USBRXFIFOSZ           = (uint32_t)(0x063); // Receive Dynamic FIFO Sizing
const uint32_t  USBTXFIFOADD          = (uint32_t)(0x064); // Transmit FIFO Start Address
const uint32_t  USBRXFIFOADD          = (uint32_t)(0x066); // Receive FIFO Start Address
const uint32_t  USBCONTIM             = (uint32_t)(0x07A); // Connect Timing
const uint32_t  USBVPLEN              = (uint32_t)(0x07B); // OTG VBUS Pulse Timing
const uint32_t  USBFSEOF              = (uint32_t)(0x07D); // Full-Speed Last Transaction to End of Frame Timing
const uint32_t  USBLSEOF              = (uint32_t)(0x07E); // Low-Speed Last Transaction to End of Frame Timing

const uint32_t  USBTXFUNCADDR0        = (uint32_t)(0x080); // Transmit Functional Address Endpoint 0
const uint32_t  USBTXHUBADDR0         = (uint32_t)(0x082); // Transmit Hub Address Endpoint 0
const uint32_t  USBTXHUBPORT0         = (uint32_t)(0x083); // Transmit Hub Port Endpoint 0

const uint32_t  USBTXFUNCADDR1        = (uint32_t)(0x088); // Transmit Functional Address Endpoint 1
const uint32_t  USBTXHUBADDR1         = (uint32_t)(0x08A); // Transmit Hub Address Endpoint 1
const uint32_t  USBTXHUBPORT1         = (uint32_t)(0x08B); // Transmit Hub Port Endpoint 1
const uint32_t  USBRXFUNCADDR1        = (uint32_t)(0x08C); // Receive Functional Address Endpoint 1
const uint32_t  USBRXHUBADDR1         = (uint32_t)(0x08E); // Receive Hub Address Endpoint 1
const uint32_t  USBRXHUBPORT1         = (uint32_t)(0x08F); // Receive Hub Port 1

const uint32_t  USBTXFUNCADDR2        = (uint32_t)(0x090); // Transmit Functional Address Endpoint 2
const uint32_t  USBTXHUBADDR2         = (uint32_t)(0x092); // Transmit Hub Address Endpoint 2
const uint32_t  USBTXHUBPORT2         = (uint32_t)(0x093); // Transmit Hub Port Endpoint 2
const uint32_t  USBRXFUNCADDR2        = (uint32_t)(0x094); // Receive Functional Address Endpoint 2
const uint32_t  USBRXHUBADDR2         = (uint32_t)(0x096); // Receive Hub Address Endpoint 2
const uint32_t  USBRXHUBPORT2         = (uint32_t)(0x097); // Receive Hub Port 2

const uint32_t  USBTXFUNCADDR3        = (uint32_t)(0x098); // Transmit Functional Address Endpoint 3
const uint32_t  USBTXHUBADDR3         = (uint32_t)(0x09A); // Transmit Hub Address Endpoint 3
const uint32_t  USBTXHUBPORT3         = (uint32_t)(0x09B); // Transmit Hub Port Endpoint 3
const uint32_t  USBRXFUNCADDR3        = (uint32_t)(0x09C); // Receive Functional Address Endpoint 3
const uint32_t  USBRXHUBADDR3         = (uint32_t)(0x09E); // Receive Hub Address Endpoint 3
const uint32_t  USBRXHUBPORT3         = (uint32_t)(0x09F); // Receive Hub Port 3

const uint32_t  USBTXFUNCADDR4        = (uint32_t)(0x0A0); // Transmit Functional Address Endpoint 4
const uint32_t  USBTXHUBADDR4         = (uint32_t)(0x0A2); // Transmit Hub Address Endpoint 4
const uint32_t  USBTXHUBPORT4         = (uint32_t)(0x0A3); // Transmit Hub Port Endpoint 4
const uint32_t  USBRXFUNCADDR4        = (uint32_t)(0x0A4); // Receive Functional Address Endpoint 4
const uint32_t  USBRXHUBADDR4         = (uint32_t)(0x0A6); // Receive Hub Address Endpoint 4
const uint32_t  USBRXHUBPORT4         = (uint32_t)(0x0A7); // Receive Hub Port 4

const uint32_t  USBTXFUNCADDR5        = (uint32_t)(0x0A8); // Transmit Functional Address Endpoint 5
const uint32_t  USBTXHUBADDR5         = (uint32_t)(0x0AA); // Transmit Hub Address Endpoint 5
const uint32_t  USBTXHUBPORT5         = (uint32_t)(0x0AB); // Transmit Hub Port Endpoint 5
const uint32_t  USBRXFUNCADDR5        = (uint32_t)(0x0AC); // Receive Functional Address Endpoint 5
const uint32_t  USBRXHUBADDR5         = (uint32_t)(0x0AE); // Receive Hub Address Endpoint 5
const uint32_t  USBRXHUBPORT5         = (uint32_t)(0x0AF); // Receive Hub Port 5

const uint32_t  USBTXFUNCADDR6        = (uint32_t)(0x0B0); // Transmit Functional Address Endpoint 6
const uint32_t  USBTXHUBADDR6         = (uint32_t)(0x0B2); // Transmit Hub Address Endpoint 6
const uint32_t  USBTXHUBPORT6         = (uint32_t)(0x0B3); // Transmit Hub Port Endpoint 6
const uint32_t  USBRXFUNCADDR6        = (uint32_t)(0x0B4); // Receive Functional Address Endpoint 6
const uint32_t  USBRXHUBADDR6         = (uint32_t)(0x0B6); // Receive Hub Address Endpoint 6
const uint32_t  USBRXHUBPORT6         = (uint32_t)(0x0B7); // Receive Hub Port 6

const uint32_t  USBTXFUNCADDR7        = (uint32_t)(0x0B8); // Transmit Functional Address Endpoint 7
const uint32_t  USBTXHUBADDR7         = (uint32_t)(0x0BA); // Transmit Hub Address Endpoint 7
const uint32_t  USBTXHUBPORT7         = (uint32_t)(0x0BB); // Transmit Hub Port Endpoint 7
const uint32_t  USBRXFUNCADDR7        = (uint32_t)(0x0BC); // Receive Functional Address Endpoint 7
const uint32_t  USBRXHUBADDR7         = (uint32_t)(0x0BE); // Receive Hub Address Endpoint 7
const uint32_t  USBRXHUBPORT7         = (uint32_t)(0x0BF); // Receive Hub Port 7

const uint32_t  USBCSRL0              = (uint32_t)(0x102); // Control and Status Endpoint 0 Low
const uint32_t  USBCSRH0              = (uint32_t)(0x103); // Control and Status Endpoint 0 High
const uint32_t  USBCOUNT0             = (uint32_t)(0x108); // Receive Byte Count Endpoint 0
const uint32_t  USBTYPE0              = (uint32_t)(0x10A); // Type Endpoint 0
const uint32_t  USBNAKLMT             = (uint32_t)(0x10B); // NAK Limit

const uint32_t  USBTXMAXP1            = (uint32_t)(0x110); // Maximum Transmit Data Endpoint 1
const uint32_t  USBTXCSRL1            = (uint32_t)(0x112); // Transmit Control and Status Endpoint 1 Low
const uint32_t  USBTXCSRH1            = (uint32_t)(0x113); // Transmit Control and Status Endpoint 1 High
const uint32_t  USBRXMAXP1            = (uint32_t)(0x114); // Maximum Receive Data Endpoint 1
const uint32_t  USBRXCSRL1            = (uint32_t)(0x116); // Receive Control and Status Endpoint 1 Low
const uint32_t  USBRXCSRH1            = (uint32_t)(0x117); // Receive Control and Status Endpoint 1 High
const uint32_t  USBRXCOUNT1           = (uint32_t)(0x118); // Receive Byte Count Endpoint 1
const uint32_t  USBTXTYPE1            = (uint32_t)(0x11A); // Host Transmit Configure Type Endpoint 1
const uint32_t  USBTXINTERVAL1        = (uint32_t)(0x11B); // Host Transmit Interval Endpoint 1
const uint32_t  USBRXTYPE1            = (uint32_t)(0x11C); // Host Configure Receive Type Endpoint 1
const uint32_t  USBRXINTERVAL1        = (uint32_t)(0x11D); // Host Receive Polling Interval Endpoint 1

const uint32_t  USBTXMAXP2            = (uint32_t)(0x120); // Maximum Transmit Data Endpoint 2
const uint32_t  USBTXCSRL2            = (uint32_t)(0x122); // Transmit Control and Status Endpoint 2 Low
const uint32_t  USBTXCSRH2            = (uint32_t)(0x123); // Transmit Control and Status Endpoint 2 High
const uint32_t  USBRXMAXP2            = (uint32_t)(0x124); // Maximum Receive Data Endpoint 2
const uint32_t  USBRXCSRL2            = (uint32_t)(0x126); // Receive Control and Status Endpoint 2 Low
const uint32_t  USBRXCSRH2            = (uint32_t)(0x127); // Receive Control and Status Endpoint 2 High
const uint32_t  USBRXCOUNT2           = (uint32_t)(0x128); // Receive Byte Count Endpoint 2
const uint32_t  USBTXTYPE2            = (uint32_t)(0x12A); // Host Transmit Configure Type Endpoint 2
const uint32_t  USBTXINTERVAL2        = (uint32_t)(0x12B); // Host Transmit Interval Endpoint 2
const uint32_t  USBRXTYPE2            = (uint32_t)(0x12C); // Host Configure Receive Type Endpoint 2
const uint32_t  USBRXINTERVAL2        = (uint32_t)(0x12D); // Host Receive Polling Interval Endpoint 2

const uint32_t  USBTXMAXP3            = (uint32_t)(0x130); // Maximum Transmit Data Endpoint 3
const uint32_t  USBTXCSRL3            = (uint32_t)(0x132); // Transmit Control and Status Endpoint 3 Low
const uint32_t  USBTXCSRH3            = (uint32_t)(0x133); // Transmit Control and Status Endpoint 3 High
const uint32_t  USBRXMAXP3            = (uint32_t)(0x134); // Maximum Receive Data Endpoint 3
const uint32_t  USBRXCSRL3            = (uint32_t)(0x136); // Receive Control and Status Endpoint 3 Low
const uint32_t  USBRXCSRH3            = (uint32_t)(0x137); // Receive Control and Status Endpoint 3 High
const uint32_t  USBRXCOUNT3           = (uint32_t)(0x138); // Receive Byte Count Endpoint 3
const uint32_t  USBTXTYPE3            = (uint32_t)(0x13A); // Host Transmit Configure Type Endpoint 3
const uint32_t  USBTXINTERVAL3        = (uint32_t)(0x13B); // Host Transmit Interval Endpoint 3
const uint32_t  USBRXTYPE3            = (uint32_t)(0x13C); // Host Configure Receive Type Endpoint 3
const uint32_t  USBRXINTERVAL3        = (uint32_t)(0x13D); // Host Receive Polling Interval Endpoint 3

const uint32_t  USBTXMAXP4            = (uint32_t)(0x140); // Maximum Transmit Data Endpoint 4
const uint32_t  USBTXCSRL4            = (uint32_t)(0x142); // Transmit Control and Status Endpoint 4 Low
const uint32_t  USBTXCSRH4            = (uint32_t)(0x143); // Transmit Control and Status Endpoint 4 High
const uint32_t  USBRXMAXP4            = (uint32_t)(0x144); // Maximum Receive Data Endpoint 4
const uint32_t  USBRXCSRL4            = (uint32_t)(0x146); // Receive Control and Status Endpoint 4 Low
const uint32_t  USBRXCSRH4            = (uint32_t)(0x147); // Receive Control and Status Endpoint 4 High
const uint32_t  USBRXCOUNT4           = (uint32_t)(0x148); // Receive Byte Count Endpoint 4
const uint32_t  USBTXTYPE4            = (uint32_t)(0x14A); // Host Transmit Configure Type Endpoint 4
const uint32_t  USBTXINTERVAL4        = (uint32_t)(0x14B); // Host Transmit Interval Endpoint 4
const uint32_t  USBRXTYPE4            = (uint32_t)(0x14C); // Host Configure Receive Type Endpoint 4
const uint32_t  USBRXINTERVAL4        = (uint32_t)(0x14D); // Host Receive Polling Interval Endpoint 4

const uint32_t  USBTXMAXP5            = (uint32_t)(0x150); // Maximum Transmit Data Endpoint 5
const uint32_t  USBTXCSRL5            = (uint32_t)(0x152); // Transmit Control and Status Endpoint 5 Low
const uint32_t  USBTXCSRH5            = (uint32_t)(0x153); // Transmit Control and Status Endpoint 5 High
const uint32_t  USBRXMAXP5            = (uint32_t)(0x154); // Maximum Receive Data Endpoint 5
const uint32_t  USBRXCSRL5            = (uint32_t)(0x156); // Receive Control and Status Endpoint 5 Low
const uint32_t  USBRXCSRH5            = (uint32_t)(0x157); // Receive Control and Status Endpoint 5 High
const uint32_t  USBRXCOUNT5           = (uint32_t)(0x158); // Receive Byte Count Endpoint 5
const uint32_t  USBTXTYPE5            = (uint32_t)(0x15A); // Host Transmit Configure Type Endpoint 5
const uint32_t  USBTXINTERVAL5        = (uint32_t)(0x15B); // Host Transmit Interval Endpoint 5
const uint32_t  USBRXTYPE5            = (uint32_t)(0x15C); // Host Configure Receive Type Endpoint 5
const uint32_t  USBRXINTERVAL5        = (uint32_t)(0x15D); // Host Receive Polling Interval Endpoint 5

const uint32_t  USBTXMAXP6            = (uint32_t)(0x160); // Maximum Transmit Data Endpoint 6
const uint32_t  USBTXCSRL6            = (uint32_t)(0x162); // Transmit Control and Status Endpoint 6 Low
const uint32_t  USBTXCSRH6            = (uint32_t)(0x163); // Transmit Control and Status Endpoint 6 High
const uint32_t  USBRXMAXP6            = (uint32_t)(0x164); // Maximum Receive Data Endpoint 6
const uint32_t  USBRXCSRL6            = (uint32_t)(0x166); // Receive Control and Status Endpoint 6 Low
const uint32_t  USBRXCSRH6            = (uint32_t)(0x167); // Receive Control and Status Endpoint 6 High
const uint32_t  USBRXCOUNT6           = (uint32_t)(0x168); // Receive Byte Count Endpoint 6
const uint32_t  USBTXTYPE6            = (uint32_t)(0x16A); // Host Transmit Configure Type Endpoint 6
const uint32_t  USBTXINTERVAL6        = (uint32_t)(0x16B); // Host Transmit Interval Endpoint 6
const uint32_t  USBRXTYPE6            = (uint32_t)(0x16C); // Host Configure Receive Type Endpoint 6
const uint32_t  USBRXINTERVAL6        = (uint32_t)(0x16D); // Host Receive Polling Interval Endpoint 6

const uint32_t  USBTXMAXP7            = (uint32_t)(0x170); // Maximum Transmit Data Endpoint 7
const uint32_t  USBTXCSRL7            = (uint32_t)(0x172); // Transmit Control and Status Endpoint 7 Low
const uint32_t  USBTXCSRH7            = (uint32_t)(0x173); // Transmit Control and Status Endpoint 7 High
const uint32_t  USBRXMAXP7            = (uint32_t)(0x174); // Maximum Receive Data Endpoint 7
const uint32_t  USBRXCSRL7            = (uint32_t)(0x176); // Receive Control and Status Endpoint 7 Low
const uint32_t  USBRXCSRH7            = (uint32_t)(0x177); // Receive Control and Status Endpoint 7 High
const uint32_t  USBRXCOUNT7           = (uint32_t)(0x178); // Receive Byte Count Endpoint 7
const uint32_t  USBTXTYPE7            = (uint32_t)(0x17A); // Host Transmit Configure Type Endpoint 7
const uint32_t  USBTXINTERVAL7        = (uint32_t)(0x17B); // Host Transmit Interval Endpoint 7
const uint32_t  USBRXTYPE7            = (uint32_t)(0x17C); // Host Configure Receive Type Endpoint 7
const uint32_t  USBRXINTERVAL7        = (uint32_t)(0x17D); // Host Receive Polling Interval Endpoint 7

const uint32_t  USBRQPKTCOUNT1        = (uint32_t)(0x304); // Request Packet Count in Block Transfer Endpoint 1
const uint32_t  USBRQPKTCOUNT2        = (uint32_t)(0x308); // Request Packet Count in Block Transfer Endpoint 2
const uint32_t  USBRQPKTCOUNT3        = (uint32_t)(0x30C); // Request Packet Count in Block Transfer Endpoint 3
const uint32_t  USBRQPKTCOUNT4        = (uint32_t)(0x310); // Request Packet Count in Block Transfer Endpoint 4
const uint32_t  USBRQPKTCOUNT5        = (uint32_t)(0x314); // Request Packet Count in Block Transfer Endpoint 5
const uint32_t  USBRQPKTCOUNT6        = (uint32_t)(0x318); // Request Packet Count in Block Transfer Endpoint 6
const uint32_t  USBRQPKTCOUNT7        = (uint32_t)(0x31C); // Request Packet Count in Block Transfer Endpoint 7

const uint32_t  USBRXDPKTBUFDIS       = (uint32_t)(0x340); // Receive Double Packet Buffer Disable
const uint32_t  USBTXDPKTBUFDIS       = (uint32_t)(0x342); // Transmit Double Packet Buffer Disable
const uint32_t  USBEPC                = (uint32_t)(0x400); // External Power Control
const uint32_t  USBEPCRIS             = (uint32_t)(0x404); // External Power Control Raw Interrupt Status
const uint32_t  USBPECIM              = (uint32_t)(0x408); // External Power Control Interrupt Mask
const uint32_t  USBEPCISC             = (uint32_t)(0x40C); // External Power Control Interrupt Status and Clear
const uint32_t  USBDRRIS              = (uint32_t)(0x410); // Device RESUME Raw Interrupt Status
const uint32_t  USBDRIM               = (uint32_t)(0x414); // Device RESUME Interrupt Mask
const uint32_t  USBDRISC              = (uint32_t)(0x418); // Device RESUME Interrupt Status and Clear
const uint32_t  USBGPCS               = (uint32_t)(0x41C); // General-Purpose Control and Status
const uint32_t  USBVDC                = (uint32_t)(0x430); // VBUS Droop Control
const uint32_t  USBVDCRIS             = (uint32_t)(0x434); // VBUS Droop Control Raw Interrupt Status
const uint32_t  USBVDCIM              = (uint32_t)(0x438); // VBUS Droop Control Raw Interrupt Mask
const uint32_t  USBVDCISC             = (uint32_t)(0x43C); // VBUS Droop Control Interrupt Status and Clear
const uint32_t  USBIDVRIS             = (uint32_t)(0x444); // ID Valid Detect Draw Interrupt Status
const uint32_t  USBIDVIM              = (uint32_t)(0x448); // ID Valid Detect Interrupt Mask
const uint32_t  USBIDVISC             = (uint32_t)(0x44C); // ID Valid Detect Interrupt Status and Clear
const uint32_t  USBDMASEL             = (uint32_t)(0x450); // DMA Select
const uint32_t  USBPP                 = (uint32_t)(0xFC0); // Peripheral Properties
/****************************************************************/


#endif /* __TM4C123GH6PM_REGISTERS_H__ */
