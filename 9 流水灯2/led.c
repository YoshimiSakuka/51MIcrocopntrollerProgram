/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  实验：流水灯2
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*   QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/
#include<reg52.h>

void delay(unsigned char i)
{
	unsigned char m,n;
	for(m=i;m>0;m--)
	for(n=125;n>0;n--);
}

void main()
{	while(1)
{
	P1=0x7e;
	delay(2000);
	P1=0xbd;
	delay(2000);
	P1=0xdb;
	delay(2000);
	P1=0xe7;
	delay(2000);
	P1=0xdb;
	delay(2000);
	P1=0xbd;
	delay(2000);
	P1=0x7e;
	delay(2000);
}
}