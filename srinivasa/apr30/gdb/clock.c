#include<stdio.h>
#include<time.h>
int main()
{
	clock_t start = clock();
	int sum = 0;
	for (int i = 0; i <=1000000; i++)
	{
		sum += i;
	}
	clock_t end = clock();
	double time_taken = ((double)(end - start));
	printf("sum = %d\n",sum);
	printf("time taken :%f",time_taken);
	return 0;
}
