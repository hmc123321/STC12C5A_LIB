#include <stc12c5a.h>
#ifndef _IIC_H_
#define _IIC_H_
#ifndef uchar
#define uchar unsigned char
#endif
#ifndef uint	
#define uint unsigned int
#endif	

sbit SDA = P0^7;
sbit SCL = P0^6;

void I2C_SOFT_SEND(uchar S_SND);
void I2C_SOFT_STOP();
void I2C_SOFT_START();
void delayus();
#endif 