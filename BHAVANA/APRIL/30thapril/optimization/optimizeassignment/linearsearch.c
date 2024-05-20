#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

// Function to perform linear search
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found
}

int main() {
    // Generate an array of SIZE elements
    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = i; // Fill the array with consecutive numbers
    }

    // Key to search for (present in the array)
    int key = SIZE / 2;

    // Start the clock
    clock_t start = clock();

    // Perform linear search
    int index = linear_search(arr, SIZE, key);

    // Stop the clock
    clock_t end = clock();

    // Calculate the elapsed time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the result
    if (index != -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }

    // Print the execution time
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
