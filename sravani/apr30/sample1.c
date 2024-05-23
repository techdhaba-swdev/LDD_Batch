#include <stdio.h>
#include <stdlib.h>
void allocate_and_modify(int **ptr) {
   	int *temp = (int *)malloc(sizeof(int));
      	// Dynamically allocate memory    
	*temp = 10;  // Modify the allocated value 
   *ptr = temp;  // Assign the address to the pointer passed by reference
		 } 
int main() {
   	int *x = NULL;
   	allocate_and_modify(&x);
   	printf("Modified value: %d\n", *x); // Access dangling pointer after function exitfree(x); 
	return 0;
}