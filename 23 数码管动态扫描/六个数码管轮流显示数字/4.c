/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  名称：让SY-1 实验板的六位数码管轮流显示数字0到5
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*   QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/
#include <reg51.h>

sbit dula=P2^6;		//段选信号的锁存器控制
sbit wela=P2^7;		//位选信号的锁存器控制

unsigned char code wei[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf};
						//数码管各位的码表
unsigned char code duan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d};
						//0-5的码表
void delay(unsigned int i)
{
	unsigned int m,n;
	for(m=i;m>0;m--)
		for(n=90;n>0;n--);
}

void main()
{
	unsigned char num;
	while(1)
	{
		for(num=0;num<6;num++)
		{
			P0=wei[num];	   
			wela=1;
			wela=0;

			P0=duan[num];	  
			dula=1;
			dula=0;
			delay(1000);
		 }
	}
}

