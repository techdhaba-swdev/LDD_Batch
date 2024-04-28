#include<stdio.h>

#define square(x) (x*x)

int main()
{

	int num = 5;

        for (int i = num; i <= 10; i++)
	{
	  printf("Value of %d is %d\n",i , square(i));
           }
}	
