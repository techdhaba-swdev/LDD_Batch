#include<stdio.h>
int main()
{
	int* ptr = (int*)malloc(sizeof(int));
	free(ptr);
	*ptr = 42;
	printf("value stored: %d\n",*ptr);
	return 0;
}

