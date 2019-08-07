#include "IIC.h"
       
//delay ----------------------------------------------------------------------
void delayus()
{
        uchar i=6;
        while(i--);
}

/*
void delayms()
{
        uchar i,j;
        i = 32;
        j = 40;
        while (j--)
        {        while (i--);
        }
        }
*/



//I2C init ----------------------------------------------------------------------

void I2C_SOFT_START() //���ģ��I2C ��ʼ�ź�
{
        SDA = 1;
        //delayus();
        SCL = 1;
        //delayus();
        SDA = 0;
        //delayus();
        SCL = 0;
        SDA = 1;
}


void I2C_SOFT_STOP() //���ģ��I2C ֹͣ�ź�
{
        SDA = 0;
        //delayus();
        SCL = 1;
        //delayus();
        SDA = 1;
        //delayus();
        SCL =0;
        SDA = 1;
}




void I2C_SOFT_SEND(uchar S_SND)   //���ģ��I2C��д1�ֽ�����
{
  unsigned char i,j,SOFT_ACK,SND;
  SOFT_ACK = 1;
	while (SOFT_ACK)       
	{
    SND = S_SND;
			for (i=8;i!=0;i--)
        {
          if(SND & 0X80)
						SDA = 1;
          else SDA = 0;
          SND <<=1;
//          delayus();
          SCL = 1;
//          delayus();
          SCL=0;
//          delayus();
        }
      SDA =1;
//      delayus();
      SCL = 1;
      while(SDA)
      {
				j++;
       }
			if (j>=100){
					SOFT_ACK = 1; //�ж��Ƿ��ط�
				}
			else SOFT_ACK = 0;
			SCL=0;
		}
}