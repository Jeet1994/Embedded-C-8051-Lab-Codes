#include<reg51.h>
#include<math.h>


void delay(unsigned int DELAY_VALUE ) // delay function
{
int i ,j ;
for(i=0;i<=DELAY_VALUE;i++)
 for(j=0; j<1275; j++);
}

void main()
{
int a[50];
int i;
for(i=0;i<50;i++)
	{
		a[i]= 0.1*i ;	
		a[i] = a[i]*25.6;
		
	}

while(1)
{
	for(i=0;i<50;i++)
		{
		  P0 = a[i];
		  delay(2);
		}
}

}


