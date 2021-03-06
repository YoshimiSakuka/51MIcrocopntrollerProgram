/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  名称：用逐位赋值的方法点亮第一、第三、第五、第七个发光二极管
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*  QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/


#include <reg51.h> //包含头文件，在“reg51.h”上右键单击，并打开，可以看到它里面的定义

sbit led1=P1^0;	 //第一个led是和P1^0口连接的。
sbit led3=P1^2;
sbit led5=P1^4;
sbit led7=P1^6;

void main()
{
	led1=0;	   //参照电路图可知，P1^0为低电平，可以让led1点亮。
	led3=0;
	led5=0;
	led7=0;
	while(1);//此处设置一个死循环，让程序停留在这里，防止跑飞。
}

