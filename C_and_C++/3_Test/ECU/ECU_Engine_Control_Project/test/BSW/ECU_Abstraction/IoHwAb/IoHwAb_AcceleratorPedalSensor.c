#include "IoHwAb_AcceleratorPedalSensor.h"
#include "../../../BSW/MCAL/adc.h"


static AcceleratorPedal_ConfigType AcceleratorPedal_Global;

Std_ReturnType IoHwAb_Call_AcceleratorPedalSensor_Init(AcceleratorPedal_ConfigType *AcceleratorPedalConfig){
    if(AcceleratorPedalConfig == NULL){
        printf("ERROR! Acclerator Pedal can't be initialize\n");
        return R_NOK;
    }
    /* Save infor of Accelerator Pedal */
    AcceleratorPedal_Global.Accelerator_Channel = AcceleratorPedalConfig->Accelerator_Channel;
    AcceleratorPedal_Global.Acclerator_Max = AcceleratorPedalConfig->Acclerator_Max;

    /*Set up Hardware ADC*/
    ADC_Config Config_ADC;
    Config_ADC.ADC_Channel = AcceleratorPedalConfig->Accelerator_Channel;
    Config_ADC.ADC_Resolution = 0x11;
    Config_ADC.ADC_Sample = 0x04;

    ADC_Init(&Config_ADC);

    /*print infor Accelerator Pedal */
    printf("Load information of Accelerator Pedal ..........\n");
    printf("The channel of Accelerator Pedal = %d\n",AcceleratorPedal_Global.Accelerator_Channel);
    printf("The max percent of Acclerator Pedal = %d\n",AcceleratorPedalConfig->Acclerator_Max);
    return R_OK;
}

Std_ReturnType IoHwAb_Read_AcceleratorPedalSensor_AcceleratorValue(float *value){
    if(value == NULL){
        printf("ERROR! Address of value can't be find\n");
        return R_NOK;
    }
    if(ADC_Read(value,AcceleratorPedal_Global.Accelerator_Channel)==R_NOK){
        printf("ERROR! ADC can't read value\n");
        return R_NOK;
    }
    printf("Reading value of Accelerator Pedal ........\n");
    AcceleratorPedal_Global.Acclerator_Max = *value;
    printf("Value of Accelerator Pedal = %d%\n", AcceleratorPedal_Global.Acclerator_Max);
    return R_OK;
}