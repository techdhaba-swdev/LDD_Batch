#include "linear.h"

// Function to perform linear search
// Parameters:
// - arr: Pointer to the integer array to search
// - n: Size of the array
// - key: Integer value to search for in the array
// Returns:
// - Index of the first occurrence of the key if found, or -1 if not found
int linear_search(const int arr[], size_t n, int key) {
    // Check if the array pointer is NULL
    if (arr == NULL) {
        return -1; // Return -1 if the array pointer is NULL
    }

    // Iterate through the array to search for the key
    for (size_t i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index if the key is found
        }
    }

    // If the key is not found in the array, return -1
    return -1;
}