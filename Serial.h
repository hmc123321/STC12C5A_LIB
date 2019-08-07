#include <stdio.h>
#include <stc12c5a.h>
#ifndef SERIAL_H
#define SERIAL_H

#ifndef uchar
#define uchar unsigned char
#endif
#ifndef uint	
#define uint unsigned int
#endif	

#define NONE_PARITY     0   //None parity
#define ODD_PARITY      1   //Odd parity
#define EVEN_PARITY     2   //Even parity
#define MARK_PARITY     3   //Mark parity
#define SPACE_PARITY    4   //Space parity
#define PARITYBIT EVEN_PARITY   //Testing even parity

//void PutString(unsigned char *TXStr);
void putChar(char a,unsigned char TXStr);
//void Send2Data(unsigned char dat);
//void Send1Data(unsigned char dat);
void SendString(char a,char *s);
void Uart1Init(void);
void Uart2Init(void);
#endif
