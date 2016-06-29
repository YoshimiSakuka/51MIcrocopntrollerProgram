/**********************SY-1ʵ�鿪��������************************
*  ƽ̨��SY-1+STC89C52
*  ���ƣ������
*  ��˾��˼Դ���ӿƼ����޹�˾
*  ��д��˼Դ
*  ���ڣ�2012-12-25
*   QQ : 936559219
*  ����:11.0592MHZ
******************************************************************

//ע�����10��̳��е�LCD1602��5�����ڵ�ʱ��ƴ���ֱ�ӽӵ�GND���ˣ����˵͵�ƽ��
//��ʵ����Ҫ��LCD1602��5�ţ���/д�Žӵ�GND�ϣ������ַ�������һ�֣��öŰ��߰�P3.6�Žӵ�GND�ϡ�
//��һ�ַ���������һ�� P3.6 IO�ڣ����������� ��P3.6 дһ���͵�ƽ�Ϳ����ˡ�
//sbit WR = P3^6; �ں����������м��� WR=0;�Ϳ��Բ��ýӶŰ��ߣ� P3.6��GND�ĶŰ��߲�Ҫ��
//WR=0;

�����ܣ��������ģ����λ��ί�ı�����������жϣ��������ʾ��1602�ϡ�
		  ���õ�SY-1ѧϰ��������е�S6,S7,S10,S11,S14,S15,S18�߸�������
		  ����S18Ϊ���������1602���������Ͷ���ر������㡣
		  ÿλ��ί�ٿ������������ֱ����ͨ�����͡���ͨ������
		  ��һλ��ί����S6��ͨ������S7����ͨ������
		  �ڶ�λ��ί����S10��ͨ������S11����ͨ������
		  ����λ��ί����S14��ͨ������S15����ͨ������
		  ������ͨ�����������ڡ���ͨ����ʱ��1602����ʾ��yes����������ʾ��no����
		  ��һ���غ��У�ÿλ��ίֻ��һ�ΰ�����Ȩ����һ�����£���ٿص�����
		  �����������������ٰ�Ҳ�������κ����á����ǰ��������S18�����ʼ��һ�غϡ�

************************************************************************************/

#include<reg52.h>
#define uchar unsigned char 
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
sbit rs=P1^0;
sbit rw=P1^1;
sbit beep=P2^3;
sbit lcden=P2^5;

bit ok1,ok2,ok3,clear;

uchar pass,nopass,temp;
uchar table[]="yes";
uchar table1[]="no";
uchar table2[]="agree";
uchar table3[]="disagree";
uchar table4[]="   ";
uchar table5[]="  ";

void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}



void write_com(uchar com)
{
	rs=0;
	lcden=0;
	P0=com;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;	
}

void write_date(uchar date)
{
	rs=1;
	lcden=0;
	P0=date;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;	
}



void init()
{       
        rw=0;
//	uchar a;
	dula=0;
	wela=0;
	write_com(0x38);
	delay(20);
	write_com(0x0c);
	delay(20);
	write_com(0x06);
	delay(20);
	write_com(0x01);
	delay(20);
		
}

void yes()
{
	uchar a;
	write_com(0x80+12);
	delay(20);
	for(a=0;a<3;a++)
	{
		write_date(table[a]);
		delay(20);
	}
}

void no()
{
	uchar a;
	write_com(0x80+0x40+12);
	delay(20);
	for(a=0;a<2;a++)
	{
		write_date(table1[a]);
		delay(20);
	}
}

void agree()
{
	uchar a;
	write_com(0x80);
	delay(20);
	for(a=0;a<5;a++)
	{
		write_date(table2[a]);
		delay(20);
	}
}

void disagree()
{
	uchar a;
	write_com(0x80+0x40);
	delay(20);
	for(a=0;a<8;a++)
	{
		write_date(table3[a]);
		delay(20);
	}
}

void keyscan()
{
    if(!ok1)
	{ 
	P3=0xfe;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay(10);
      if(temp!=0xf0)
      {
        temp=P3;
		switch(temp)
        {
          case 0xee:
               pass++;
			   ok1=1;		//һ����ί���о���
               break;

          case 0xde:
               nopass++;
			   ok1=1;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
           beep=0;
         }
         beep=1;
      }
    }
	}
	if(!ok2)
	{
    P3=0xfd;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay(10);
      if(temp!=0xf0)
      {
        temp=P3;
        switch(temp)
        {
          case 0xed:
               pass++;
			   ok2=1;
               break;

          case 0xdd:
               nopass++;
			   ok2=1;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
           beep=0;
         }
         beep=1;
      }
      }
	  }
	if(!ok3)
	{
    P3=0xfb;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay(10);
      if(temp!=0xf0)
      {
        temp=P3;
        switch(temp)
        {
          case 0xeb:
               pass++;
			   ok3=1;
               break;

          case 0xdb:
               nopass++;
			   ok3=1;
               break;
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
           beep=0;
         }
         beep=1;
      }
      }
	  }
	      P3=0xf7;
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
    {
      delay(10);
      if(temp!=0xf0)
      {
        temp=P3;
        switch(temp)
        {
          case 0xe7:
               clear=1;
               break;
          
         }
         while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
           beep=0;
         }
         beep=1;
      }
    }
}

void main()
{
	uchar a,b;
	init();
	while(1)
	{	
		agree();
		disagree();
		keyscan();
		if(pass||nopass)
		{
			write_com(0x80+10);
			delay(20);
			write_date(0x30+pass);
			write_com(0x80+0x40+10);
			delay(20);
			write_date(0x30+nopass);
		}
		a=pass+nopass;
		if(a==3)
		{
			if(pass>nopass)
			yes();
			if(pass<nopass)
			no(); 
		}
		if(clear)
		{
			ok1=0;	ok2=0;	ok3=0;	
			pass=0;	nopass=0;	clear=0;	a=0;
			agree();
			disagree();
			write_com(0x80+10);
			delay(20);
			write_date(0x30+pass);
			write_com(0x80+0x40+10);
			delay(20);
			write_date(0x30+nopass);
	
			write_com(0x80+12);
			for(b=0;b<3;b++)
			{
				write_date(table4[b]);
				delay(20);
			}
			write_com(0x80+0x40+12);
			for(b=0;b<2;b++)
			{
				write_date(table5[b]);
				delay(20);
			} 
		} 	   
	}
}