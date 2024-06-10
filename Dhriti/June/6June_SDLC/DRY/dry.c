//The DRY principle emphasizes the avoidance of duplication of code within a software system. It encourages modularization and reusability of code to reduce redundancy. DRY aims to improve maintainability and readability by ensuring that any given piece of functionality is implemented in exactly one place in the codebase.

#include <stdio.h>  

// Function to find the minimum element in an array
int findMin(int arr[], int size) {
    int min = arr[0];  // Initialize 'min' with the first element of the array

    // Loop through the array starting from the second element
    for (int i = 1; i < size; i++) {
        // If the current element is smaller than 'min', update 'min'
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;  // Return the minimum element found
}

int main() {
    int numbers1[5] = {10, 5, 8, 3, 6};  // Initialize the first array with 5 elements
    int numbers2[4] = {9, 15, 7, 2};     // Initialize the second array with 4 elements

    // Print the minimum element of the first array
    printf("Minimum of numbers1: %d\n", findMin(numbers1, 5));
    // Print the minimum element of the second array
    printf("Minimum of numbers2: %d\n", findMin(numbers2, 4));

    return 0; 
}
