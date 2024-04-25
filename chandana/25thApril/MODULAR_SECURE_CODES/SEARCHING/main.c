#include "linear_search.h"  // Include the header file that contains the function prototype

int main() {
    int arr[] = {10, 20, 30, 40, 50};  // Initialize an array
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    int target = 30;  // Element to search for

    // Perform linear search
    int index = linearSearch(arr, size, target);

    // Print the result
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
