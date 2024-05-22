#include<stdio.h>

int main(){
	int n,i,count = 0;

	printf("Enter the number :\n");
	scanf("%d",&n);

	for ( i = 2; i <= n; i++)
	{
		if(n%i == 0)
		{
			count++;
		}
	}
	int temp = count;
	if(temp == 1)
	{
		printf(" %d is prime number\n",n);
	}
	else
	{
             printf("%d is non-prime number\n",n);
	}
	return 0;
}
