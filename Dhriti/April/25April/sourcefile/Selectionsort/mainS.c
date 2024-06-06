#include <stdio.h>
#include "selection_sort.h"
#include "print_array.h"

int main() {
    // Initialize the array
    int arr[] = {64, 25, 12, 22, 11};
    // Calculate the size of the array
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // Print the original array
    printf("Original array: \n");
    printArray(arr, n);
    
    // Perform Selection Sort
    selectionSort(arr, n);
    
    // Print the sorted array
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}

