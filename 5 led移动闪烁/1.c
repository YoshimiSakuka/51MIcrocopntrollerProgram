/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  名称：使八位LED逐位移动并不断循环
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*   QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/

#include <reg51.h>
#include <intrins.h>  //这个头文件是这个方法的核心，它包含了逐步移位函数功能
					  //即程序中的_crol_(P1,y)

sbit led=P1^0;

void delay(unsigned int i)
{
	unsigned int j;
	unsigned char k;
	for(j=i;j>0;j--)
		for(k=125;k>0;k--);
}

void main()
{	P1=0xfe;
	delay(1000);
	while(1)
	{
	//	unsigned char m;
		//P1=0xfe;
	//	delay(1000);
	//	for(m=7;m>0;m--)
		{
			P1=_crol_(P1,1);   //P1逐步左移一位。
			delay(1000);
		}
	}
}