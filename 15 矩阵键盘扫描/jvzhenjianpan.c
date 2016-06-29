/**********************SY-1实验开发板例程************************
*  平台：SY-1+STC89C52
*  4*4键盘检测程序,按下键后相应的代码显示在数码管上
*  公司：思源电子科技有限公司
*  编写：思源
*  日期：2012-12-25
*   QQ : 936559219
*  晶振:11.0592MHZ
******************************************************************/

#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit beep=P2^3;			//定义蜂鸣器的位
sbit duan=P2^6;			//573的锁存位
sbit wei=P2^7;			//573的锁存位
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
    P3=0xfe;			 //第一行扫描初值
    temp=P3;			 //P3的值给变量temp
    temp=temp&0xf0;		 //temp与0xf0按位与再赋值给temp
    if(temp!=0xf0)		 //如果temp测试不等于0xf0
    {
      delay_ms(10);		 //延时消抖
      if(temp!=0xf0)	 //如果temp仍然测试不等于0xf0
      {
        temp=P3;		 //把P3当前的按键值给temp
        switch(temp)	 //看看temp是什么值选择下面的其它一种情况
        {
          case 0xee:	 //情况1
               key=0;
               break;	 //退出

          case 0xde:	 //情况2
               key=1;
               break;	 //退出

          case 0xbe:	 //情况3
               key=2;
               break;	 //退出

          case 0x7e:	 //情况4
               key=3;
               break;	 //退出
         }
         while(temp!=0xf0) //当temp仍然不等于0xf0(就是按那个键还没有松手),就执行花括号里的语句
         {
           temp=P3;		   //松开之后就P3的值就回到刚刚的0xfe
           temp=temp&0xf0; //再后按位与
//           beep=0;
         }
         beep=1;		   // 松开了就停止蜂鸣器继续响
        display(key);	   //显示按键值
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
