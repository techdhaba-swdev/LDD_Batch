#include<stdio.h>
#include<stdlib.h>
void main()
{
	int* ptr = (int*)malloc(sizeof(int)); // Allocate memory

	printf("value store before:%d\n",*ptr);
	free(ptr); // Deallocate memory
        printf("Value stored: %d\n",ptr);


	*ptr = 42; // Using a dangling pointer can crash

	printf("Value stored: %d\n",ptr);
}
