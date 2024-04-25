#include<stdio.h>
int main()
{
	int* ptr =(int*)malloc(sizeof(int));
	free(ptr);
	*ptr = 23;
	printf("value is :%d\n",*ptr);
	return 0;
}
