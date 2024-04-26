#include<stdio.h>
#include<stdlib.h>
int *allocate_array(int size)
{
	int *arr=(int*)malloc(size* sizeof(int));
	if(arr==NULL)
	{
		printf("memory allocation failed\n");
		exit(0);
	}
	return arr;
}
void main()
{
	int size;
	printf("enter the size of the array:");
	scanf("%d",&size);
	int *my_array=allocate_array(size);
	for(int i=1;i<=size;i++)
	{
		my_array[i]=i;
	}
	printf("the array elements are:\n");
	for(int i=1;i<=size;i++)
	{
		printf("%d\n",my_array[i]);
	}
	free(my_array);
}
