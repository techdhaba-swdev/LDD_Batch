#include "binary_search.h"  // Include the header file that contains the function prototype

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;          // Leftmost index of the subarray
    int right = size - 1;  // Rightmost index of the subarray

    // Repeat until the left index is less than or equal to the right index
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate the middle index of the subarray

        // If the target is found at the middle index, return the index
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is greater than the value at the middle index, search the right half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If the target is less than the value at the middle index, search the left half
        else {
            right = mid - 1;
        }
    }

    // If the target is not found, return -1
    return -1;
}
