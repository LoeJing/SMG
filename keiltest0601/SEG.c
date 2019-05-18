#include "reg51.h"
#include "extern.h"

sbit SEGA0 = P2^3;
sbit SEGA1 = P2^4;
sbit SEGA2 = P2^5;
sbit STCP = P3^0;
sbit SHCP = P3^4;
sbit QS = P3^5;


void segwei(unsigned char num)
{ 
	SEGA0=num&0x01; 
	SEGA1=(num&0x02)>>1; 
	SEGA2=(num&0x04)>>2; 
}

void segwrite(unsigned char duan,unsigned char wei)
{
	unsigned char i;
	for(i=0;i<8;i++)//先送段
	{
		QS=(duan>>i)&0x01;
		SHCP=0;
		delayus(20);
		SHCP=1;
	}
    segwei(wei);//后选中位
}
//74HC595驱动
//数码管刷新显示
void segrefresh(void)
{
	STCP=1;
	delayus(20);
	STCP=0;
}

//void seginit(void)
//{
//	char i = 0;
//	for(i=0;i<6;i++)
//	{
//		segwrite(i)
//	
//	}
//}