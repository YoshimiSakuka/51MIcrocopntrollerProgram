/**********************SY-1ʵ�鿪��������************************
*  ƽ̨��SY-1+STC89C52
*  4*4���̼�����,���¼�����Ӧ�Ĵ�����ʾ���������
*  ��˾��˼Դ���ӿƼ����޹�˾
*  ��д��˼Դ
*  ���ڣ�2012-12-25
*   QQ : 936559219
*  ����:11.0592MHZ
******************************************************************/

#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit beep=P2^3;			//�����������λ
sbit duan=P2^6;			//573������λ
sbit wei=P2^7;			//573������λ
uchar i=100;
uchar j,k,temp,key;
void delay_ms(uint k)
 {
  uint i,j;
  for(i=0;i<k;i++)
   {
    for(j=0;j<113;j++)
	 {
	  ;
	  }
	}
  }
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,
                        0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
display(uchar num)
{
         P0=table[num];
         duan=1;
         duan=0;
         P0=0xc0;
         wei=1;
         wei=0;
}
void main()
{
  duan=0;
  wei=0;
  while(1)
  {
    P3=0xfe;			 //��һ��ɨ���ֵ
    temp=P3;			 //P3��ֵ������temp
    temp=temp&0xf0;		 //temp��0xf0��λ���ٸ�ֵ��temp
    if(temp!=0xf0)		 //���temp���Բ�����0xf0
    {
      delay_ms(10);		 //��ʱ����
      if(temp!=0xf0)	 //���temp��Ȼ���Բ�����0xf0
      {
        temp=P3;		 //��P3��ǰ�İ���ֵ��temp
        switch(temp)	 //����temp��ʲôֵѡ�����������һ�����
        {
          case 0xee:	 //���1
               key=0;
               break;	 //�˳�

          case 0xde:	 //���2
               key=1;
               break;	 //�˳�

          case 0xbe:	 //���3
               key=2;
               break;	 //�˳�

          case 0x7e:	 //���4
               key=3;
               break;	 //�˳�
         }
         while(temp!=0xf0) //��temp��Ȼ������0xf0(���ǰ��Ǹ�����û������),��ִ�л�����������
         {
           temp=P3;		   //�ɿ�֮���P3��ֵ�ͻص��ոյ�0xfe
           temp=temp&0xf0; //�ٺ�λ��
//           beep=0;
         }
         beep=1;		   // �ɿ��˾�ֹͣ������������
        display(key);	   //��ʾ����ֵ
      }
    }
    P3=0xfd;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay_ms(10);
      if(temp!=0xf0)
      {
        temp=P3;
        switch(temp)
        {
          case 0xed:
               key=4;
               break;

          case 0xdd:
               key=5;
               break;

          case 0xbd:
               key=6;
               break;

          case 0x7d:
               key=7;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
//           beep=0;
         }
         beep=1;
         display(key);
      }
      }
    P3=0xfb;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay_ms(10);
      if(temp!=0xf0)
      {
        temp=P3;
        switch(temp)
        {
          case 0xeb:
               key=8;
               break;

          case 0xdb:
               key=9;
               break;

          case 0xbb:
               key=10;
               break;

          case 0x7b:
               key=11;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
//           beep=0;
         }
         beep=1;
        display(key);
      }
      }
    P3=0xf7;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay_ms(10);
      if(temp!=0xf0)
      {
        temp=P3;
        switch(temp)
        {
          case 0xe7:
               key=12;
               break;

          case 0xd7:
               key=13;
               break;

          case 0xb7:
               key=14;
               break;

          case 0x77:
               key=15;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
//           beep=0;
         }
         beep=1;
        display(key);
      }
    }
  }
}
