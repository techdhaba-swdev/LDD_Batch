#include <stdio.h>
#include "jumpsearch.h"

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7}; // Example sorted array
    int size = sizeof(array) / sizeof(array[0]); // Calculate the size of the array
    int target = 5; // Example target value to search

    // Perform jump search
    int result = jumpSearch(array, size, target);

    // Display the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}


// vim jump_main.c
// gcc -o jumpsearch jumpsearch.o jump_main.o -lm
//./jumpsearch

