/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  名称：使八位LED逐位移动并不断循环，该方法采用逐个查表赋值的方法
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*   QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/
#include <reg51.h>



unsigned char table[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};

void delay(unsigned int i)
{
	unsigned int j;
	unsigned char k;
	for(j=i;j>0;j--)
		for(k=125;k>0;k--);
}

void main()
{
	while(1)
	{
		unsigned char m;
		for(m=0;m<8;m++)
		{
			P1=table[m];
			delay(2000);
		}
	}
}