#include<reg51.h>
sbit RS = P3^4;	
sbit RW = P3^5;	 
sbit EN = P3^6;	 
sbit sign=P0^7; 

void delay(unsigned int del)
{	
	unsigned int i;
	for(i=0;i<del;i++);
}
void lcd_cmd(unsigned char val)
{
	P0 = val;
	RS = 0;
	RW = 0;
	EN = 1;
	delay(50);
	EN = 0;
	delay(250);
}

void lcd_data(unsigned char val)
{
	P0 = val;
	RS = 1;
	RW = 0;
	EN = 1;
	delay(50);
	EN = 0;
	delay(250);
}


void main()
{
	signed char d=0x3C;
        lcd_cmd(0x38);		//to enable LCD
		lcd_cmd(0x0E);			//Display on, blinking cursor
		lcd_cmd(0x01);			//clears display screen
		lcd_cmd(0x06); 			//enables forward incrementing
		lcd_cmd(0x80);			//displays at first line first position
 d=~d;
 d=d+1;
 if(d>=0)
 {
  lcd_data('+');
	  for( unsigned int i=0; dig!=0; i++)
 {
  a[i]= dig%10;
  dig=dig/10;
  
  lcd_data((0x30)+a[i]);
 }
  lcd_data((0x30)+(d));
 }
 else
 { lcd_data('-');
   sign=0;
   lcd_data((0x30)+(d));
 }
}
 
            