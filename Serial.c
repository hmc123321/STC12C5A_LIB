#include "Serial.h"
/*
void PutString(unsigned char *TXStr)  
{    
   while(*TXStr!=0) {                      
     SBUF=*TXStr;
     while(TI==0);
     TI=0;    
     TXStr++;
   }
} 
*/

void putChar(char a,unsigned char TXStr)  
{   
		if (a==1){
     SBUF=TXStr;
     while(TI==0);
     TI=0; 
		}
		else if (a==2){
		 S2BUF=TXStr;
     while(S2CON&S2TI==0);
     TI=0; 
		}
} 

void SendString(char a,char *s)
{
   while (*s)              //Check the end of the string
	 {
      putChar(a,*s++);     //Send current char and increment string ptr
		 }
}
/*
void Send1Data(unsigned char dat)
{
//    while (TI==1);           //Wait for the completion of the previous data is sent
    ACC = dat;              //Calculate the even parity bit P (PSW.0)
    if (P)                  //Set the parity bit according to P
    {
#if (PARITYBIT == ODD_PARITY)
        TB8 = 0;            //Set parity bit to 0
#elif (PARITYBIT == EVEN_PARITY)
        TB8 = 1;            //Set parity bit to 1
#endif
    }
    else
    {
#if (PARITYBIT == ODD_PARITY)
        TB8 = 1;            //Set parity bit to 1
#elif (PARITYBIT == EVEN_PARITY)
        TB8 = 0;            //Set parity bit to 0
#endif
    }
    SBUF = ACC;             //Send data to UART buffer
}

void Send2Data(unsigned char dat)
{
//    while (S2CON & S2TI==0);           //Wait for the completion of the previous data is sent
    ACC = dat;              //Calculate the even parity bit P (PSW.0)
    if (P)                  //Set the parity bit according to P
    {
#if (PARITYBIT == ODD_PARITY)
        S2CON &= ~S2TB8;    //Set parity bit to 0
#elif (PARITYBIT == EVEN_PARITY)
        S2CON |= S2TB8;     //Set parity bit to 1
#endif
    }
    else
    {
#if (PARITYBIT == ODD_PARITY)
        S2CON |= S2TB8;     //Set parity bit to 1
#elif (PARITYBIT == EVEN_PARITY)
        S2CON &= ~S2TB8;    //Set parity bit to 0
#endif
    }
    S2BUF = ACC;            //Send data to UART2 buffer
}
*/
void Uart1Init(void)   //��ʼ��������Ϊ9600
{
		AUXR &= 0xBF;		//��ʱ��1ʱ��ΪFosc/12,��12T
		AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
		PCON &= 0x7F;		//�����ʲ�����
		SCON  = 0x50;   //���ڷ�ʽ1, 8-n-1, �������.
		TMOD &= 0x0F;		//�����ʱ��1ģʽλ  
		TMOD |= 0x20;   //T1��ʽ2  
	
		TH1 = 0xFD;    //9600bps@11.0592MHz[/url]  
		TL1 = 0xFD;  
	
		ET1=0;
		TR1 = 1;                  
		ES  = 1;       //���ж�.  
		EA  = 1;
		TI=0;
		RI=0;
}

void Uart2Init(void)   
	//��ʼ��������Ϊ9600@11.0592M
	//TX=P1.3,RX=P1.2
{
	AUXR &= 0xF7;		//�����ʲ�����
	S2CON = 0x50;		//8λ����,�ɱ䲨����
	AUXR &= 0xFB;		//���������ʷ�����ʱ��ΪFosc/12,��12T
	BRT = 0xFD;		//�趨���������ʷ�������װֵ
	AUXR |= 0x10;		//�������������ʷ�����
	
    IP2H|=0x01;
	  IP2 |=0x01;
		IE2|= 1;       //��2�ж�.  
		EA  = 1;
}
/*
void ser_int (void) interrupt 4   
{  
	if(RI == 1) {
		RI = 0;//��������жϱ�־λ
		receiveData=SBUF;//�洢���յ�������
		if ((receiveData=='\r')||(receiveData=='\n')){
			position=0;
			recFlag=1;
		}
		else {
			p[position]=receiveData;
			position++;
		}
	}
}  
*/