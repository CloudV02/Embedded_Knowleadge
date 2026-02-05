#ifndef _RTE_TorqueControl_
#define _RTE_TorqueControl_

#include "../BSW/Services/Std_Types.h"

/* API Init Accelerator Pedal Sensor - Khởi tạo cảm biến bàn đạp */
Std_ReturnType RTE_Call_AcceleratorPedalSensor_Init(void);

/* API Init Speed Car Sensor - Khởi tạo cảm biến tốc độ */
Std_ReturnType RTE_Call_SpeedCarSensor_Init(void);

/* API Init Load Capacity Sensor - Khởi tạo cảm biến trọng tải*/
Std_ReturnType RTE_Call_LoadCapacitySensor_Init(void);

/* API Init Torque Sensor - Khởi tạo cảm biến momen xoắn */
Std_ReturnType RTE_Call_TorqueSensor_Init(void);

/* API Read Value Of Accelerator Pedal Sensor */
Std_ReturnType RTE_Read_AcceleratorPedalSensor_AcceleratorValue(float *value);

/* API Read Value of Speed Car Sensor */
Std_ReturnType RTE_Read_SpeedCarSensor_SpeedValue(float *value);

/* API Read Value of Load Capacity Sensor */
Std_ReturnType RTE_Read_LoadCapacitySensor_CapacityValue(float *value);

/* API Read Value of Torque Sensor*/
Std_ReturnType RTE_Read_TorqueSensor_TorqueValue(float *value);

/* API Write Value For Torque */
Std_ReturnType RTE_Write_TorqueSensor_TorqueUpdate(const float value);

#endif