#include "binarysearch.h"

// Binary search function implementation
int binary_search(int arr[], int size, int target) {
    int left = 0; // Initialize the left boundary of the search range
    int right = size - 1; // Initialize the right boundary of the search range

    while (left <= right) { // Repeat until the search range is valid
        int mid = left + (right - left) / 2; // Calculate the middle index

        if (arr[mid] == target) // If the middle element is the target
            return mid; // Return the index of the target element
        else if (arr[mid] < target) // If the target is in the right half
            left = mid + 1; // Adjust the left boundary
        else // If the target is in the left half
            right = mid - 1; // Adjust the right boundary
    }

    // If target is not found
    return -1; // Return -1 to indicate target not found
}



