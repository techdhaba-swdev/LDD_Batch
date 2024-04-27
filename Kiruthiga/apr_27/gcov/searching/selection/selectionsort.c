#include <stdio.h>
#include <stdlib.h>
#include "selectionsort.h"
// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_index;

    // One by one move the boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // Swap the found minimum element with the first element
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}
