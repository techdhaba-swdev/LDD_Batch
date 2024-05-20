#include <stdio.h>
#include <stdlib.h> // for malloc
#include "main.h"

int main() {
    int *arr; // Pointer to store dynamically allocated array
    int n;     // Variable to store the number of elements

    // Ask user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n); // Read the number of elements from the user

    // Allocate memory for the array
    arr = (int *)malloc(n * sizeof(int)); // Secure: Allocate memory for the array based on user input

    // Ask user to input elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]); // Read each element from the user and store in the array
    }

    int key; // Variable to store the element to search
    // Ask user for the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key); // Read the element to search from the user

    // Perform linear search
    int result = linear_search(arr, n, key); // Secure: Perform linear search on the array

    // Print result
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result); // Print if element is found
    } else {
        printf("Element %d not found\n", key); // Print if element is not found
    }

    // Free dynamically allocated memory
    free(arr); // Secure: Free dynamically allocated memory for the array

    return 0;
}