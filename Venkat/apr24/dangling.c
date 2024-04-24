#include <stdio.h>
#include <stdlib.h>

int main(){
	int *ptr = (int*)malloc(sizeof(int)); //allocation of memory 
        *ptr = 42;
	printf("%x\n",ptr);
	printf("%d\n",*ptr);
	printf("after free the memory location\n");
		free(ptr); // deallocation of memory 
		// even though ptr it will pointing to memory location the memory location was freed in order to resolve
	printf("%d\n",*ptr);
	printf("%x\n",ptr);
		// we need to reassing the pointer ptr to null so it will not become dangling pointer 
	}

