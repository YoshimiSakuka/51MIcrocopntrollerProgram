/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  名称：用四个led指示实验板键盘最下面一排的四个按键状态。
			当按键按下时，对应led亮；松开后，对应led灭
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*   QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/
#include<reg51.h>

sbit s2=P3^4;
sbit s3=P3^5;
sbit s4=P3^6;
sbit s5=P3^7;
sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;
sbit led4=P1^3;

void main()
{
	while(1)
	{
		if(s2==0)
			led1=0;
		else
			led1=1;

		if(s3==0)
			led2=0;
		else
			led2=1;

		if(s4==0)
			led3=0;
		else
			led3=1;

		if(s5==0)
			led4=0;
		else
			led4=1;
	}
}