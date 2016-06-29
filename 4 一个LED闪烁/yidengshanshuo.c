/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  名称：让灯闪烁十次后停止
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*   QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/
#include <reg51.h>

sbit led=P1^0;

void delay(unsigned int i)
{
	unsigned int j;
	unsigned char k;
	for(j=i;j>0;j--)
		for(k=125;k>0;k--);
}

void main()
{
	unsigned char m;
	for(m=20;m>0;m--)
	{
		led=~led;	//没隔一段时间即对输出取反。
		delay(3000); //闪烁间隔。
	}
	while(1); //闪烁十次后，到此不再闪烁。
}