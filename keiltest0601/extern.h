#ifndef __EXTERN_H__
#define __EXTERN_H__
typedef struct 
{

	unsigned char min;
	unsigned char sec;
	unsigned char bms;	
}_calendar_obj;	

extern _calendar_obj calendar;	//½á¹¹Ìå

extern int temp;

extern void waitingkey(void);
extern unsigned char smg_duan;
extern unsigned char smg_wei;
extern void I2CStart();
extern void I2CStop();
extern bit I2CWrite(unsigned char dat);
extern unsigned char I2CReadNAK();
extern unsigned char I2CReadACK();
extern void delay10us();
extern void delay1ms();
extern void delayus(int us);
extern void delayms(int ms);
extern void segwrite(unsigned char duan,unsigned char wei);
extern void segwei(unsigned char num);
extern void segrefresh(void);


#endif