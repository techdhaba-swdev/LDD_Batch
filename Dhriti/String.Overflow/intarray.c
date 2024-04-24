#include<stdio.h>

//The loop runs one iteration too many, writing beyond the bounds of the array resulting in overflow#include <stdio.h>

int main() {
    int array[5];

    // Manipulating the array without bounds checking
    for (int i = 0; i <= 5; i++) {
        array[i] = i; // Buffer overflow vulnerability
    }

    // Printing the contents of the array
    printf("Array contents:\n");
    for (int i = 0; i < 5; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}

