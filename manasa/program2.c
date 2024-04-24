#include<stdio.h>
#include<stdlib.h>

int main() {
	int* ptr = (int*)malloc(sizeof(int));
	free(ptr);
	printf("memory deallocated.\n");
	*ptr = 42;
	return 0;
}

