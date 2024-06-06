#include<stdio.h>
#include<stdlib.h>

int main() {
	int *ptr = (int *)malloc(sizeof(int));
	*ptr = 5;
	printf("Value: %d\n", *ptr);
	free(ptr);
	return 0;
}

