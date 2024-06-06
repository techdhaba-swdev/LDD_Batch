#include<stdio.h>
#include<stdlib.h>
int main(){
	int* ptr = (int*)malloc(sizeof(int)); 
	printf("Pointer %d\n", *ptr);
       free(ptr);
        printf("Pointer %d\n", ptr);

       *ptr = 42;
       printf("Value stored: %d\n", ptr);
return 0;
}

//Memory is allocated with malloc and deallocated with free.But after deallcation of memory ptr still holds the address of the previously allocated memory that becomes dangling pointer.
//ptr crashes so after deallocation ptr should set to null to avoid crashes.
