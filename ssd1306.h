#include <stc12c5a.h>
#include "IIC.h"
#ifndef _SSD1306_H_
#define _SSD1306_H_
#ifndef uchar
#define uchar unsigned char
#endif
#ifndef uint	
#define uint unsigned int
#endif	

#define ADDR 0x78
void sendCMD(uchar cmd);
void sendDAT(uchar dat);
void OledInit();
void OledFill(uchar);
void displayBmp(uchar imgx,uchar imgy,uchar posX,uchar posY,uchar * bmp);
#endif