#ifndef __data__
#define __data__

#define uchar unsigned char
#define uint  unsigned int
#include <intrins.h>

unsigned char code num[]={"0123456789"};
unsigned char code *maths[14]={"+","-","*","/","=",
							  ".","^","%",">","<",
							  ">=","<="," "};
long num0,num1,num2,nume,fs=0;
float fnum0,fnum1,fnum2,fnume;
uchar flag=1;

void xs(long w);
void chuli();
void datas();
void flags();

void datas()
{
double fshu;
	if (3==flag||1==flag)
	{
		if(5==math||fs!=0)
		{
			if(0==fs)
			{
				zfc(".");
			}
			fshu=shu;
			num0=num0*10+fshu/fs;
			fs=fs*10;
		}
		else
		{
			num0=num0*10+shu;
			
		}
	}
}
void chuli()
{
	if (0==xmath)
	nume=num1+num2;
	if (1==xmath)
	nume=num1-num2;
	if (2==xmath)
	nume=num1*num2;
	if (3==xmath)
	{
		nume=num1/num2;
	}
	if(6==xmath)
	{
		nume=num1;
		while(num2>1)
		{	
			nume=nume*num1;
			num2--;
		}
		num1=0;
	}	   
}
void flags()
{
 		if (0==math||1==math||2==math||3==math||6==math||7==math)
		{
			flag++;
			if (4!=flag)
			{
				xmath=math;
				math=100;
			}
		}
		if (4==button)
		{
			flag=5;
		}
}
#endif