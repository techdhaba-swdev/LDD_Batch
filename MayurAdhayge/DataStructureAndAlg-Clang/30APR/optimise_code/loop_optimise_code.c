#include<stdio.h>

void main()
{
	int sum=0,number=1000;
	for(int i=0;i<1000;i+2)
	{
		sum=sum+i;
		if ((sum+1)<1000)
		{
			sum=sum+(i+1);
		}
	}

	printf("sum of all code in ")


}
