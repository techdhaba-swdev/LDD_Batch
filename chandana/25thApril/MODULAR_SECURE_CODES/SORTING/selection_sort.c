#include "selection_sort.h"  // Include the header file that contains the function prototype

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    int i, j, min_idx;

    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < size - 1; i++) {
        // Find the minimum element in the unsorted array
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
