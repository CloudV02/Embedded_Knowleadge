#ifndef _Std_Types_
#define _Std_Types_

#include <stdio.h>
#include <stdint.h>
typedef enum{
    R_NOK = 0,
    R_OK
}Std_ReturnType;

typedef struct{
    /* config adc channel used */
    uint32_t Accelerator_Channel;
    /* information */
    const uint16_t Acclerator_Max; 

}AcceleratorPedal_ConfigType;

typedef struct{

    uint32_t Speed_Channel;
    const uint16_t Speed_Max;

}Speed_ConfigType;

typedef struct{

    uint32_t Load_Channel;
    const uint16_t Load_Max;

}LoadCapacitor_ConfigType;

typedef struct{

    uint32_t Torque_Channel;
    const uint16_t Torque_Max;

}Torque_ConfigType;


#endif