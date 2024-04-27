//modular and secure code for binary search 


#include <stdio.h>    // including standred input/output header files
#include "binarysearch.h"
// for the binary search the array must me sorted 
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17}; // Sorted array for testing
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int target = 13; // Element to search 

    int index = binary_search(arr, size, target); // Perform binary search

    // Display result
    if (index != -1) // If target found
        printf("Element %d found at index %d\n", target, index); // Print index
    else // If target not found
        printf("Element %d not found\n", target); // Print message

    return 0; // Return success
}
