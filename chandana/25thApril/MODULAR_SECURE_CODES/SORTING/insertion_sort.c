#include "insertion_sort.h"  // Include the header file that contains the function prototype

// Function to perform insertion sort
void insertionSort(int arr[], int size) {
    int i, key, j;
    // Start from the second element (index 1) of the array
    for (i = 1; i < size; i++) {
        key = arr[i];  // Store the current element to be inserted at the correct position
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;  // Insert key at its correct position in sorted array
    }
}
