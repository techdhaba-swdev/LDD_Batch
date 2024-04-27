#include "linearsearch.h" // Include the header file containing the function prototype

// Function to perform linear search
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) { // Loop through the array
        if (arr[i] == key) { // Check if current element is equal to key
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}
