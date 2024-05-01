#include <stdio.h>
#include <time.h>

int main()
{
	clock_t start = clock();
	int i;
	int sum = 0;

	for (i=0 ; i<= 10 ; i++)
	{
		sum = sum + i;
	}
	printf("The sum is:%d\n",sum);
	clock_t end = clock();
	double time_used = ((double)(start-end))/CLOCKS_PER_SEC;
	printf("time taken : %f\n",time_used);
	return 0;
}

