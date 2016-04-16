#include<reg51.h>
#include<math.h>
  
#define LCD_PORT P0 

  
// function prototypes
void converttochar(int value2);
void lcd_data_string(unsigned char *);
void delay(unsigned int );
void lcd_cmd(unsigned char );
void lcd_data(unsigned char );
void LCD_Init(void);
//int pow (int x, int y);
//float sqrt(float s);
  
// LCD control pins declaration
sbit RS = P3^4;     // Register Select line
sbit RW = P3^5;  // Read/ADC_WRITEite line
sbit ENABLE = P3^6; // Enable line
  

void main()
{	
int i;
int a[5] = {34,43,12,56,78}	;
int min = a[0];
LCD_PORT = 0x00;
LCD_Init();
lcd_cmd(0x80);  
delay(2);

for(i=0;i<5;i++)
	{
	  if (a[i] < min)
	  	min = a[i] ;
	}
converttochar(min);
 while(1); 
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
  
void converttochar(int value2)
{
int M;
 M=value2/1000;  
 value2=value2%1000;	  
 lcd_data(M+48);
 M=value2/100;  
 value2=value2%100;	  
 lcd_data(M+48);
 delay(2);
 M=value2/10;
 value2=value2%10;
 lcd_data(M+48);
 delay(2);
 lcd_data(value2+48);
 lcd_data(32);
  }
void delay(unsigned int DELAY_VALUE ) // delay function
{
int i ,j ;
for(i=0;i<=DELAY_VALUE;i++)
 for(j=0; j<1275; j++);
}
