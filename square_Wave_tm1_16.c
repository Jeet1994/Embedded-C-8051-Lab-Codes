	#include<reg51.h>
	void TM1_delay(void);
	void main ()
	{
	int i=0;
	P1=0x01;
	TMOD=0x10;
	while(1)
	{
		P1=~P1;
		for(i=0;i<20;i++)
		TM1_delay();
	}
   }
void TM1_delay()
{
TL1 = 0xFD;
TH1 = 0x4B;
TR1=1;
while(TF1==0);
TR1=0;
TF1=0;
}
