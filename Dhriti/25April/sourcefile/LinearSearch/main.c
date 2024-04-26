#include<stdio.h>

#include "linears.h"

int main() {
    // Declare and initialize the array
    int arr[] = {5, 10, 15, 20, 25, 30};
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key; // Variable to store the element to search

    // Display the array
    displayArray(arr, n);

    // Ask the user to enter the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Call the linearSearch function to search for the element
    int index = linearSearch(arr, n, key);

    // Display whether the element is found or not
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0; // Exit the program
}

