#include <stdio.h>  // including the standerd input/out functions
#include "jump_search.h" // including the header file

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Array to search 
    int n = sizeof(arr) / sizeof(arr[0]); // Length of the array
    int target = 11; // Element to search in the list
    
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
