#ifndef REGISTERS_UART_H_
#define REGISTERS_UART_H_

#include <stdint.h>

typedef struct
{
    volatile uint8_t DATA   : 8;
    volatile uint8_t FE     : 1;
    volatile uint8_t PE     : 1;
    volatile uint8_t BE     : 1;
    volatile uint8_t OE     : 1;
    volatile uint32_t _reserved : 20;
} UARTDR;

typedef union {
    struct
    {
        volatile uint8_t FE     : 1;
        volatile uint8_t PE     : 1;
        volatile uint8_t BE     : 1;
        volatile uint8_t OE     : 1;
        volatile uint32_t _reserved : 28;
    } RSR;

    struct
    {
        volatile uint8_t DATA   : 8;
        volatile uint32_t _reserved : 24;
    } ECR;

} UARTRSR_ECR;

//20 byte buffer

typedef struct {
    volatile uint8_t CTS : 1;
    volatile uint8_t _reserved : 2;
    volatile uint8_t BUSY : 1;
    volatile uint8_t RxFE : 1;
    volatile uint8_t TxFF : 1;
    volatile uint8_t RxFF : 1;
    volatile uint8_t TxFE : 1;
    volatile uint32_t _reserved2 : 24;
} UARTFR;

typedef struct {
    volatile uint8_t ILPDVSR : 8;
    volatile uint32_t _reserved : 24;
} UARTILPR;

typedef struct{
    volatile uint16_t DIVINT : 16;
    volatile uint16_t _reserved : 16;
} UARTIBRD;

typedef struct {
    volatile uint8_t DIVFRAC : 6;
    volatile uint32_t _reserved : 26;
} UARTFBRD;

typedef struct {
    volatile uint8_t BRK : 1;
    volatile uint8_t PEN : 1;
    volatile uint8_t EPS : 1;
    volatile uint8_t STP2 : 1;
    volatile uint8_t FEN  : 1;
    volatile uint8_t WLEN : 2;
    volatile uint8_t SPS  : 1;
    volatile uint32_t _reserved : 24;
} UARTLCRH;

typedef struct {
    volatile uint8_t UARTEN : 1;
    volatile uint8_t SIREN  : 1;
    volatile uint8_t SIRLP  : 1;
    volatile uint8_t SMART  : 1;
    volatile uint8_t EOT    : 1;
    volatile uint8_t HSE    : 1;
    volatile uint8_t _reserved : 1;
    volatile uint8_t LBE    : 1;
    volatile uint8_t TXE    : 1;
    volatile uint8_t RXE    : 1;
    volatile uint8_t _reserved2 : 1;
    volatile uint8_t RTS    : 1;
    volatile uint8_t _reserved3 : 2;
    volatile uint8_t RTSEN  : 1;
    volatile uint8_t CTSEN  : 1;
    volatile uint16_t _reserved4 : 16;
} UARTCTL;

typedef struct {
    volatile uint8_t TXIFLSEL : 3;
    volatile uint8_t RXIFLSEL : 3;
    volatile uint32_t _reserved : 26;
} UARTIFLS;

typedef struct {
    volatile uint8_t _reserved  : 1;
    volatile uint8_t CTSIM      : 1;
    volatile uint8_t _reserved1 : 2;
    volatile uint8_t RXIM       : 1;
    volatile uint8_t TXIM       : 1;
    volatile uint8_t RTIM       : 1;
    volatile uint8_t FEIM       : 1;
    volatile uint8_t PEIM       : 1;
    volatile uint8_t BEIM       : 1;
    volatile uint8_t OEIM       : 1;
    volatile uint8_t _reserved2 : 1;
    volatile uint8_t BITIM9     : 1;
    volatile uint32_t _reserved3: 19;
} UARTIM;

typedef struct {
    volatile uint8_t _reserved  : 1;
    volatile uint8_t CTSRIS     : 1;
    volatile uint8_t _reserved1 : 2;
    volatile uint8_t RXRIS      : 1;
    volatile uint8_t TXRIS      : 1;
    volatile uint8_t RTRIS      : 1;
    volatile uint8_t FERIS      : 1;
    volatile uint8_t PERIS      : 1;
    volatile uint8_t BERIS      : 1;
    volatile uint8_t OERIS      : 1;
    volatile uint8_t _reserved2 : 1;
    volatile uint8_t BITRIS9    : 1;
    volatile uint32_t _reserved3 : 19;
}UARTRIS;

typedef struct {
    volatile uint8_t _reserved  : 1;
    volatile uint8_t CTSMIS     : 1;
    volatile uint8_t _reserved1 : 2;
    volatile uint8_t RXMIS      : 1;
    volatile uint8_t TXMIS      : 1;
    volatile uint8_t RTMIS      : 1;
    volatile uint8_t FEMIS      : 1;
    volatile uint8_t PEMIS      : 1;
    volatile uint8_t BEMIS      : 1;
    volatile uint8_t OEMIS      : 1;
    volatile uint8_t _reserved2 : 1;
    volatile uint8_t BITMIS9    : 1;
    volatile uint32_t _reserved3: 19;
} UARTMIS;

typedef struct {
    volatile uint8_t _reserved      : 1;
    volatile uint8_t CTSMIC         : 1;
    volatile uint8_t _reserved1     : 2;
    volatile uint8_t RXIC           : 1;
    volatile uint8_t TXIC           : 1;
    volatile uint8_t RTIC           : 1;
    volatile uint8_t FEIC           : 1;
    volatile uint8_t PEIC           : 1;
    volatile uint8_t BEIC           : 1;
    volatile uint8_t OEIC           : 1;
    volatile uint8_t _reserved2     : 1;
    volatile uint8_t BITTIC9        : 1;
    volatile uint32_t _reserved3    : 19;
} UARTICR;

typedef struct {
    volatile uint8_t RXDMAE : 1;
    volatile uint8_t TXDMAE : 1;
    volatile uint8_t DMAERR : 1;
    volatile uint32_t _reserved : 29;
} UARTDMACTL;

//92 Byte Buffer

typedef struct {
    volatile uint8_t MASK : 8;
    volatile uint32_t _reserved : 24;
} UART9BITMASK;

//3864 Byte Buffer
typedef struct {
    volatile uint8_t SC : 1;
    volatile uint8_t NB : 1;
    volatile uint32_t _reserved : 30;
} UARTPP;

// 8 Byte Buffer
typedef struct {
    volatile uint8_t CS : 4;
    volatile uint32_t _reserved : 28;
} UARTCC;

typedef struct
{
    UARTDR data;
    UARTRSR_ECR rsr_ecr;
    uint8_t _reserved[16];
    UARTFR fr;
    uint8_t _reserved1[4];
    UARTILPR ilpr;
    UARTIBRD ibrd;
    UARTFBRD fbrd;
    UARTLCRH lcrh;
    UARTCTL ctl;
    UARTIFLS ifls;
    UARTIM im;
    UARTRIS ris;
    UARTMIS mis;
    UARTICR icr;
    UARTDMACTL dmactl;
    uint8_t _reserved2[88];
    UART9BITMASK bitmask9;
    uint8_t _reserved3[3860];
    UARTPP pp;
    uint8_t _reserved4[4];
    UARTCC cc;
} UART_Typedef;

#endif /* REGISTERS_UART_H_ */
