#include <stdio.h>
#include <time.h>
int main()
{
	clock_t start = clock();
	int arr[] = {1,2,3,4,5};

	int size = sizeof(arr) / sizeof(arr[0]);

	for(int i = 0 ; i<=size ; i++)
	{
		printf("%d" , arr[i]);
	}
	printf("\n");
	clock_t end = clock();
	double time_used = ((double) (start-end)) /CLOCKS_PER_SEC ;
	printf("time taken : %f\n",time_used);
	return 0;
}

