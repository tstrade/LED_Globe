#ifndef __PWM_DRIVER_H__
#define __PWM_DRIVER_H__

#include <stdint.h>
#include "macros.h"

typedef enum
{
    MnPWM0 = 0x0,
    MnPWM1 = 0x1,
    MnPWM2 = 0x2,
    MnPWM3 = 0x4,
    MnPWM4 = 0x8U,
    MnPWM5 = 0x10,
    MnPWM6 = 0x20,
    MnPWM7 = 0x40
} PWM_SUBMODULES;

typedef enum
{
    PWM_IMMEDIATE = 0x0,
    PWM_LOCALSYNC = 0x2,
    PWM_GLOBALSYNC = 0x3
} PWM_ENABLE_UPDATES;

typedef struct
{
    PWM_GENERATORS generator;
    mode_t global_sync;
    uint8_t submodules_enable;
    uint8_t submodules_inversion;
    
    

}



#endif /* __PWM_DRIVER_H__ */