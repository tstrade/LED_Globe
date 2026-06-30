#ifndef __INTERNAL_MEM_REGISTERS_H__
#define __INTERNAL_MEM_REGISTERS_H__

#include <stdint.h>

typedef struct
{
    volatile uint32_t OFFSET : 18;
    volatile uint16_t _reserved : 14;
} FMA;

typedef volatile uint32_t FMD;

typedef struct
{
    volatile uint8_t WRITE : 1;
    volatile uint8_t ERASE : 1;
    volatile uint8_t MERASE : 1;
    volatile uint8_t COMT : 1;
    volatile uint16_t _reserved : 12;
    volatile uint16_t WRKEY;
} FMC;

typedef struct
{
    volatile uint8_t ARIS : 1;
    volatile uint8_t PRIS : 1;
    volatile uint8_t ERIS : 1;
    volatile uint8_t _reserved_1 : 6;
    volatile uint8_t VOLTRIS : 1;
    volatile uint8_t INVDRIS : 1;
    volatile uint8_t ERRIS : 1;
    volatile uint8_t _reserved_2 : 1;
    volatile uint8_t PROGRIS : 1;
    volatile uint32_t _reserved_3 : 18;
} FCRIS;

typedef struct
{
    volatile uint8_t AMASK : 1;
    volatile uint8_t PMASK : 1;
    volatile uint8_t EMASK : 1;
    volatile uint8_t _reserved_1 : 6;
    volatile uint8_t VOLTMASK : 1;
    volatile uint8_t INVDMASK : 1;
    volatile uint8_t ERMASK : 1;
    volatile uint8_t _reserved_2 : 1;
    volatile uint8_t PROGMASK : 1;
    volatile uint32_t _reserved_3 : 18;
} FCIM;

typedef struct
{
    volatile uint8_t AMISC : 1;
    volatile uint8_t PMISC : 1;
    volatile uint8_t EMISC : 1;
    volatile uint8_t _reserved_1 : 6;
    volatile uint8_t VOLTMISC : 1;
    volatile uint8_t INVDMISC : 1;
    volatile uint8_t ERMISC : 1;
    volatile uint8_t _reserved_2 : 1;
    volatile uint8_t PROGMISC : 1;
    volatile uint32_t _reserved_3 : 18;
} FCMISC;

typedef struct
{
    volatile uint8_t WRBUF : 1;
    volatile uint16_t _reserved : 15;
    volatile uint16_t WRKEY;
} FMC2;

typedef volatile uint32_t FWBVAL;

typedef volatile uint32_t FWBn;

typedef struct
{
    volatile uint16_t SIZE;
    volatile uint16_t _reserved;
} FSIZE;

typedef struct
{
    volatile uint16_t SIZE;
    volatile uint16_t _reserved;
} SSIZE;

typedef struct
{
    volatile uint8_t SAFERTOS : 1;
    volatile uint32_t _reserved : 31;
} ROMSWMAP;

typedef struct
{
    FMA address;
    FMD data;
    FMC control;
    FCRIS raw_interrupt_status;
    FCMISC masked_interrupt_status_and_clear;
    volatile uint8_t _reserved_1[2];
    FMC2 control_2;
    volatile uint8_t _reserved_2[3];
    FWBVAL write_buffer_valid;
    volatile uint8_t _reserved_3[0xCCU];
    FWBn write_buffer_n[32];
    volatile uint8_t _reserved_3[0xDC0U];
    FSIZE flash_size;
    SSIZE sram_size;
    volatile uint8_t _reserved_4;
    ROMSWMAP software_map;
} FLASH_t;

typedef struct
{
    volatile uint16_t WORDCNT;
    volatile uint16_t BLKCNT : 11;
    volatile uint8_t _reserved : 5;
} EESIZE;

typedef struct
{
    volatile uint16_t BLOCK;
    volatile uint16_t _reserved;
} EEBLOCK;

typedef struct
{
    volatile uint8_t OFFSET : 4;
    volatile uint32_t _reserved : 28;
} EEOFFSET;

