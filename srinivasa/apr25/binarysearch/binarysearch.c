#include "binarysearch.h"    // including the hearder file

// Binary search function 
int binary_search(int arr[], int size, int target) {
    int left = 0; // Initialize the left as 0
    int right = size - 1; // Initialize the right value as size -1

    while (left <= right) { // run while until left <= right
        int mid = left + (right - left) / 2; // Calculate the middle 

        if (arr[mid] == target) // check the mid is target
            return mid; // return the mid value 
        else if (arr[mid] < target) // If the target is in the right half
            left = mid + 1; // Adjust the left 
        else // If the target is in the left half
            right = mid - 1; // Adjust the right boundary
    }

    // If target is not found
    return -1; // Return -1 if the element is not found
}
