#include "stm32f10x.h"

void GPIO_Config(void) {
    // B?t clock GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // C?u hình PA1: Alternate Function Push-Pull, Output 50MHz
    GPIOA->CRL &= ~(0xF << 4);   // Clear bits for PA1 (bits 7:4)
    GPIOA->CRL |=  (0xB << 4);   // 1011 = Output 50MHz, AF push-pull
}

void TIM2_PWM_Config(void) {
    // B?t clock cho TIM2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Prescaler: 72 MHz / 72 = 1 MHz (1 tick = 1 us)
    TIM2->PSC = 72 - 1;

    // Auto-reload: 20,000 ticks ? 20ms ? 50Hz
    TIM2->ARR = 20000 - 1;

    // Pulse width (duty cycle): 1500 = 1.5ms = trung tâm servo
    TIM2->CCR2 = 1500;

    // PWM mode 1 on channel 2 (OC2M = 110), preload enable (OC2PE)
    TIM2->CCMR1 &= ~(0xFF << 8);               // Clear bits for CH2
    TIM2->CCMR1 |= (6 << 12) | (1 << 11);      // OC2M = 110, OC2PE = 1

    // Enable capture/compare for channel 2 (output)
    TIM2->CCER |= TIM_CCER_CC2E;

    // Enable auto-reload preload
    TIM2->CR1 |= TIM_CR1_ARPE;

    // Enable counter
    TIM2->CR1 |= TIM_CR1_CEN;
}

int main(void) {
    GPIO_Config();
    TIM2_PWM_Config();
		volatile int i = 0;
	  int pulse = 0;
    while (1) {
        // Ví d?: quét t? 1ms d?n 2ms d? servo quay t? 0 d?n 180 d?
        for (pulse = 1000; pulse <= 2000; pulse += 10) {
            TIM2->CCR2 = pulse;
            for (i = 0; i < 50000; i++); // Delay t?m
        }

        for (pulse = 2000; pulse >= 1000; pulse -= 10) {
            TIM2->CCR2 = pulse;
            for (i = 0; i < 50000; i++); // Delay t?m
        }
    }
}
