#include<reg51.h>
  
#define LCD_PORT P0 
#define ADC_DATA P1
  
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
  
// ADC control pins declaration

sbit ALE= P2^4;
sbit OE=  P2^5;
sbit SC=  P2^6;
sbit EOC= P2^7;
sbit ADDR_A= P2^0;
sbit ADDR_B= P2^1;
sbit ADDR_C= P2^2;





//sbit ADC_READ= P3^0;
//sbit ADC_WRITE= P3^1;
//sbit ADC_INTR= P3^2;
  
int value1=0;
void main()
{
ADC_DATA = 0xff; // make P1 as input port
LCD_PORT = 0x00; //make P2 as outport
  
LCD_Init();
lcd_cmd(0x85);  // Setting cursor location at 5th position of the first line
delay(2);
  
lcd_data_string("ADC VALUE");
delay(100);
lcd_cmd(0x01);
delay(5);
lcd_cmd(0x80);
delay(5);
lcd_data_string("VOLTAGE:");
while(1)
{
  delay(5);

 	ADDR_A=0;
	ADDR_B=0;
	ADDR_C=0;
	delay(1);
	ALE=1;
	delay(1);
	SC=1;
	delay(1);
	ALE=0;
	SC=0;

	while(EOC==1); 
	while(EOC==0);                         //when intr==0 it jumps to next iteration
                    //read the digital output from adc
	value1=ADC_DATA;
  	delay(5);
  //	ADC_INTR=1;
  	converttochar(); 
  
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
  
void converttochar()
{
int M;
 value1= value1*1.95;
 M=value1/100;  
 value1=value1%100;	  
 lcd_cmd(0x8a);
 if(M!=0)
 lcd_data(M+48);
 else
 lcd_data(48);
 lcd_data(46);
 M=value1/10;
 value1=value1%10;
 lcd_data(M+48);
 lcd_data(value1+48);
 lcd_data(' ');
 delay(5);
}
  
void delay(unsigned int DELAY_VALUE ) // delay function
{
int i ,j ;
for(i=0;i<=DELAY_VALUE;i++)
 for(j=0; j<1275; j++);
}