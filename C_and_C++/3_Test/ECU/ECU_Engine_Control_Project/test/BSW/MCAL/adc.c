#include "adc.h"

static ADC_Config ADC_CurrentConfig;


void ADC_Init(const ADC_Config *Config){
    if(Config==NULL){
        printf("ERROR! ADC can't find address\n");
        return;
    }
    ADC_CurrentConfig.ADC_Channel = Config->ADC_Channel;
    ADC_CurrentConfig.ADC_Resolution = Config->ADC_Resolution;
    ADC_CurrentConfig.ADC_Sample = Config->ADC_Sample;
    printf("Succesfull! Config ADC\n");

    srand(time(0));

}

Std_ReturnType ADC_Read(float *value, uint16_t Channel){
    *value = rand()/1024;

    printf("The value of Channel %d = %.2f",Channel,*value);
    return R_OK;
}