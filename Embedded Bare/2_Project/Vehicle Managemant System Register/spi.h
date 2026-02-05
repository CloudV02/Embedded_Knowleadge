#include "stm32f10x.h"

#ifndef			_SPI_
#define 		_SPI_

void RC522_SPI_Config(void);
uint8_t SPI_TransmitRecive(SPI_TypeDef *SPIx, uint8_t data);
void SDCard_SPI_Config(void);

#endif
