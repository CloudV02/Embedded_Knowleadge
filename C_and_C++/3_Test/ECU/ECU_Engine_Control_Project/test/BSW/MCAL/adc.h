#ifndef _ADC_H_
#define _ADC_H_

#include <stdio.h>
#include <stdint.h>
#include "../Services/Std_Types.h"

typedef struct {
    uint8_t ADC_Channel;
    uint32_t ADC_Sample;
    uint32_t ADC_Resolution;
}ADC_Config;

void ADC_Init(const ADC_Config *Config);

Std_ReturnType ADC_Read(float *value, uint16_t Channel);

#endif