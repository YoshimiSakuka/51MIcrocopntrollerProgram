/**********************SY-1ʵ�鿪��������************************
*  ƽ̨��SY-1+STC89C52
*  ���ƣ�ѧϰ��ĵ�һ���������ʾ����0��F
*  ��˾��˼Դ���ӿƼ����޹�˾
*  ��д��˼Դ
*  ���ڣ�2012-12-25
*   QQ : 936559219
*  ����:11.0592MHZ
******************************************************************/

#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit duan=P2^6;		//��ѡ�źŵ�����������
sbit wei=P2^7;		//λѡ�źŵ�����������

unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,
                        0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
						//0-F�����
void delay_ms(uint k)
{
	uint i;
	uchar j;
	for(i=0;i<k;i++)
		for(j=0;j<230;j++)
		{
		 ;
		 }
}

void main()
{
	uchar num;
	while(1)
	{
		for(num=0;num<16;num++)
		{
			P0=table[num];	   
			duan=1;
			duan=0;
			P0=0xdf;
			wei=1;
			wei=0;
			delay_ms(1000);
		}
	}
}

