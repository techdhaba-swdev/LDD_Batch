#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* ptr = (int*)malloc(sizeof(int));
	printf("value :%d",ptr);
	free(ptr); // Deallocate memory
	   *ptr = 42; 
	   printf("value:%d",ptr);
	   return 0;
}


