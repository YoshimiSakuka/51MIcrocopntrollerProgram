/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  名称：流水灯1
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*   QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/
#include<reg52.h>
#include<intrins.h>

void delay(unsigned char i)
{
	unsigned char m,n;
	for(m=i;m>0;m--)
	for(n=125;n>0;n--);
}

void main()
{	unsigned char k;
while(1)
{
	P1=0xfe;
	for(k=0;k<8;k++)
	{
	delay(2000);
	P1=_crol_(P1,1); //crol(left)左移一位，引用intrins.h头文件
	}
}
}