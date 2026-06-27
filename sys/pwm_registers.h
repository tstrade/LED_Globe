#ifndef __PWM_REGISTERS_H__
#define __PWM_REGISTERS_H__

#include <stdint.h>

typedef enum
{
    PWM0 = 0x0,
    PWM1 = 0x1,
    PWM2 = 0x2,
    PWM3 = 0x3
} PWM_GENERATORS;

typedef struct
{
    volatile uint8_t GLOBALSYNC0 : 1;
    volatile uint8_t GLOBALSYNC1 : 1;
    volatile uint8_t GLOBALSYNC2 : 1;
    volatile uint8_t GLOBALSYNC3 : 1;
    volatile uint32_t _reserved : 28;
} PWMCTL;

typedef struct
{
    volatile uint8_t SYNC0 : 1;
    volatile uint8_t SYNC1 : 1;
    volatile uint8_t SYNC2 : 1;
    volatile uint8_t SYNC3 : 1;
    volatile uint32_t _reserved : 28;
} PWMSYNC;

typedef struct
{
    volatile uint8_t PWM0EN : 1;
    volatile uint8_t PWM1EN : 1;
    volatile uint8_t PWM2EN : 1;
    volatile uint8_t PWM3EN : 1;
    volatile uint8_t PWM4EN : 1;
    volatile uint8_t PWM5EN : 1;
    volatile uint8_t PWM6EN : 1;
    volatile uint8_t PWM7EN : 1;
} PWMENABLE;

typedef struct
{
    volatile uint8_t PWM0INV : 1;
    volatile uint8_t PWM1INV : 1;
    volatile uint8_t PWM2INV : 1;
    volatile uint8_t PWM3INV : 1;
    volatile uint8_t PWM4INV : 1;
    volatile uint8_t PWM5INV : 1;
    volatile uint8_t PWM6INV : 1;
    volatile uint8_t PWM7INC : 1;
} PWMINVERT;

typedef struct
{
    volatile uint8_t FAULT0 : 1;
    volatile uint8_t FAULT1 : 1;
    volatile uint8_t FAULT2 : 1;
    volatile uint8_t FAULT3 : 1;
    volatile uint8_t FAULT4 : 1;
    volatile uint8_t FAULT5 : 1;
    volatile uint8_t FAULT6 : 1;
    volatile uint8_t FAULT7 : 1;
} PWMFAULT;

typedef struct
{
    volatile uint8_t INTPWM0 : 1;
    volatile uint8_t INTPWM1 : 1;
    volatile uint8_t INTPWM2 : 1;
    volatile uint8_t INTPWM3 : 1;
    volatile uint16_t _reserved_1 : 12;
    volatile uint8_t INTFAULT0 : 1;
    volatile uint8_t INTFAULT1 : 1;
    volatile uint8_t _reserved_2 : 14;
} PWMINTEN;

typedef struct
{
    volatile uint8_t INTPWM0 : 1;
    volatile uint8_t INTPWM1 : 1;
    volatile uint8_t INTPWM2 : 1;
    volatile uint8_t INTPWM3 : 1;
    volatile uint16_t _reserved_1 : 12;
    volatile uint8_t INTFAULT0 : 1;
    volatile uint8_t INTFAULT1 : 1;
    volatile uint8_t _reserved_2 : 14;
} PWMRIS;

typedef struct
{
    volatile uint8_t INTPWM0 : 1;
    volatile uint8_t INTPWM1 : 1;
    volatile uint8_t INTPWM2 : 1;
    volatile uint8_t INTPWM3 : 1;
    volatile uint16_t _reserved_1 : 12;
    volatile uint8_t INTFAULT0 : 1;
    volatile uint8_t INTFAULT1 : 1;
    volatile uint8_t _reserved_2 : 14;
} PWMISC;

typedef struct
{
    volatile uint8_t FAULT0 : 1;
    volatile uint8_t FAULT1 : 1;
    volatile uint32_t _reserved : 30;
} PWMSTATUS;

typedef struct
{
    volatile uint8_t PWM0 : 1;
    volatile uint8_t PWM1 : 1;
    volatile uint8_t PWM2 : 1;
    volatile uint8_t PWM3 : 1;
    volatile uint8_t PWM4 : 1;
    volatile uint8_t PWM5 : 1;
    volatile uint8_t PWM6 : 1;
    volatile uint8_t PWM7 : 1;
    volatile uint8_t _reserved : 24;
} PWMFAULTVAL;

