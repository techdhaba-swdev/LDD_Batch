#include<stdio.h>
#include "bubble_sort.h"

int main() {
    // Array to be sorted

      int arr[] = {64, 34, 25, 12, 22, 11, 90};
    // Number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Printing the unsorted array
    printf("Unsorted array: \n");
    printArray(arr, n);

    // Sorting the array
    bubbleSort(arr, n);

    // Printing the sorted array
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

