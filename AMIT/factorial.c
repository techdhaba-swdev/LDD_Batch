#include<stdio.h>

int factorial(int n)
{
	int result=1;
	int i;
	for(i=2;i<=n;i++)
	{
		result*=i;
	}
	return result;
}

int main()
{
	int n=5;
	printf("factorial of %d is:%d\n",n,factorial(n));
	return 0;
}
	

