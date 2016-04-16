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
int a[4];
int i;
for(i=0;i<4;i++)
	{
		a[i]= 1.25*i ;	
		a[i] = a[i]*51.2;
		
	}

while(1)
{
	for(i=0;i<4;i++)
		{
		  P0 = a[i];
		  delay(4);   // frequency setting
		}
}

}


