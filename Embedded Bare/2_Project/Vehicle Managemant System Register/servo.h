#ifndef _SERVO_H_
#define _SERVO_H_
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "delay.h"

void Servo_PWM_Init(void);
void Set_ServoCorner(uint16_t setCorner);

#endif

