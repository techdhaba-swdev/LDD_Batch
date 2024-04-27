#include "bubble_sort.h"  //including the bubble_sort header file

// Implementation of the bubble sort algorithm
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    
    // Outer loop for traversing through all elements
    for (i = 0; i < n-1; i++) {
        // Inner loop for comparing adjacent elements and swapping if necessary
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
