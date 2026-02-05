#ifndef _IOHWAB_ACCELERATOR_H_
#define _IOHWAB_ACCELERATOR_H_

#include "../../Services/Std_Types.h"

typedef struct{
    /* config adc channel used */
    uint32_t Accelerator_Channel;
    /* information */
    uint16_t Acclerator_Max; 

}AcceleratorPedal_ConfigType;

Std_ReturnType IoHwAb_Call_AcceleratorPedalSensor_Init(AcceleratorPedal_ConfigType *AcceleratorPedalConfig);

Std_ReturnType IoHwAb_Read_AcceleratorPedalSensor_AcceleratorValue(float *value);


#endif