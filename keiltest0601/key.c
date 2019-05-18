#include "reg51.h"
#include "extern.h"

sbit BUZZ = P1^0;
sbit KEY0 = P1^1;
sbit KEY1 = P1^2;
sbit KEY3 = P1^3;

//void waitingkey(void)
//{
//	if(KEY0 == 0)
//	{
//		delayms()
//	}

//}
	
//			EA=1;
//		}
//		if(KEY == 0)
//		{
//			char i = 0;
//			EA =0;
//			for(i=0;i<6;i++)
//			{
//				segwrite(0x00,i);
//				segrefresh();
//			}
//			temp = 0;

//		}