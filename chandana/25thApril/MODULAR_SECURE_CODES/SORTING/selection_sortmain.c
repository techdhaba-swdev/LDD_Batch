#include <stdio.h>            // Include standard I/O functions
#include "selection_sort.h"   // Include the header file that contains the function prototype

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  // Initialize an array
    int size = sizeof(arr) / sizeof(arr[0]);    // Calculate the size of the array

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform selection sort
    selectionSort(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
