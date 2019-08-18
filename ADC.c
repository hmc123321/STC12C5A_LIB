#include "ADC.h"
void AdcInit(char x,char speed,bit intr){//x为通道数，如：0x07为选通7通道，speed 0=FOSC/540,1=FOSC/360,2=FOSC/180,3=FOSC/90,是否开启中断
	AUXR1 |= 0x04;                         //ADC_RES[1:0]+/ADC_RESL[7:0]
	P1ASF = (1<<x);                        //打开AD通道开关

	EA = intr;                             //interrupt 5  
	EADC |= intr;

	if (intr==1)
		ADC_CONTR = ADC_POWER| (speed<<5)| ADC_START |pin	;          //打开ADC电源、选择速度、选择模拟输入通道、开始转换
	else ADC_CONTR = ADC_POWER| (speed<<5);   //不开启ADC
	
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}
/*
void rec ()	interrupt 5
{
	char str[15];
	unsigned int val= (ADC_RES<<8)|ADC_RESL;
	ADC_CONTR &= !ADC_FLAG;
	sprintf(str,"AD1:%d\r\n",val);
	SendString(1,str);
	ADC_CONTR = ADC_POWER| (0<<5)| ADC_START |1	;
}
*/
uint analogRead(uchar pin){
	unsigned int val;
	
	ADC_CONTR = ADC_POWER | (3<<5) | pin | ADC_START;
	 _nop_();                        //Must wait before inquiry
   _nop_();
   _nop_();
   _nop_();
	
	while (!(ADC_CONTR & ADC_FLAG));
	ADC_CONTR &= ~ADC_FLAG;
	val = (ADC_RES<<8)|ADC_RESL;
	return val;
}
