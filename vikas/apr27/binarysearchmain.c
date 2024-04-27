#include <stdio.h>
#include "binarysearch.h"

int main() {
    int arr[] = {36, 44, 9, 12, 19, 28, 67, 77, 14}; //input array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int target = 28; // Element to search for

    int index = binary_search(arr, size, target); // Perform binary search

    // Display result
    if (index != -1) // If target found
        printf("Element %d found at index %d\n", target, index); // Print index
    else // If target not found
        printf("Element %d not found\n", target); // Print message

    return 0; // Return success
}

