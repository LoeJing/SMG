#include "reg51.h"
#include "extern.h"
#include "intrins.h"

void delay10us()
{
	_nop_();
//	TMOD &= 0xf0;
//	TL0 = 0xd0;
//	TH0 = 0xff;
//	TF0 = 0;
//	TR0 = 1;
}

void delay1ms()   //@6.000MHz
{
	unsigned char i;
	_nop_();
	i = 247;
	while (--i);
//	TMOD &= 0xf0;
//	TL0 = 0x80;
//	TH0 = 0x44;
//	TF0 = 0;
//	TR0 = 1;
}

void delayus(int us)
{
	int a;
	for(a=us;a!=0;a--)
	{
		delay10us();
	}
	
}

void delayms(int ms)
{
	int a;
	for(a=ms;a!=0;a--)
	{
		delay1ms();
	}
	
}