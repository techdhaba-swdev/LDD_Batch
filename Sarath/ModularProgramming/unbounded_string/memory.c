#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *arr = malloc(sizeof(int) * 3);
   	if (arr == NULL) 
	{
       		printf("Memory allocation failed\n");
       		exit(1);
  	 }
}
