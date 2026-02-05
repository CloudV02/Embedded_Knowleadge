#include "rifd.h"
#include "spi.h"
#include "delay.h"

void RC522_Init(void){
	RC522_SPI_Config();
	RC522_Reset();
	DelayUs(50);
	
	/*Set up internal timer*/
	RC522_WriteRegister(TMOD_REG, 0x8D);
	/*This register will be prescaler of 13.56Mhz
	default: 13.56Mhz
	TPrecaler = 169 -> 1 tick = (TPrescaler*2+1) / 13.56Mhz -> T = 25us
	*/
	
	RC522_WriteRegister(TPRESCALER_REG,0x3E);
	RC522_WriteRegister(TRELOADHI_REG, 30);
	RC522_WriteRegister(TRELOADLO_REG, 0);
	
	/*Set 48db*/
	RC522_WriteRegister(RFCFG_REG,0x70);
	/*ASK 100%*/
	RC522_WriteRegister(TXASK_REG,0x40);
	/*CRC*/
	RC522_WriteRegister(MODE_REG,0x3D);
	
	/*Turn on Anten*/
	RC522_Anten();
}

void RC522_Reset(void){
	RC522_WriteRegister(COMMAND_REG,CMD_SOFTRESET);
}

void RC522_Anten(void){
	uint8_t data_dump;
	data_dump = RC522_ReadRegister(TXCONTROL_REG);
	
	RC522_WriteRegister(TXCONTROL_REG,data_dump|0x03);
}

void RC522_ClearBit(uint8_t addr, uint8_t val_clear){
	uint8_t data_dump;
	data_dump = RC522_ReadRegister(addr);
	RC522_WriteRegister(addr,data_dump &~(val_clear));
}

void RC522_SetBit(uint8_t addr, uint8_t val_bitSet){
	
	uint8_t data_dump;
	data_dump = RC522_ReadRegister(addr);
	RC522_WriteRegister(addr,data_dump | val_bitSet);
}

uint8_t RC522_ReadRegister(uint8_t addr){
	uint8_t data;
	RC522_OFF
	
	SPI_TransmitRecive(SPI1,((addr<<1) & 0x7E) | 0x80);
	data = SPI_TransmitRecive(SPI1,0x00);
	
	RC522_ON
	return data;
}

void RC522_WriteRegister(uint8_t addr, uint8_t val_addr){
	RC522_OFF
	
	SPI_TransmitRecive(SPI1,(addr<<1) & 0x7E);
	
	SPI_TransmitRecive(SPI1,val_addr);

	RC522_ON
}


RC522_STATUS_T RC522_ToCard(uint16_t size, uint8_t *data_transmit, uint8_t *data_store, uint16_t *number_bit){
	uint16_t loop;
	volatile uint8_t fifoBuffer = 0x00;
	RC522_STATUS_T status;
	uint8_t lastbyte;
	/*Init ComIEnReg*/
	status = RC522_CRC_ERROR;
	RC522_WriteRegister(COMIEN_REG, 0xF7);
	RC522_ClearBit(COMIRQ_REG,0x80);
	/*IDLE*/
	RC522_WriteRegister(COMMAND_REG,CMD_IDLE);
	
	RC522_SetBit(FIFOLEVEL_REG,0x80);
	
	/*Wrting to FIFO 0x26 mean request REQA to card*/
	for(loop = 0;loop < size;loop++){
		RC522_WriteRegister(FIFODATA_REG,data_transmit[loop]);
	}
	
	/*Tranmit data*/
	RC522_WriteRegister(COMMAND_REG,CMD_TRANSCEIVE);
	/*Start Send = 1*/
	RC522_SetBit(BITFRAMING_REG,0x80);
	
	
	/*Wait recive data*/
	/*Check: timeout(0x01) of ComIRQ, check Idle va Rx of ComIRQ*/
	loop = 2000;
	do{
		fifoBuffer = RC522_ReadRegister(COMIRQ_REG);
		loop--;
	
	}while((loop!=0) && !(fifoBuffer&0x01) && !(fifoBuffer&0x30));
	
	RC522_ClearBit(BITFRAMING_REG,0x80);
	
	volatile uint8_t read1 = RC522_ReadRegister(ERROR_REG);
	
	if(loop!=0)
	{
		if(!(RC522_ReadRegister(ERROR_REG)&0x1B)){
			status = RC522_OK;
			if(fifoBuffer & 0x01){
				status = RC522_TIMEOUT;
			}
			fifoBuffer = RC522_ReadRegister(FIFOLEVEL_REG);
			/*if CONTROL_REG = 0 -> all bit valit(hop le)*/
			lastbyte= RC522_ReadRegister(CONTROL_REG) & 0x07;
			if(lastbyte){
				*number_bit = (fifoBuffer-1)*8 + lastbyte;
			}else{
				*number_bit = fifoBuffer * 8;
			}
			if (fifoBuffer == 0) {   
					fifoBuffer = 1;    
				}
			if (fifoBuffer > 16) {   
					fifoBuffer = 16;   
			}

			for(loop = 0; loop<fifoBuffer; loop++){
				data_store[loop] = RC522_ReadRegister(FIFODATA_REG);
			}
		}
		else{
			status = RC522_CRC_ERROR;
		}
	}
	return status;
}

RC522_STATUS_T RC522_Check(uint8_t *id){
	RC522_STATUS_T status;
	
	/*size: lenght of data tranmit to card
	id: transmit and store data
	number_bit: count number of bit of frame
	*/
	status = RC522_Request(id);
	if(status == RC522_OK){
		
		status = RC522_Anticoll(id);
	}
	return status;
}

RC522_STATUS_T RC522_Request(uint8_t *id){
	RC522_STATUS_T status;
	uint16_t allbit;
	/*command to request to card*/
	id[0] = 0x26;
	RC522_WriteRegister(BITFRAMING_REG,0x07);
	status = RC522_ToCard(1,id,id,&allbit);
	if ((status != RC522_OK) || (allbit != 0x10)) {    
		status = RC522_CRC_ERROR;
	}
	return status;
}
RC522_STATUS_T RC522_Anticoll(uint8_t *id){
	RC522_STATUS_T status;
	uint16_t allbit;
	id[0] = 0x93;
	id[1] = 0x20;
	RC522_WriteRegister(BITFRAMING_REG,0x00);
	status = RC522_ToCard(2,id,id,&allbit);
	if (allbit != 40) return RC522_CRC_ERROR; // 5 bytes * 8 bits

	return status;
}
