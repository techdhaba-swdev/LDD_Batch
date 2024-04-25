#include "bubblesort.h"  // Include the header file that contains the function prototype

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    // Outer loop to traverse through all elements of the array
    for (int i = 0; i < size - 1; i++) {
        // Inner loop to compare adjacent elements and swap them if necessary
        for (int j = 0; j < size - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
