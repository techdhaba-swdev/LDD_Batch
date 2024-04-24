#include<stdio.h>
#include<stdlib.h>

int main()
{
	int* ptr = (int*)malloc(sizeof(int));
	printf("%d\n",*ptr);
	free(ptr);
	printf("Memory allocated:%d\n", ptr);
	*ptr = 42;
	printf("Memory allocated:%d\n", ptr);
	return 0;
}

