#include <stdio.h>    // including standared input/output header files
#include "bubble_sort.h"  // including bubble_sort.h header file

int main() {
    // Test array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // size of the array
    
    // Print original array
    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call bubble sort function
    bubble_sort(arr, n);

    // Print sorted array
    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;   // executing programe with out errors
}
