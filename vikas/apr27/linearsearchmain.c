#include <stdio.h>
#include "linearsearch.h" // Include the header file containing function prototype

int main() {
    int arr[] = {10, 20, 30, 44, 58}; // input array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    int key = 58; // Key to search for
    int result = linear_search(arr, n, key); // Call the linear search function
    if (result != -1) {
        printf("Element found at index: %d\n", result); // Print the index if found
    } else {
        printf("Element not found\n"); // Print if element not found
    }
    return 0;
}
