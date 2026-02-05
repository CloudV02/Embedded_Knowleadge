#include "stm32f10x.h"


void DelayInit(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	TIM_TimeBaseInitTypeDef Tim_InitStruct;
	
	/*Chia nho xung dau vao, clock cap cho timer */
	Tim_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1; // Clock cap cho tim 2 la 72mhz: 1s tao dc 72m dao dong
	
	/*Gia tri quyet dinh sau bao xung mhz dem len 1 lan, tuc la sau bao nhieu dao dong se dem len 1 lan*/
	// 1 dao dong ton: 1/72m s
	// 1ms = 10^6s
	Tim_InitStruct.TIM_Prescaler = 7; // 72*1/72m = 1/1000000= 1ms
	
	/*Sau bao nhieu gia tri dem no se tran -> reset lai thanh ghi*/
	Tim_InitStruct.TIM_Period = 0xFFFF; // tuc la nhay len 1000 lan reset ve 0

	/*Mode dem len or dem xuong or mode khac*/
	Tim_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_Cmd(TIM3,ENABLE);
	TIM_TimeBaseInit(TIM3, &Tim_InitStruct);
}

/*1 giay nhay 1 lan*/
void DelayMs(uint32_t ms)
{
    while (ms--)
    {
        uint16_t start = TIM_GetCounter(TIM3);
        while ((uint16_t)(TIM_GetCounter(TIM3) - start) < 1000);
    }
}
void DelayUs(uint32_t us)
{
    while (us--)
    {
        uint16_t start = TIM_GetCounter(TIM3);
        while ((uint16_t)(TIM_GetCounter(TIM3) - start) < us);
    }
}


void I2C1_Config(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    gpio.GPIO_Mode = GPIO_Mode_AF_OD;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &gpio);

    I2C_InitTypeDef i2c;
    i2c.I2C_ClockSpeed = 100000;
    i2c.I2C_Mode = I2C_Mode_I2C;
    i2c.I2C_DutyCycle = I2C_DutyCycle_2;
    i2c.I2C_OwnAddress1 = 0x00;
    i2c.I2C_Ack = I2C_Ack_Enable;
    i2c.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

    I2C_Init(I2C1, &i2c);
    I2C_Cmd(I2C1, ENABLE);
}


void I2C_Send(uint8_t addr, uint8_t data) {
    while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));

    I2C_GenerateSTART(I2C1, ENABLE);
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));

    I2C_Send7bitAddress(I2C1, addr << 1, I2C_Direction_Transmitter);
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

    I2C_SendData(I2C1, data);
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

    I2C_GenerateSTOP(I2C1, ENABLE);
}

void I2C_TestStart(void) {
    while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
    I2C_GenerateSTART(I2C1, ENABLE);
    for (volatile int i = 0; i < 10000; i++);
    I2C_GenerateSTOP(I2C1, ENABLE);
}


int main(void) {
    I2C1_Config();

    while (1) {
        I2C_TestStart();
        for (volatile int i = 0; i < 1000000; i++);
    }
}
