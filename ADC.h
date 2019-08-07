#include <stc12c5a.h>
#include <intrins.h>
#ifndef _ADC_H_
#define _ADC_H_
#ifndef uchar
#define uchar unsigned char
#endif
#ifndef uint	
#define uint unsigned int
#endif	
void AdcInit(char x,char speed,bit intr);
#endif	