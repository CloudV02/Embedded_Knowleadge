#include "Torque_Control1.h"
#include "../RTE/RTE_TorqueControl1.h"
void TorqueControl_Init(void){

    Std_ReturnType status;
    /* Init Accelerator pedal sensor (APS) → Cảm biến bàn đạp ga. */
    status = RTE_Call_AccleratorPedalSensor_Init();

    if(status == R_OK){
        printf("Initialize Acclerator Pedal Successful!\n");
    }
    else{
        printf("Initialize Acesslertor Pedal Error!\n");
        return;
    }

    /* Init Speed Car Sensor */
    status = RTE_Call_SpeedCarSensor_Init();
    if(status == R_OK){
        printf("Initialize Speed Car Sensor Successful!\n ");
    }
    else{
        printf("Initialize Speed Car Sensor Error!\n");
        return;
    }

    /* Init Load Capacity Car Sensor -> cảm biến trọng lượng */
    status = RTE_Call_LoadCapacitySensor_Init();
    if(status == R_OK){
        printf("Initialize Load Capacity Sensor Successful!\n ");
    }
    else{
        printf("Initialize Load Capacity Sensor Error!\n ");
        return;
    }

    status = RTE_Call_TorqueSensor_Init();
    if (status == R_OK)
    {
        printf("Initialize Torque Sensor Successful!\n ");
    }
    else{
        printf("Initialize Torque Sensor Error!\n ");
        return;
    }
    

    printf("Initialize Torque Control Successful!\n");
}

void TorqueControl_Update(void){
    float value_ofSpeed;
    float value_ofCapacity;
    float value_ofAcceleratorPedal;
    float value_ofTorque;
    float value_ofCalculate;
    /* read data of accelerator pedal sensor*/
    if(RTE_Read_AcceleratorPedalSensor_AcceleratorValue(&value_ofAcceleratorPedal)==R_OK){
        printf("The data of Accelerator Pedal Sensor is: %.2f\n",value_ofAcceleratorPedal);
    }
    else{
        printf("ERROR! Can't be received the data of Accelerator Pedal Sensor\n");
        return;
    }
    /* read data of speed sensor*/
    if (RTE_Read_SpeedCarSensor_SpeedValue(&value_ofSpeed)==R_OK)
    {
        printf("The data of Speed Car Sensor is: %.2f\n",value_ofSpeed);
    }
    else{
        printf("ERROR! Can't be received the data of Speed Car Sensor\n");
        return;
    }    

    /* read data of load capacity sensor */
    if (RTE_Read_LoadCapacitySensor_CapacityValue(&value_ofCapacity)==R_OK)
    {
        printf("The data of Load Capacity Sensor is: %.2f\n",value_ofCapacity);
    }
    else{
        printf("ERROR! Can't be received the data of Load Capacity Sensor\n");
        return;
    }

    /* read data of torque sensor */
    if (RTE_Read_TorqueSensor_TorqueValue(&value_ofTorque)==R_OK){
        printf("The data of Torque Sensor: %.2f\n",value_ofTorque);
    }
    else{
        printf("ERROR! Can't be received the data of Torque Sensor\n");
    }
    
    /* calculating */
    value_ofCalculate = value_ofAcceleratorPedal * MAX_TORQUE;
    if(value_ofSpeed > 50.0f){
        value_ofCalculate *= 0.8f;
    }
    if(value_ofCapacity > 500.0f){
        value_ofCalculate += 10.0f;
    }

    if(value_ofCalculate > MAX_TORQUE){
        value_ofCalculate = MAX_TORQUE;
    }
    if (value_ofTorque < MIN_TORQUE)
    {
        value_ofCalculate = MIN_TORQUE;
    }
    
    /* update for torque */
    if(RTE_Write_TorqueSensor_UpdateTorque(value_ofCalculate)==R_OK){
        printf("Write data of Torque !! Successful !!\n");
    }
    else{
        printf("ERROR! Can't write data of Torque\n");
        return;
    }
}