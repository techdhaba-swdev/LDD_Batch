#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to perform insertion sort
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Generate an array of random numbers
    int arr[SIZE];
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }

    // Print the original array
    printf("Original array: ");
    print_array(arr, SIZE);

    // Start the clock
    clock_t start = clock();

    // Perform insertion sort
    insertion_sort(arr, SIZE);

    // Stop the clock
    clock_t end = clock();

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, SIZE);

    // Calculate the elapsed time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
