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
int a[36];
int i;
float k;
for(i=0;i<36;i++)
	{
		k = i*3.14/18;
		a[i]= sin(k)*5 + 5;
		a[i] = a[i]*25.6;
		
	}

while(1)
{
	for(i=0;i<36;i++)
		{
		  P0 = a[i];
			delay(3);
		}
}

}


