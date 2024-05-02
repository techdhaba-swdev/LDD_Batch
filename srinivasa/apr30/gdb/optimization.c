#include<stdio.h>
#include<time.h>

int main()
{       clock_t start = clock();
	int sum = 0;
	int n = 1000;
	for (int i = 0; i < n; i += 2)
	{
		sum += i;
		if(i + 1 < n)
		{
			sum += i + 1;
		}
	}
	clock_t end = clock();
	double time_taken = ((double )(end -start));
	printf("sum : %d\n",sum);
	printf("time taken :%f\n",time_taken);
	return 0;
}