typedef volatile uint32_t EERDWR;

typedef volatile uint32_t EERDWRINC;

typedef struct
{
    volatile uint8_t WORKING : 1;
    volatile uint8_t _reserved_1 : 1;
    volatile uint8_t WKERASE : 1;
    volatile uint8_t WKCOPY : 1;
    volatile uint8_t NOPERM : 1;
    volatile uint8_t WRBUSY : 1;
    volatile uint32_t _reserved_2 : 26;
} EEDONE;

typedef struct
{
    volatile uint8_t START : 1;
    volatile uint8_t EREQ : 1;
    volatile uint8_t ERETRY : 1;
    volatile uint8_t PRETRY : 1;
    volatile uint32_t _reserved : 28;
} EESUPP;

typedef volatile uint32_t EEUNLOCK;

typedef struct
{
    volatile uint8_t PROT : 3;
    volatile uint8_t ACC : 1;
    volatile uint32_t _reserved : 28;
} EEPROT;

typedef struct
{
    volatile uint32_t PASS;
} EEPASSn;

typedef struct
{
    volatile uint8_t INT : 1;
    volatile uint32_t _reserved : 31;
} EEINT;

typedef struct
{
    volatile uint8_t _reserved : 1;
    volatile uint32_t Hn : 31;
} EEHIDE;

typedef struct
{
    volatile uint8_t ME : 1;
    volatile uint16_t _reserved : 15;
    volatile uint16_t KEY;
} EEDBGME;

typedef struct
{
    volatile uint8_t SIZE : 5;
    volatile uint32_t _reserved : 27;
} EEPROMPP;

typedef struct
{
    EESIZE size_info;
    EEBLOCK current_block;
    volatile uint8_t _reserved_1;
    EERDWR read_write;
    EERDWRINC read_write_with_increment;
    EEDONE done_status;
    EESUPP support_control_and_status;
    EEUNLOCK unlock;
    volatile uint8_t _reserved_2[3];
    EEPROT protection;
    EEPASSn password[3];
    EEINT interrupt;
    volatile uint8_t _reserved_3[3];
    EEHIDE block_hide;
    volatile uint8_t _reserved_4[0x2C];
    EEDBGME debug_mass_erase;
    volatile uint8_t _reserved_5[0xF3CU];
    EEPROMPP peripheral_properties;
} EEPROM_t;

typedef struct
{
    volatile uint8_t BA : 1;
    volatile uint32_t _reserved : 31;
} RMCTL;

typedef struct
{
    volatile uint32_t READ_ENABLE;
} FMPREn;

typedef struct
{
    volatile uint32_t PROG_ENABLE;
} FMPPEn;

typedef struct
{
    volatile uint8_t DBG0 : 1;
    volatile uint8_t DBG1 : 1;
    volatile uint8_t _reserved_1 : 2;
    volatile uint8_t KEY : 1;
    volatile uint8_t _reserved_2 : 3;
    volatile uint8_t EN : 1;
    volatile uint8_t POL : 1;
    volatile uint8_t PIN : 3;
    volatile uint8_t PORT : 3;
    volatile uint16_t _reserved_3 : 15;
    volatile uint8_t NW : 1;
} BOOTCFG;

typedef struct
{
    volatile uint32_t DATA;
} USER_REGn;

typedef struct
{
    volatile uint8_t _reserved_1[0xECU];
    RMCTL control;
    volatile uint8_t _reserved_2[0x3C];
    FMPREn protection_read_enable_0;
    FMPPEn protection_program_enable_0;
    volatile uint8_t _reserved_3[0x98U];
    BOOTCFG boot_configuration;
    volatile uint8_t _reserved_4[3];
    USER_REGn user_register[4];
    volatile uint8_t _reserved_5[16];
    FMPREn protection_read_enable[4];
    volatile uint8_t _reserved_6[0x1F0];
    FMPPEn protection_program_enable[4];
} ROM_t;

#endif /* __INTERNAL_MEM_REGISTERS_H__ */