typedef struct
{
    volatile uint8_t ENUPD0 : 2;
    volatile uint8_t ENUPD1 : 2;
    volatile uint8_t ENUPD2 : 2;
    volatile uint8_t ENUPD3 : 2;
    volatile uint8_t ENUPD4 : 2;
    volatile uint8_t ENUPD5 : 2;
    volatile uint8_t ENUPD6 : 2;
    volatile uint8_t ENUPD7 : 2;
    volatile uint16_t _reserved;
} PWMENUPD;

typedef struct
{
    volatile uint8_t ENABLE : 1;
    volatile uint8_t MODE : 1;
    volatile uint8_t DEBUG : 1;
    volatile uint8_t LOADUPD : 1;
    volatile uint8_t CMPAUPD : 1;
    volatile uint8_t CMPBUPD : 1;
    volatile uint8_t GENAUPD : 2;
    volatile uint8_t GENBUPD : 2;
    volatile uint8_t DBCTLUPD : 2;
    volatile uint8_t DBRISEUPD : 2;
    volatile uint8_t DBFALLUPD : 2;
    volatile uint8_t FLTSRC : 1;
    volatile uint8_t MINFLTPER : 1;
    volatile uint8_t LATCH : 1;
    volatile uint16_t _reserved : 13;
} PWMnCTL;

typedef struct
{
    volatile uint8_t INTCNTZERO : 1;
    volatile uint8_t INTCNTLOAD : 1;
    volatile uint8_t INTCMPAU : 1;
    volatile uint8_t INTCMPAD : 1;
    volatile uint8_t INTCMPBU : 1;
    volatile uint8_t INTCMPBD : 1;
    volatile uint8_t _reserved_1 : 2;
    volatile uint8_t TRCNTZERO : 1;
    volatile uint8_t TRCNTLOAD : 1;
    volatile uint8_t TRCMPAU : 1;
    volatile uint8_t TRCMPAD : 1;
    volatile uint8_t TRCMPBU : 1;
    volatile uint8_t TRCMPBD : 1;
    volatile uint32_t _reserved_2 : 18;
} PWMnINTEN;

typedef struct
{
    volatile uint8_t INTCNTZERO : 1;
    volatile uint8_t INTCNTLOAD : 1;
    volatile uint8_t INTCMPAU : 1;
    volatile uint8_t INTCMPAD : 1;
    volatile uint8_t INTCMPBU : 1;
    volatile uint8_t INTCMPBD : 1;
    volatile uint32_t _reserved : 26;
} PWMnRIS;

typedef struct
{
    volatile uint8_t INTCNTZERO : 1;
    volatile uint8_t INTCNTLOAD : 1;
    volatile uint8_t INTCMPAU : 1;
    volatile uint8_t INTCMPAD : 1;
    volatile uint8_t INTCMPBU : 1;
    volatile uint8_t INTCMPBD : 1;
    volatile uint32_t _reserved : 26;
} PWMnISC;

typedef struct
{
    volatile uint16_t LOAD;
    volatile uint16_t _reserved;
} PWMnLOAD;

typedef struct
{
    volatile uint16_t COUNT;
    volatile uint16_t _reserved;
} PWMnCOUNT;

typedef struct
{
    volatile uint16_t COMPA;
    volatile uint16_t _reserved;
} PWMnCMPA;

typedef struct
{
    volatile uint16_t COMPB;
    volatile uint16_t _reserved;
} PWMnCMPB;

typedef struct
{
    volatile uint8_t ACTZERO : 2;
    volatile uint8_t ACTLOAD : 2; 
    volatile uint8_t ACTCMPAU : 2;
    volatile uint8_t ACTCMPAD : 2;
    volatile uint8_t ACTCMPBU : 2;
    volatile uint8_t ACTCMPBD : 2;
    volatile uint32_t _reserved : 20;
} PWMnGENA;

typedef struct
{
    volatile uint8_t ACTZERO : 2;
    volatile uint8_t ACTLOAD : 2; 
    volatile uint8_t ACTCMPAU : 2;
    volatile uint8_t ACTCMPAD : 2;
    volatile uint8_t ACTCMPBU : 2;
    volatile uint8_t ACTCMPBD : 2;
    volatile uint32_t _reserved : 20;
} PWMnGENB;

typedef struct
{
    volatile uint8_t ENABLE : 1;
    volatile uint32_t _reserved : 31;
} PWMnDBCTL;

