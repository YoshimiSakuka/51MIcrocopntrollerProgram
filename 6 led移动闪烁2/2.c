/**********************SY-1ʵ�鿪��������************************
*  ƽ̨��SY-1+STC89C52
*  ���ƣ�ʹ��λLED��λ�ƶ�������ѭ�����÷�������������ֵ�ķ���
*  ��˾��˼Դ���ӿƼ����޹�˾
*  ��д��˼Դ
*  ���ڣ�2012-12-25
*   QQ : 936559219
*  ����:11.0592MHZ
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