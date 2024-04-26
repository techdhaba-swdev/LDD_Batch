#include "linearsearch.h"

// Function definition for linear search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) { // Loop through the array
        if (arr[i] == target) // Check if current element is equal to target
            return i; // Return the index if found
    }
    return -1; // Return -1 if target is not found
}
