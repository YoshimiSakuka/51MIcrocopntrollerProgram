/**********************SY-1ʵ�鿪��������************************
*  ƽ̨��SY-1+STC89C52
*  ���ƣ���SY-1 ʵ���������������������ʾ����3
*  ��˾��˼Դ���ӿƼ����޹�˾
*  ��д��˼Դ
*  ���ڣ�2012-12-25
*   QQ : 936559219
*  ����:11.0592MHZ
******************************************************************/
#include <reg51.h>

sbit dula=P2^6;		//��ѡ�źŵ�����������
sbit wela=P2^7;		//λѡ�źŵ�����������

unsigned char code table[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf};
						//����ܸ�λ�����
void delay(unsigned int i)
{
	unsigned int m,n;
	for(m=i;m>0;m--)
		for(n=90;n>0;n--);
}

void main()
{
	unsigned char num;
	while(1)
	{
		for(num=0;num<6;num++)
		{
			P0=table[num];	   
			wela=1;
			wela=0;

			P0=0x4f;	  //���֡�3���Ĵ���
			dula=1;
			dula=0;
			delay(1000);
		}
	}
}

