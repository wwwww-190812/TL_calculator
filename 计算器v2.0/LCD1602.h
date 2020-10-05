
#ifndef __LCD_1602_CLIMBERWIN__
#define __LCD_1602_CLIMBERWIN__

#define uchar unsigned char
#define uint  unsigned int
#include <intrins.h>
#include"lcd1602define.h"
/******Port Definitions*****/
#define LCD_Data P0        //LCD�����ݿ�
sbit LCD_BF=LCD_Data^7;
sbit led1=P2^5;    //LCDæ�ź�λ
sbit LCD_RS = P2^0;
sbit LCD_RW = P2^1;
sbit LCD_EN = P2^2;

/*�����ӳ���*/
void LCD_ClrAll(void);              //����
void Judge_LCD_busy(void);           //����Ƿ�æµ
void LCD_Write(uchar WriteData);     //д������
void LCD_write_data(uchar LCD_data); //д������ʾ
void LCD_cursor(uchar x);    //�����ʼ��ַ
void zf(unsigned char lcd_data) ;  //���һ���ַ�
void zfc(unsigned char *lcd_string);//����ַ���

//void LCD_Back(void);

///*���ص�ԭ��*/    //����־��棿������
//void LCD_Back(void)
//{
 //LCD_Write(LCD_GO_HOME);
//}

//************************************************************************
/*LCD1602æµ�ж��ӳ���*/
void Judge_LCD_busy(void)   //�ж�LCD1602�Ƿ�æ״̬
{
 while(1)
  {
   LCD_EN=0;
   LCD_RS=0;
   LCD_RW=1;
   LCD_Data=0xff;
   LCD_EN=1;   //EN �� 1��0 ʹ��
   if(!LCD_BF)break; //LCD_BF=1��ʾæµ����Ҫ�ȴ���
  }
   LCD_EN=0;
}
/******LCD����***************/
void LCD_ClrAll(void)
{

 Judge_LCD_busy();   //�ж��Ƿ�æµ
 LCD_RS=0;
 LCD_RW=0;
 LCD_Data=0x01;
 LCD_EN=1;
 LCD_EN=0;

}
/*******LCDд���ݶ������ģʽ*********/
void LCD_Write(uchar WriteData)   //дָ�LCD
{
 Judge_LCD_busy();
 LCD_RS=0;
 LCD_RW=0;

 LCD_Data=WriteData; //��WriteData�������͵����ݿ�
 LCD_EN=1;
 LCD_EN=0;
 }
/********LCD��ʾ����***********/
void LCD_write_data(uchar LCD_data)      //���һ���ֽ����ݵ�LCD
{
 Judge_LCD_busy();
 LCD_RS=1;
 LCD_RW=0;

 LCD_Data=LCD_data;
 LCD_EN=1;
 LCD_EN=0;
 }


/****���λ�õ�ȷ��***/
void LCD_cursor(uchar x)            //LCD��궨λ��x��
{
 LCD_Write(0x80+x);                       //��һ�е�ַ��0x80
}


/*���һ���ַ�*/
void zf(unsigned char lcd_data)
{
 LCD_write_data(lcd_data);
}

/*����ַ���*/
void zfc(unsigned char *lcd_string)
{
 unsigned char i=0;
 while(lcd_string[i]!=0x00)
  {
   LCD_write_data(lcd_string[i]);
   i++;
  }
}

/*��ʼ������*/
void LCD_initial(void)                        //��ʼ��LCD
{
 LCD_Write(LCD_AC_AUTO_INCREMENT|LCD_MOVE_DISENABLE);
 LCD_Write(LCD_DISPLAY_ON|LCD_CURSOR_OFF);
 LCD_Write(LCD_DISPLAY_DOUBLE_LINE);
 LCD_ClrAll();
}
void yh(unsigned char yi)
{
	LCD_cursor(0);   //�����ʼ��ַ ����һ�е�ַ��0x00~0x0F���ڶ��е�ַ��0x40~0x4f
	zf(yi);
}
void eh(unsigned char er)
{
	LCD_cursor(0x40);
	zf(er);
}
void ceh(unsigned char *cer)
{	
	LCD_cursor(0x40);
	zfc(cer);
}
void cyh(unsigned char *cyi )
{
	LCD_cursor(0);   //�����ʼ��ַ ����һ�е�ַ��0x00~0x0F���ڶ��е�ַ��0x40~0x4f
	zfc(cyi);

}
void cdp(unsigned char *cyi ,unsigned char *cer)
{
	LCD_cursor(0);   //�����ʼ��ַ ����һ�е�ַ��0x00~0x0F���ڶ��е�ַ��0x40~0x4f
	zfc(cyi);
	LCD_cursor(0x40);
	zfc(cer);
}
#endif
