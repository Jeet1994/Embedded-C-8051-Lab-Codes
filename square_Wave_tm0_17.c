	#include<reg51.h>
	void TM0_delay(void);
	void main ()
	{
	int i=0;
	P1=0x10;
	TMOD=0x01;
	while(1)
	{
		P1=~P1;
		for(i=0;i<20;i++)
		TM0_delay();
	}
   }
void TM0_delay()
{
TL0 = 0xFD;
TH0 = 0x4B;
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
}
