/**********************SY-1ʵ�鿪��������************************
*  ƽ̨��SY-1+STC89C52
*  ���ƣ���ˮ��1
*  ��˾��˼Դ���ӿƼ����޹�˾
*  ��д��˼Դ
*  ���ڣ�2012-12-25
*   QQ : 936559219
*  ����:11.0592MHZ
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
	P1=_crol_(P1,1); //crol(left)����һλ������intrins.hͷ�ļ�
	}
}
}