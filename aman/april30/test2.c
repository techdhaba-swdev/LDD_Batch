#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void allocate_and_modify(int **ptr){
	int *temp = (int *)malloc(sizeof(int));
	*temp = 10;
	*ptr = temp;
}
int main(){
	clock_t start = clock();
	int *x = NULL;
	allocate_and_modify(&x);
	clock_t stop = clock();
	double time_taken = ((double)(stop-start));
	printf("time taken: %f\n", time_taken);
	printf("Modified value: %d\n", *x);
	free(x);
	return 0;
}
