#include<reg51.h>
  
#define LCD_PORT P0 
  
// function prototypes
void converttochar(void);
void lcd_data_string(unsigned char *);
void delay(unsigned int );
void lcd_cmd(unsigned char );
void lcd_data(unsigned char );
void LCD_Init(void);
  
// LCD control pins declaration
sbit RS = P3^4;     // Register Select line
sbit RW = P3^5;  // Read/ADC_WRITEite line
sbit ENABLE = P3^6; // Enable line
  
int value1=0;
void main()
{

LCD_PORT = 0x00; //make P2 as outport
  
LCD_Init();
lcd_cmd(0x85);  // Setting cursor location at 5th position of the first line
delay(2);
  
lcd_data_string("BCD DOWN COUNT");
delay(100);
lcd_cmd(0x01);  // clear the LCD
delay(5);
lcd_cmd(0x80);	// move cursor to 1st row 1st column
while(1)
{
int n1 = 99; //count from 
int n2 = 81;	 //count to
int f =0;
int bcd;
int i =0; 
int a[8];
int k;
for(i= n1;i>=n2;i--)
{
f = i/10;
bcd = i + f*6;
delay(100);
lcd_cmd(0x01);
lcd_cmd(0x80);

for(k=0;k<8;k++)
{
a[k]=bcd&(0x80>>k);
if (a[k]>0)
lcd_data(49);
else
lcd_data(48);
}
}
}
}
  
  
  
void LCD_Init()
{
lcd_cmd(0x38);  //2 Line, 5X7 Matrix
delay(5);
lcd_cmd(0x0E);  //Display On, CuRSor Blink
delay(5);
lcd_cmd(0x06);
delay(5);
lcd_cmd(0x01);  // Clear Screen
delay(5);
}
  
void lcd_cmd(unsigned char Command) // LCD Command Sending Function declaration
{
LCD_PORT = Command;
RS= 0;
RW=0;
ENABLE = 1;
delay(1);
ENABLE = 0;
return;
}
  
void lcd_data(unsigned char data_value)  // LCD data Sending Function declaration
{
LCD_PORT = data_value;
RS= 1;
RW=0;
ENABLE = 1;
delay(1);
ENABLE = 0;
return;
}
  
void lcd_data_string(unsigned char *string) // LCD Command Sending String declaration
{
int i=0,j=0;
while(string[i]!='\0')
{
 if(i>=9)
 { 
  // If the number of characters in the string > 16, then the below command automatically 
 lcd_cmd(0xc0+j++);  // Shift the display right side 
 }
  lcd_data(string[i]);
  i++;
  delay(2);
}
return;
}
 
void delay(unsigned int DELAY_VALUE ) // delay function
{
int i ,j ;
for(i=0;i<=DELAY_VALUE;i++)
 for(j=0; j<1275; j++);
}