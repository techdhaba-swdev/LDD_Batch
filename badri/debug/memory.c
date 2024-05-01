#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void allocate_and_modify(int **ptr)
{
	int *temp = (int *)malloc(sizeof(int));
	*temp = 10;
	*ptr = temp;
}
int main()
{
	clock_t start = clock();
	int *x = NULL;
	allocate_and_modify(&x);
	printf("Modified value:%d\n",*x);
	clock_t end = clock();
	double time_taken = ((double)(start - end)) / CLOCKS_PER_SEC;
	printf("time used %f\n",time_taken);
	free(x);
	return 0; 
}
