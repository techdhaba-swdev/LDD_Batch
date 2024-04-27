#include <stdio.h>    // include the standred input/outout functions
#include "linear_search.h" // Include the header file containing function prototype

int main() {
    int arr[] = {10, 12, 23, 54, 35}; // Sample array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    int key = 12; // Key to search the element
    int result = linear_search(arr, n, key); // Call the linear search function
    if (result != -1) {
        printf("Element found at index: %d\n", result); // Print the index if found
    } else {
        printf("Element not found\n"); // Print if element not found
    }
    return 0;    //executing the main function succesfully
}
