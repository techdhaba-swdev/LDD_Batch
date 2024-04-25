#include<stdio.h>
#include<stdlib.h>
void main(){
	int *ptr = (int*)malloc(sizeof(int));
	*ptr = 42;
	printf("value stored: %d\n", *ptr);
	free(ptr);
	return 0;
}
