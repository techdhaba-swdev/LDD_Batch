#include<stdio.h>
#include<stdlib.h>

void allocate_and_modify(int **ptr) {
	int *temp =(int *)malloc(sizeof(int));

	*temp =10;
	*ptr = temp;
}

int main(){
	int *x = NULL;
	allocate_and_modify(&x);

	printf("Modified value = %d\n",*x);
	free(x);

	return 0;
}
