#include<reg51.h>

void delay(unsigned int DELAY_VALUE ) // delay function
{
int i ,j ;
for(i=0;i<=DELAY_VALUE;i++)
 for(j=0; j<1275; j++);
}
void left_blink()
{
int left_byte;
int i;
for(i =0;i<8;i++)
	{
	left_byte = 0x01;
	left_byte = left_byte<<i;
	P1 = ~left_byte;
	delay(100);
	}
}
void right_blink()
{
int right_byte;
int i;
for(i =0;i<8;i++)
	{
	right_byte = 0x80;
	right_byte = right_byte>>i;
	P1 = ~right_byte;
	delay(100);
	}
}

 void main()
 {
 P1= 0x00;  //OUTPUT

while(1)
{
left_blink();
right_blink();
}
}