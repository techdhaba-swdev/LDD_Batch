#include<stdio.h>
#include<time.h>
int main()
{
	clock_t start = clock();
	int arr[] = {1,2,3,4,5,6};
	for(int i = 0 ; i < 6 ; i++)
	{
		printf("array of [%d] : %d\n",i,arr[i]);
	}
	clock_t end = clock();
	double time = ((double)(start - end)) / CLOCKS_PER_SEC;
	printf("time taken %f\n",time);
}
