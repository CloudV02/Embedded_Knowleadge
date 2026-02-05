#include "RTE_TorqueControl1.h"
#include "../BSW/ECU_Abstraction/IoHwAb/IoHwAb_AcceleratorPedalSensor.h"
#include "../BSW/ECU_Abstraction/IoHwAb/IoHwAb_LoadCapacitySensor.h"
#include "../BSW/ECU_Abstraction/IoHwAb/IoHwAb_SpeedCarSensor.h"
#include "../BSW/ECU_Abstraction/IoHwAb/IoHwAb_TorqueSensor.h"

/* API Init Accelerator Pedal Sensor - Khởi tạo cảm biến bàn đạp */
Std_ReturnType RTE_Call_AcceleratorPedalSensor_Init(void){
    AcceleratorPedal_ConfigType AcceleratorPedalConfig ={
        .Accelerator_Channel = 1,
        .Acclerator_Max = 100, /* 100% */
    };
    
    return IoHwAb_Call_AcceleratorPedalSensor_Init(&AcceleratorPedalConfig);
}

/* API Init Speed Car Sensor - Khởi tạo cảm biến tốc độ */
Std_ReturnType RTE_Call_SpeedCarSensor_Init(void){
    Speed_ConfigType SpeedConfig = {
        .Speed_Channel = 2,
        .Speed_Max = 120, /* speed max 120km/h */
    };

    return IoHwAb_Call_SpeedCarSensor_Init(&SpeedConfig);
}

/* API Init Load Capacity Sensor - Khởi tạo cảm biến trọng tải*/
Std_ReturnType RTE_Call_LoadCapacitySensor_Init(void){
    LoadCapacitor_ConfigType LoadConfig = {
        .Load_Channel = 3,
        .Load_Max = 500, /* load capacity max 500kg */
    };

    return IoHwAb_Call_LoadCapacitySensor_Init(&LoadConfig);
}

/* API Init Torque Sensor - Khởi tạo cảm biến momen xoắn */
Std_ReturnType RTE_Call_TorqueSensor_Init(void){
    Torque_ConfigType TorqueConfig = {
        .Torque_Channel = 4,
        .Torque_Max = 1000,
    };
    return IoHwAb_Call_TorqueSensor_Init(&TorqueConfig);
}

/* API Read Value Of Accelerator Pedal Sensor */
Std_ReturnType RTE_Read_AcceleratorPedalSensor_AcceleratorValue(float *value){
    if(value == NULL){
        return R_NOK;
    }
    
    return IoHwAb_Read_AcceleratorPedalSensor_AcceleratorValue(value);
}

/* API Read Value of Speed Car Sensor */
Std_ReturnType RTE_Read_SpeedCarSensor_SpeedValue(float *value){
    if (value == NULL)
    {
        return R_NOK;
    }
    return IoHwAb_Read_SpeedCarSensor_SpeedValue(value);
}

/* API Read Value of Load Capacity Sensor */
Std_ReturnType RTE_Read_LoadCapacitySensor_CapacityValue(float *value){
    if(value == NULL){
        return R_NOK;
    }
    return IoHwAb_Read_LoadCapacitySensor_CapacityValue(value);
}

/* API Read Value of Torque Sensor*/
Std_ReturnType RTE_Read_TorqueSensor_TorqueValue(float *value){
    if(value == NULL){
        return R_NOK;
    }
    return IoHwAb_Read_TorqueSensor_TorqueValue(value);
}

/* API Write Value For Torque */
Std_ReturnType RTE_Write_TorqueSensor_TorqueUpdate(const float value){
    if(value){
        return IoHwAb_Write_TorqueSensor_TorqueUpdate(value);
    }
    else{
        return R_NOK;
    }
}