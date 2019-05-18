#include "reg51.h"
#include "extern.h"

_calendar_obj calendar;

int temp = 0;
unsigned char smg_duan = 0;
unsigned char smg_wei = 0;
unsigned char num=0;
unsigned char SEG7[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};
unsigned char SEG7POINT[]={0xfd,0x61,0xdb,0xf3,0x67,0xb7,0xbf,0xe1,0xff,0xf7};



void timeread(void)
{
	calendar.min=temp/600; 	
	calendar.sec=(temp%600)/10;
	calendar.bms=(temp%600)%10;

}

void timer0()          //2ms中断
{
	TMOD |= 0x01;
	TL0 = 0x18;
	TH0 = 0xFC;
	TF0 = 0;
  ET0=1;
	TR0 = 1;
}
void RTC1()
{
	TMOD|=0x10;
	TH1 = 0X3c;
	TL1 = 0xb0;
	ET1 = 1;
	TR1 = 1;
}

void main()
{
	timer0();
	RTC1();
	EA=1;
	while(1)
	{
		//waitingkey();
	}
}

void intersegdisplay() interrupt 1
{
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
  ET0=1;          //定时器T0中断允许
	timeread();
	temp++;
	switch(smg_wei)
	{
		case 0:  num = 0x00; 												break;
		case 1:  num = SEG7[calendar.min/10]; 			break;
		case 2:  num = SEG7POINT[calendar.min%10];  break; 
		case 3:  num = SEG7[calendar.sec/10]; 			break;
		case 4:  num = SEG7POINT[calendar.sec%10];	break;
		case 5:  num = SEG7[calendar.bms]; 	 				break;
	}
		segwrite(num,smg_wei);
		segrefresh();
		smg_wei++;
		if(smg_wei==6) smg_wei=0;
	
}
void INQP() interrupt 3
{
	TMOD|=0x10;
	TH1=0X3c;
	TL1=0xb0;
	TR1=1;
	ET1=1;
	//temp++;
	
}

//		int i = 0;
//		for(i=0;i<8;i++)
//		{
//			segwrite(SEG7[i],smg_wei);
//			segrefresh();
//			smg_wei++;
//			if(smg_wei==8)  smg_wei=0;
//		}

//		while(1);
