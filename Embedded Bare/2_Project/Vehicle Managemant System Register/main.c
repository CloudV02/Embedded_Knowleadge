#include "rifd.h"
#include "lcd.h"
#include "servo.h"
#include "ff.h"
#include "stdio.h"
/*uint8_t CardID[5];
char szBuff[100];*/
void SD_Test(void);
void myprintf(const char *fmt, ...);
static FATFS fs;
static FIL file;
static BYTE buf[64];

int main(void){
	DelayInit();
	SDCard_SPI_Config();
	//LCD_Init();
	//Servo_PWM_Init();
	//RC522_Init();
	SD_Test();
	
	while(1) {
		/*if (RC522_Check(CardID) == RC522_OK) 
		{
			sprintf(szBuff, "ID: 0x%02X%02X%02X%02X%02X", CardID[0], CardID[1], CardID[2], CardID[3], CardID[4]);
		}*/
		
		
		
		}
}


void SD_Test(void)
{
    FRESULT res;
    DWORD fre_clust, fre_sect, tot_sect;
    FATFS *pfs;

    res = f_mount(&fs, "", 1);
    if (res != FR_OK)
    {
        myprintf("Mount fail: %d\r\n", res);
        return;
    }

    res = f_getfree("", &fre_clust, &pfs);
    if (res == FR_OK)
    {
        tot_sect = (pfs->n_fatent - 2) * pfs->csize;
        fre_sect = fre_clust * pfs->csize;

        myprintf("Total: %lu KB\r\n", tot_sect / 2);
        myprintf("Free : %lu KB\r\n", fre_sect / 2);
    }

    res = f_open(&file, "data.txt", FA_READ);
    if (res != FR_OK)
    {
        myprintf("Open fail: %d\r\n", res);
        goto exit;
    }

    while (f_gets((TCHAR*)buf, sizeof(buf), &file))
    {
        myprintf("%s", buf);
    }

    f_close(&file);

exit:
    f_mount(NULL, "", 0);
}
void myprintf(const char *fmt, ...)
{
    // do nothing
}


