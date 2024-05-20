#include <stdio.h>
#include <stdlib.h>
int *allocateIntArray(int size)
{
int *arr = (int*)malloc(size * sizeof(int));
if (arr == NULL)
{
printf("memory allocation failed\n");
exit(1);
}
return arr;
}
int main()
{
int size;
printf("enter the size of the array:");
scanf("%d",&size);
int *array = allocateIntArray(size);
free(array);
return 0;
}
