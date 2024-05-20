#include <stdlib.h> // Include the standard library for malloc and free functions
#include<stdio.h>
int main() {
    int* ptr = (int*)malloc(sizeof(int)); // creates a variable ptr and allocate memory space
    printf("value is: %d \n",*ptr);
    free(ptr); // Deallocate memory for releasing its memory space
   
    *ptr = 42; // ptr is not pointing to a valid memory as ptr was made free so it may cause different behavior
   
    printf("value is: %d \n",*ptr);
    
    return 0;
}
