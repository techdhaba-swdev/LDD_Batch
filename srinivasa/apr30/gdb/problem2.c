#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
	printf("modified value :%d\n",*x);
	free(x);
	clock_t end = clock();
	float time = ((float)(start - end ));
	printf("time taken :%f\n",time);
	return 0;
}
