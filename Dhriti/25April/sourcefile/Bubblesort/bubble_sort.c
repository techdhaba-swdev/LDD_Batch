#include<stdio.h>
#include "bubble_sort.h"

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Iterating through all elements
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            // Swapping if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                // Swapping arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    // Iterating through all elements and printing each one
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

