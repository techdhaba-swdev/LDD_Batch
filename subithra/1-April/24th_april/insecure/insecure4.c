//double free

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 10; // Assigning a value to the integer
    printf("Value before double free: %d\n", *ptr); // Print value before double free
    free(ptr);
    free(ptr); // Double free vulnerability
    printf("Value after double free: %d\n", *ptr); // Print value after double free
    return 0;
}