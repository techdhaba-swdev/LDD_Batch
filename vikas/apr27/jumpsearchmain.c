#include <stdio.h>
#include "jumpsearch.h" // Including the header file

int main() {
    int arr[] = {19, 33, 35, 17, 21, 16, 29, 32, 48, 52}; // Array to search in
    int n = sizeof(arr) / sizeof(arr[0]); // Length of the array
    int target = 21; // Element to search for
    
    // Calling jump_search function to find the target element
    int index = jump_search(arr, n, target);
    // Checking if the element was found or not and printing the result
    if (index == -1) {
        printf("Element %d not found\n", target);
    } else {
        printf("Element %d found at index %d\n", target, index);
    }

    return 0;
}
