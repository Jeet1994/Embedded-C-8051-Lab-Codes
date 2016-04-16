/*
Display Largest number */
#include<reg51.h>
#include <stdio.h>       //Define I/O Functions
#define DATA P0          //Define DATA to Port2
sbit RS   = P3^4;        //Register Select
sbit RW   = P3^5;        //LCD Read/Write
sbit lcd_e = P3^6;       //LCD Enable
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_display(unsigned char);
void DelayMs(int);
void lcd_cmd(unsigned char cmnd)  
{
    DATA = cmnd;               //Masking lower 4 Bits
    RS = 0;  RW = 0;
    lcd_e = 1;
    DelayMs(500);
    lcd_e = 0;
}
void lcd_display(unsigned char dat)   
{
    DATA = dat;                            //Masking lower 4
    RS = 1;  RW = 0;
    lcd_e = 1;
    DelayMs(500);
    lcd_e = 0;
}
void DelayMs(int k)  
    {
    unsigned int a;
    for(a=0;a<=k;a++);
    }

void lcd_init(void)  
{
    unsigned char i;
  	 DATA=0x00; 
         lcd_cmd(0x38);                     //2x16 Character 5x7
         DelayMs(500);  //matrix LCD,4-bit format
         lcd_cmd(0x0c);                                     
         DelayMs(500);
         lcd_cmd(0x01);                                     //Shift
         DelayMs(500);
		  lcd_cmd(0x06);
		   DelayMs(500);
}

void main(void)
{
unsigned char A[5]={ 2,5,3,1,4};
unsigned char ans, i;
ans=A[0];
for (i=1; i<5; i++)
{
if(ans<A[i])
ans=A[i];
}
DATA= 0;
lcd_init();         //LCD Initialization
DelayMs(10000); 
lcd_display((0x30)+(ans));
while(1);            //Loop Forever
}