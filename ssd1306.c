#include "ssd1306.h"


void sendCMD(uchar cmd){
	I2C_SOFT_START();
	I2C_SOFT_SEND(ADDR);
	I2C_SOFT_SEND(0x00);
	I2C_SOFT_SEND(cmd);
	I2C_SOFT_STOP();
}

void sendDAT(uchar dat){
	I2C_SOFT_START();
	I2C_SOFT_SEND(ADDR);
	I2C_SOFT_SEND(0x40);
	I2C_SOFT_SEND(dat);
	I2C_SOFT_STOP();
}

void OledInit(){
	sendCMD(0xAE);//--turn off oled panel
 	sendCMD(0x00);//---set low column address
 	sendCMD(0x10);//---set high column address
 	sendCMD(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	sendCMD(0xB0);
 	sendCMD(0x81);//--set contrast control register�Աȶ�
 	sendCMD(0xff); // Set SEG Output Current Brightness
 	sendCMD(0xa1);//--Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
 
	sendCMD(0xc8);//Set COM/Row Scan Direction   0xc0���·��� 0xc8����
 	sendCMD(0xa6);//--set normal display
 	sendCMD(0xa8);//--set multiplex ratio(1 to 64)
 	sendCMD(0x3f);//--1/64 duty
 	sendCMD(0xd3);//-set display offset Shift Mapping RAM Counter (0x00~0x3F)
 	sendCMD(0x00);//-not offset
	sendCMD(0xd5);//--set display clock divide ratio/oscillator frequency
 	sendCMD(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	sendCMD(0xd8);
	sendCMD(0x05);
	sendCMD(0xd9);//--set pre-charge period
 	sendCMD(0xf1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
 	sendCMD(0xda);//--set com pins hardware configuration
 	sendCMD(0x12);
 	sendCMD(0xdb);//--set vcomh
	sendCMD(0x30);
	
	sendCMD(0x40);//Set VCOM Deselect Level
 	sendCMD(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
 	sendCMD(0x02);//
 	sendCMD(0x8d);//--set Charge Pump enable/disable
	sendCMD(0x14);//--set(0x10) disable
 	sendCMD(0xa4);// Disable Entire Display On (0xa4/0xa5)
 	sendCMD(0xa6);// Disable Inverse Display On (0xa6/a7)
 	sendCMD(0xaf);//--turn on oled panel
}


void OledFill(uchar dat)  
{  
	uchar i,n;		    
	for(i=0;i<8;i++) //�ж��ٸ�ҳ 
	{  
		sendCMD (0xb0+i);    //����ҳ��ַ��0~1��
		sendCMD (0x00);      //������ʾλ�á��е͵�ַ
		sendCMD (0x10);      //������ʾλ�á��иߵ�ַ   
		for(n=0;n<128;n++)	
			sendDAT(dat); //ÿҳ�ж�����
	} //������ʾ
}

void displayBmp(uchar imgx,uchar imgy,uchar posX,uchar posY,uchar * bmp){
	uint i=0;
	sendCMD(0x20);//��������ģʽ
	sendCMD(0x00);//ˮƽģʽ
	
	sendCMD(0x22);//������ʼ�н�����
	sendCMD(posY);
	sendCMD(posY+(imgy/8-1));
	
	sendCMD(0x21);//������ʼ�н�����
	sendCMD(posX);
	sendCMD(posX+imgx-1);
	
	while (i<imgx*imgy/8)
	{
		sendDAT(*(bmp+i));
		i++;
		}
}