#ifndef __keyscan__
#define __keyscan__

#define uchar unsigned char
#define uint  unsigned int
#include <intrins.h>
uchar Key,keyz,shu,math=15,button=0,fuction=0,xmath=1;
char floatcan=0;


unsigned char keyscan();
void keyschu();
void delay50us(unsigned int us);
void delayms(unsigned int ms);
unsigned char keyscan()
{
	P3= 0xfe;
	P1=0xff;
	while(P1!=0xff)
	{
	    delayms(10);
        P1=0xff;
		while(P1!=0xff)
		{
			switch (P1)
			{
				case 0xbf:Key=1;break;
				case 0xdf:Key=2;break;
				case 0xef:Key=3;break;
				case 0xf7:Key=4;break;
				case 0xfb:Key=5;break;
				case 0xfd:Key=6;break;
				case 0xfe:Key=7;break;
			}				 
			keyz=1;
			while(P1!=0xff)  //À… ÷ºÏ≤‚
			{
			   P1=0xff;
			}
		}
	}
	P3= 0xfd;
	P1=0xff;
	while(P1!=0xff)
	{
	    delayms(10);
        P1=0xff;
		while(P1!=0xff)
		{
			switch (P1)
			{
				case 0xbf:Key=8;break;
				case 0xdf:Key=9;break;
				case 0xef:Key=10;break;
				case 0xf7:Key=11;break;
				case 0xfb:Key=12;break;
				case 0xfd:Key=13;break;
				case 0xfe:Key=14;break;
			}				 
			keyz=1;
			while(P1!=0xff)  //À… ÷ºÏ≤‚
			{
			   P1=0xff;
			}
		}
	}
	P3= 0xfb;
	P1=0xff;
	while(P1!=0xff)
	{
	    delayms(10);
        P1=0xff;
		while(P1!=0xff)
		{
			switch (P1)
			{
				case 0xbf:Key=15;break;
				case 0xdf:Key=16;break;
				case 0xef:Key=17;break;
				case 0xf7:Key=18;break;
				case 0xfb:Key=19;break;
				case 0xfd:Key=20;break;
				case 0xfe:Key=21;break;
			}				 
			keyz=1;
			while(P1!=0xff)  //À… ÷ºÏ≤‚
			{
			   P1=0xff;
			}
		}
	}
	P3= 0xf7;
	P1=0xff;
	while(P1!=0xff)
	{
	    delayms(10);
        P1=0xff;
		while(P1!=0xff)
		{
			switch (P1)
			{
				case 0xbf:Key=22;break;
				case 0xdf:Key=23;break;
				case 0xef:Key=24;break;
				case 0xf7:Key=25;break;
				case 0xfb:Key=26;break;
				case 0xfd:Key=27;break;
				case 0xfe:Key=28;break;
			}				 
			keyz=1;
			while(P1!=0xff)  //À… ÷ºÏ≤‚
			{
			   P1=0xff;
			}
		}
	}
	P3= 0xef;
	P1=0xff;
	while(P1!=0xff)
	{
	    delayms(10);
        P1=0xff;
		while(P1!=0xff)
		{
			switch (P1)
			{
				case 0xbf:Key=29;break;
				case 0xdf:Key=30;break;
				case 0xef:Key=31;break;
				case 0xf7:Key=32;break;
				case 0xfb:Key=33;break;
				case 0xfd:Key=34;break;
				case 0xfe:Key=35;break;
			}				 
			keyz=1;
			while(P1!=0xff)  //À… ÷ºÏ≤‚
			{
			   P1=0xff;
			}
		}
	}
return Key;	  
}
void keyschu()
{
	if (32==Key)
		shu=1;
	else if (25==Key)
		shu=2;
	else if (18==Key)
		shu=3;
	else if (33==Key)
		shu=4;
	else if (26==Key)
		shu=5;
	else if (19==Key)
		shu=6;
	else if (34==Key)
		shu=7;
	else if (27==Key)
		shu=8;
	else if (20==Key)
		shu=9;
	else if (28==Key)
		shu=0;
	else if (11==Key)
		math=0;	
	else if (12==Key)
		math=1;	
	else if (13==Key)
		math=2;	
	else if (14==Key)
		math=3;
	else if (21==Key)
		button=4;
	else if (35==Key)
		math=5;
	else if	(31==Key)
		math=6;
	else if	(24==Key)
		math=7;
	else if (3==Key)
		fuction=1;
}
void delay50us(unsigned int us)
{
     while(us--)
	 {
	    unsigned char i = 2;
	    while(i--)
		{
	      _nop_();
		}
		
	 }
}
void delayms(unsigned int ms)
{
   while(ms--)
   {
     unsigned char i =17;
     while(i--)
	 {
	    delay50us(1);
	 }
   }	     
}
#endif