typedef struct
{
    volatile uint16_t RISEDELAY : 12;
    volatile uint32_t _reserved : 20;
} PWMnDBRISE;

typedef struct
{
    volatile uint16_t FALLDELAY : 12;
    volatile uint32_t _reserved : 20;
} PWMnDBFALL;

typedef struct
{
    volatile uint8_t FAULT0 : 1;
    volatile uint8_t FAULT1 : 1;
    volatile uint32_t _reserved : 30;
} PWMnFLTSRC0;

typedef struct
{
    volatile uint8_t DCMP0 : 1;
    volatile uint8_t DCMP1 : 1;
    volatile uint8_t DCMP2 : 1;
    volatile uint8_t DCMP3 : 1;
    volatile uint8_t DCMP4 : 1;
    volatile uint8_t DCMP5 : 1;
    volatile uint8_t DCMP6 : 1;
    volatile uint8_t DCMP7 : 1;
} PWMnFLTSRC1;

typedef struct
{
    volatile uint16_t MFP;
    volatile uint16_t _reserved;
} PWMnMINFLTPER;

typedef struct
{
    volatile uint8_t FAULT0 : 1;
    volatile uint8_t FAULT1 : 1;
    volatile uint32_t _reserved : 30;
} PWMnFLTSEN;

typedef struct
{
    volatile uint8_t FAULT0 : 1;
    volatile uint8_t FAULT1 : 1;
    volatile uint32_t _reserved : 30;
} PWMnFLTSTAT0;

typedef struct
{
    volatile uint8_t DCMP0 : 1;
    volatile uint8_t DCMP1 : 1;
    volatile uint8_t DCMP2 : 1;
    volatile uint8_t DCMP3 : 1;
    volatile uint8_t DCMP4 : 1;
    volatile uint8_t DCMP5 : 1;
    volatile uint8_t DCMP6 : 1;
    volatile uint8_t DCMP7 : 1;
} PWMnFLTSTAT1;

typedef struct
{
    volatile uint8_t GCNT : 4;
    volatile uint8_t FCNT : 4;
    volatile uint8_t ESYNC : 1;
    volatile uint8_t EFAULT : 1;
    volatile uint8_t ONE : 1;
    volatile uint32_t _reserved : 21;
} PWMPP;

typedef struct
{
    PWMnCTL control;
    PWMnINTEN interrupt_and_trigger_enable;
    PWMnRIS raw_interrupt_status;
    PWMnISC interrupt_status_and_clear;
    PWMnLOAD load;
    PWMnCOUNT counter;
    PWMnCMPA compare_A;
    PWMnCMPB compare_B;
    PWMnGENA generator_A_control;
    PWMnGENB generator_B_control;
    PWMnDBCTL deadband_control;
    PWMnDBRISE deadband_rising_edge_delay;
    PWMnDBFALL deadband_falling_edge_delay;
    PWMnFLTSRC0 fault_source0;
    PWMnFLTSRC1 fault_source1;
    PWMnMINFLTPER minimum_fault_period;
} PWMnMODULE;

typedef struct
{
    PWMnFLTSTAT0 fault_status_0;
    PWMnFLTSTAT1 fault_status_1;
} PWMnFLT_PART;

typedef struct
{
    PWMnFLTSEN fault_pin_logic_sense;
    PWMnFLTSTAT0 fault_status_0;
    PWMnFLTSTAT1 fault_status_1;
} PWMnFLT_FULL;

typedef struct
{
    PWMCTL master_control;
    PWMSYNC time_base_sync;
    PWMENABLE output_enable;
    PWMINVERT output_inversion;
    PWMFAULT output_fault;
    PWMINTEN interrupt_enable;
    PWMRIS raw_interrupt_status;
    PWMISC interrupt_status_and_clear;
    PWMSTATUS status;
    PWMFAULTVAL fault_condition_value;
    PWMENUPD enable_update;
    PWMnMODULE PWM0;
    PWMnMODULE PWM1;
    PWMnMODULE PWM2;
    PWMnMODULE PWM3;
    volatile uint8_t _reserved_1[0x6C0];
    PWMnFLT_FULL PWM0FLT;
    PWMnFLT_FULL PWM1FLT;
    PWMnFLT_PART PWM2FLT;
    volatile uint8_t _reserved_2[0x78];
    PWMnFLT_PART PWM3FLT;
    volatile uint8_t _reserved_3[0x634];
    PWMPP peripheral_properties;
} PWM_t;

#endif /* __PWM_REGISTERS_H__ */