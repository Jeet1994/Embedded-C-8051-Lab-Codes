			   #include<reg51.h>
sbit RS = P3^4;	
sbit RW = P3^5;	 
sbit EN = P3^6;	 



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
void show_hex(int k)
{		
int i=k%16;

int j=k/16;
lcd_data('0');
lcd_data('x');
if(j<10)
lcd_data((0x30)+j);
if(j>=10)
{
switch(j)
{
case 10: 
lcd_data('a');
break;

 case 11: 
lcd_data('b');
break;

case 12: 
lcd_data('c');
break;

case 13: 
lcd_data('d');
break;

case 14: 
lcd_data('e');
break;

case 15: 
lcd_data('f');
break;
}}
if(i<10)
lcd_data((0x30)+i);
else{

switch(i)
{
case 10: 
lcd_data('a');
break;

 case 11: 
lcd_data('b');
break;

case 12: 
lcd_data('c');
break;

case 13: 
lcd_data('d');
break;

case 14: 
lcd_data('e');
break;

case 15: 
lcd_data('f');
break;
}}}


void show_number(int k)
{
	int d1,d2,d3;
	d1=k%10;
	k=k/10;
	d2=k%10;
	k=k/10;
	d3=k%10;
	lcd_data((0x30)+d3);
	lcd_data((0x30)+d2);
	lcd_data((0x30)+d1);
}
void main()
{
	unsigned char k=0x6a;
	unsigned char b=k,c=k;
	k=k&(0x0f);
	if(k>=0x0a)
	k=k+(0x37);
	if(k<0x0a)
	k=k+30;
	b=b&(0xf0);
	b=b/(0x10);
	if(b>=0x0a)
	b=b+(0x37);
	else
	b=b+(0x30);
	


	


        lcd_cmd(0x38);		//to enable LCD
		
		lcd_cmd(0x0E);			//Display on, blinking cursor
		lcd_cmd(0x01);			//clears display screen
		lcd_cmd(0x06); 			//enables forward incrementing
		lcd_cmd(0x80);			//displays at first line first position
		show_hex(c);
		lcd_data('-');
		lcd_data('>');
		show_number(b);
		lcd_data('&');
		show_number(k);

								 
		

			
}