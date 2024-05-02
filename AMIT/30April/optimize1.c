#include<stdio.h>
#include<time.h>

int main()
{
	int sum= 0;
	int n= 1000;
	//original loop (less effective)
	/*for (int i=0; i<n;i++)
	{
		som+=i;
	}*/

	//unrolled loop (improve performance for small loop iterations)
	clock_t start = clock();


	for (int i=0;i<n;i+=2)
	{
		sum+=i;
		if(i+1<n)
		{
			sum+=i+1;
		}
	}

	printf("sum : %d \n",sum);
	// Stop the clock

    clock_t end = clock();

    // Calculate the elapsed time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sum of first 1000 numbers: %d\n", sum);

    printf("Time taken: %f seconds\n", time_taken);



	return 0;
}
