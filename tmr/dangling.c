#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void allocate_and_modify(int **ptr)
{


    int *temp = (int *)malloc(sizeof(int)); 
       	// Dynamically allocate memory 
    *temp = 10;  // Modify the allocated value  
    *ptr = temp;  // Assign the address to the pointer passed by referenc
}

	int main() {
        clock_t start = clock();
   
      	   int *x = NULL; 
       	   allocate_and_modify(&x);  
	   printf("Modified value: %d\n", *x); // Access dangling pointer after function
	   free(x); // Free memory (may cause issues if not executed due to early termination)
        return 0;
   }
