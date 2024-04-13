#include<stdio.h>

int fibonacci(int n)
{
	if(n==1||n==0)
		return n;
	else
	
		return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
	int fn;
	printf("Enter the number to calculate fibonacci series:");
	scanf("%d",&fn);
	printf("fibonacci series:\n");

	for(int i=0;i<fn;i++)
	{
		printf("%d\n",fibonacci(i));
	}
	return 0;
}
