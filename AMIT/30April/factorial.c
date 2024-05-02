#include<stdio.h>
#include<time.h>

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
	clock_t start = clock();
	int n=5;
	printf("factorial of %d is:%d\n",n,factorial(n));
       	clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

     printf("Time taken: %f seconds\n", time_taken);
	return 0;
}
	

