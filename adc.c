
#include< reg51.h>

sbit rs=P3^4;   //Register select (RS)
sbit rw=P3^5;	//R/W 
sbit en=P3^6;   //Enable (EN) pin
sbit ALE= P2^4;
sbit OE=  P2^5;
sbit SC=  P2^6;
sbit EOC= P2^7;
sbit ADDR_A= P2^0;
sbit ADDR_B= P2^1;
sbit ADDR_C= P2^2;

//char cel[]="CELSIUS TEMP";
//char far[]="FAHRENHEIT TEMP";
int i,j;

void delay(unsigned int time)  //Time delay function
{
unsigned int i,j;
for(i=0;i< time;i++)
  for(j=0;j<5;j++);
}
void lcdcmd(unsigned char value)  //Function for sending values to the command register of LCD
{

P0=value;
rs=0;
rw=0;
en=1;
delay(50);
en=0;
delay(50);
return;
}
void display(unsigned char value)  //Function for sending values to the data register of LCD
{
P0=value;
rs=1;
rw=0;
en=1;
delay(500);
en=0;
delay(50);
return;
}

void lcdint(void)         //function to initialize the registers and pins of LCD
{
P1=0xFF;
P2=0x00;                 
P3=0x00;
 //	delay(15000);
//   	display(0x30);
//     delay(4500);
 //  	display(0x30);
  //   delay(300);
 //  	display(0x30);
 //    delay(650);
	lcdcmd(0x38);
	delay(50);
    lcdcmd(0x0E);
	delay(50);
    lcdcmd(0x01);
	delay(50);
    lcdcmd(0x06);
	delay(50);
    lcdcmd(0x80);
	delay(50);
}

void main()
{
 unsigned int Adcvalue,Adcvalue1,i;
 char ch1,ch2,ch3;
 P0=0x00;              //Declared as Output port
 P3=0x00;             //Output port
 P1=0xFF;             //Input port
 P2=0x00;             //Output port lcdint();
 while (1)
  {
	delay(10000);
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
	Adcvalue=P1;
	ch1=Adcvalue/100;
	if(ch1!=0)
	lcdcmd(0x82);
	delay(50);
	display(ch1+0x30);
	delay(100);
	Adcvalue1=Adcvalue%100;
	ch2=Adcvalue1/10;
	lcdcmd(0x81);
	delay(50);
	display(ch2+0x30);
	ch3=Adcvalue1-(ch2*10);
	lcdcmd(0x80);
	delay(50);
	display(ch3);
	delay(10000);
	lcdcmd(0x01);




}
}
