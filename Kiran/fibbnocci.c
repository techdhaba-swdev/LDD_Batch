#include<stdio.h>

int fibbn(int n)
{
	if(n<=1)
	{
		return n;
	}
	return fibbn(n -1) + fibbn(n-2);
}

int main()
{
	int n,i;
	
	printf("Enter the terms number: ");
	scanf("%d\n",&n);

	printf(" Fibbnacci Series\n ");
	for( i = 0;i < n; i++)
	{
		printf("%d\n",fibbn(i));
	}
	return 0;
}
