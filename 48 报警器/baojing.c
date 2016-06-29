/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  名称：按下SY-1 实验板上的S2按键时（一直按着），会发出频率为1000HZ和2000HZ交替
			的信号，通过蜂鸣器发出类似于救护车发出的报警声
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*   QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/

#include <reg51.h>
#include <intrins.h>

#define uchar unsigned char 
#define uint unsigned int

sbit beep=P2^3;
sbit kaiguan=P3^4;

void delay()		   //大概0.5ms左右的延时
{
	uchar a;
	for(a=450;a>0;a--)
	{
		_nop_();
	}
}
void main()
{
	while(1)
	{
		if(!kaiguan)
		{
			uint m;
			for(m=800;m>0;m--)	  //持续时间0.5ms*800
			{
				beep=~beep;		
				delay();		 //2000HZ的信号。
			}
			for(m=500;m>0;m--)	 //持续时间0.5ms*2*500
			{
				beep=~beep;
				delay();
				delay();		//1000HZ的信号。
			}
		}
	}
}