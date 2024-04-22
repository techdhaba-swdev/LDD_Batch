#include<stdio.h>
#include"evenodd.h"
int even(int a)
{
	if(a%2==0)
		printf("%d is a even number\n",a);
	else
		printf("%d is odd number\n",a);
}
