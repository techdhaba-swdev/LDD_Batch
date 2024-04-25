#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr=(int *)malloc(sizeof(int));
	printf("before free  %p\n",ptr);
        free(ptr);
        printf("after free %p\n",ptr);
	ptr=NULL;
        printf("after assigning null: %p\n",ptr);
}
