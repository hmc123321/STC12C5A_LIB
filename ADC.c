#include "ADC.h"
void AdcInit(char x,char speed,bit intr){//xΪͨ�������磺0x07Ϊѡͨ7ͨ����speed 0=FOSC/540,1=FOSC/360,2=FOSC/180,3=FOSC/90,�Ƿ����ж�
	AUXR1 |= 0x04;                         //ADC_RES[1:0]+/ADC_RESL[7:0]
	P1ASF = (1<<x);                        //��ADͨ������

	EA = intr;                             //interrupt 5  
	EADC |= intr;

	ADC_CONTR = ADC_POWER| (speed<<5)| ADC_START |x	;          //��ADC��Դ��ѡ���ٶȡ�ѡ��ģ������ͨ������ʼת��

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