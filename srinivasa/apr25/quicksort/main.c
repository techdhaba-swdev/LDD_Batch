#include <stdio.h>  // including the standrad input/output functions
#include "quick_sort.h"  // including quick_sort header file

#define SIZE 10   // defining the size as 10

int main() {
    int arr[SIZE] = {10, 7, 8, 9, 1, 5, 11, 3, 2, 6};
    printf("Original array: "); // printing the original array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call Quick Sort function
    quick_sort(arr, 0, SIZE - 1);

    printf("Sorted array: ");      // printing the sorted array
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;    // executing the programe with zero errors
}
