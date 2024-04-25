#include "linear_search.h"  // Include the header file that contains the function prototype

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    // Iterate through each element in the array
    for (int i = 0; i < size; i++) {
        // If the current element is equal to the target, return its index
        if (arr[i] == target) {
            return i;
        }
    }
    // If target is not found, return -1
    return -1;
}
