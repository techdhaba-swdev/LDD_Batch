#include <stdio.h>
#include <time.h>

int main()
{
	//Start the clock
	
	clock_t start = clock();

	//code whose timecomplexity you want to measure
	//for example let's calculate the sum of first 1000 numbers
	
	int sum = 0;
	for(int i = 1; i<=1000 ; i++)
	{
		sum += i;
	}

	//stop the clock
	
	clock_t end = clock();

	//calculate the elapsed time 
	
	double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

	printf("Sum of first 1000 numbers: %d\n",sum);
	printf("Time taken : %f seconds\n",time_taken);

	return 0;
}
