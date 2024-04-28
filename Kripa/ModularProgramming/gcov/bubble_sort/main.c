#include <stdio.h>
#include "bubble_sort.h"

int main() {
    int array[] = {5, 3, 9, 7, 2, 1, 6};
    int size = sizeof(array) / sizeof(array[0]);

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Perform bubble sort
    bubbleSort(array, size);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

