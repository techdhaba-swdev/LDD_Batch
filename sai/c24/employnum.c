#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *employnum = (int*)malloc(sizeof(int));
	printf("%d\n", employnum);
	printf("employnum %p\n",employnum);
	free(employnum);
	printf("memory %p\n",employnum);
	*employnum = 555;
	printf("memory %p\n",employnum);
	return 0;
}
