#include "stm32f10x.h"
#include "string.h"
#include <stdio.h>


#define RC522_ON								GPIO_SetBits(GPIOA,GPIO_Pin_4);
#define RC522_OFF 							GPIO_ResetBits(GPIOA,GPIO_Pin_4);

/*PAGE 0: COMMAND AND STATUS REGISTER*/

#define REVERSED0_REG					0x00
#define COMMAND_REG						0x01
#define COMIEN_REG						0x02
#define DIVIEN_REG						0x03
#define COMIRQ_REG						0x04
#define DIVIRQ_REG						0x05
#define ERROR_REG							0x06
#define STATUS1_REG						0x07
#define STATUS2_REG						0x08
#define FIFODATA_REG					0x09
#define FIFOLEVEL_REG					0x0A
#define WATERLEVEL_REG				0x0B
#define CONTROL_REG						0x0C
#define BITFRAMING_REG				0x0D
#define COLL_REG							0x0E

/*PAGE 1: COMMAND*/
#define REVERSED1_REG					0x10
#define MODE_REG							0x11
#define TXMODE_REG						0x12
#define RXMOD_REG							0x13
#define TXCONTROL_REG					0x14
#define TXASK_REG							0x15
#define TXSEL_REG							0x16
#define RXSEL_REG							0x17
#define RXTHREADHOLD_REG			0x18
#define DEMOND_REG						0x19
#define REVERSED12_REG				0x1A
#define REVERSED13_REG				0x1B
#define	MFTX_REG							0x1C
#define MFRX_REG							0x1D
#define REVERSED14_REG				0x1E
#define SERIALSPEED_REG				0x1F

/*PAGE 2: CONFIGURATION*/
#define REVERSED20_REG				0x20
#define CRCRESULTMSB_REG			0x21
#define CRCRESULTLSB_REG			0x22
#define REVERSED21_REG				0x23
#define MODWIDTH_REG					0x24
#define REVERSED22_REG				0x25
#define RFCFG_REG							0x26
#define GSN_REG								0x27
#define CWGSPR_REG						0x28
#define MODGSP_REG						0x29
#define TMOD_REG							0x2A
#define TPRESCALER_REG				0x2B
#define TRELOADHI_REG					0x2C
#define TRELOADLO_REG					0x2D
#define TCOUNTERVALHI_REG			0x2E
#define TCOUNTERVALLO_REG			0x2F

/*PAGE 3: TEST REGISTER*/
#define REVERSED30_REG				0x30
#define TESTSEL1_REG					0x31
#define TESTSEL2_REG					0x32
#define TESTPINEN_REG					0x33
#define TESTPINVALUE_REG			0x34
#define TESTBUS_REG						0x35
#define AUTOTEST_REG					0x36
#define VERSION_REG						0x37
#define ANALOGTEST_REG				0x38
#define TESTDAC1_REG					0x39
#define TESTDAC2_REG					0x3A
#define TESTADC_REG						0x3B
#define REVERSED31_REG				0x3C
#define REVERSED32_REG				0x3D
#define REVERSED33_REG				0x3E
#define REVERSED34_REG				0x3f

/*COMMAND CODE*/

#define CMD_IDLE							0x00
#define CMD_MEM								0x01
#define CMD_RAMDOMID					0x02
#define CMD_CALCCRC						0x03
#define CMD_TRANSMIT					0x04
#define CMD_NOCMDCHANGE				0x07
#define CMD_RECEIVE						0x08
#define CMD_TRANSCEIVE				0x0C
#define CMD_REVERSVE					0x0D
#define CMD_MFAUTHENT					0x0E
#define CMD_SOFTRESET					0x0F

/*CRC ERROR : error data return from card*/
/*ATQA ERROR: card don't respone*/
#ifndef __RFID_H__
#define __RFID_H__

typedef enum{
	
	RC522_OK = 0,
	RC522_CRC_ERROR,
	RC522_ATQA_ERROR,
	RC522_TIMEOUT,

}RC522_STATUS_T;

/*FUNCTION*/

void RC522_Init(void);
void RC522_WriteRegister(uint8_t addr, uint8_t val_addr);
void RC522_Reset(void);
void RC522_Anten(void);
uint8_t RC522_ReadRegister(uint8_t addr);
void RC522_ClearBit(uint8_t addr, uint8_t val_clear);
void RC522_SetBit(uint8_t addr, uint8_t val_bitSet);


RC522_STATUS_T RC522_Request(uint8_t *id);
RC522_STATUS_T RC522_ToCard(uint16_t size, uint8_t *data_transmit, uint8_t *data_store, uint16_t *number_bit);
RC522_STATUS_T RC522_Anticoll(uint8_t *id);
RC522_STATUS_T RC522_CalCRC(void);
RC522_STATUS_T RC522_Select(void);
RC522_STATUS_T RC522_Check(uint8_t *id);

#endif

