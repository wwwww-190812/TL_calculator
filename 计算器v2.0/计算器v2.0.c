/**************************
 单片机计算器
制作者：王天亮
制作时间：v1.0:2018年10月5日
		  v2.0:2018年10月19日
		  v2.1:2018年10月20日
**************************/
#include  <reg51.h>
#include <math.h>
#include <intrins.h>
#include "LCD1602.h"
#include "LCD1602define.h"
#include "KeyScan.h"
#include "data.h"
#define uchar unsigned char
#define uint  unsigned int		延时

void delay50us(unsigned int us);/*延时50us      */
void delayms(unsigned int ms);	/*延时 1ms      */
unsigned char keyscan();		/*按键扫描      */
void init();					/*初始化        */
void display();
void xs(long w);



/************主程序***************************/
main()
{
	LCD_initial();   //LCD初始化
	LCD_ClrAll();
	cdp("  TL calculator","     V2.1");
	delayms(1000);
	LCD_ClrAll();//LCD清屏
	init();     
	while(1)
	{
		keyscan();
		while(keyz)
		{
			keyschu();
			display();
			keyz=0;
		}
	}
}
void init()
{
	LCD_initial();   //LCD初始化
	LCD_ClrAll();
	math=100;
	shu=0;
	flag=1;
	xmath=1;
	num0=nume;
	nume=0;
	button=0;
}
void display()
{
	if(1==flag||3==flag)
	{
		if(5==math)
		{
			zfc(maths[5]);
		}
		else zf(num[shu%10]);
	}
	if(2==flag)
	{
		zfc(maths[xmath]);
	}
}
void xs(long w)
{
	uchar c=1,d=0;
	long q=1;
	while(c)
	{
		if(q*10<=w)
		{
			q=q*10;
		}
		else 
		{
			c=0;
		}
	}
	c=1;
	while(c)
		{
			zf(num[w/q%10]);
			q=q/10;
			if(0==q)
			{
				c=0;
			}
		}
}
