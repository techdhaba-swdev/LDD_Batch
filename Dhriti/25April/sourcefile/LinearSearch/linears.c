#include<stdio.h>

#include "linears.h"


// Function to perform linear search
int linearSearch(const int arr[], int n, int key) { //SECURED BY USING 'const' FOR ARRAY PARAMETERS TO PREVENT MODIFICATION
    // Loop through the array
    for (int i = 0; i < n; i++) {
        // Check if the current element is equal to the key
        if (arr[i] == key) {
            return i; // Return the index where the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

// Function to display the array
void displayArray(const int arr[], int n)  //SECURED BY USING 'const' FOR ARRAY PARAMETERS TO PREVENT MODIFICATION

{
    printf("Array: ");
    // Loop through the array to display each element
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print the current element
    }
    printf("\n");
}

