/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  名称：生活中常见一个按键随着按下次数不同对应不同功能，
		   本程序以SY-1 学习板中的k1键为例，模拟其具有2种功能，
		   一是点亮一个发光二极管，二是蜂鸣器发声
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*   QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/

#include<reg52.h>

#define uchar unsigned char 
uchar num;

sbit beep=P2^3;
sbit led=P1^0;
sbit k1=P3^4;

void delay(uchar i)
{
	uchar j,k;
	for(j=i;j>0;j--)
	for(k=125;k>0;k--);
}


void main()
{
	while(1)
	{
		if(k1==0)
		{
			delay(20);		 //消抖
			if(k1==20)
			{
				while(!k1);	 //等待按键松开
				num++;
			}
			switch(num)
			{
				case 1: led=0;	beep=1; break;
				case 2: beep=0;	led=1;	num=0; break;
			}
		}
	}
}