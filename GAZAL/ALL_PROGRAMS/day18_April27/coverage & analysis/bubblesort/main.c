#include <stdio.h> // Include standard input/output library
#include "bubble_sort.h" // Include the bubble sort header file

#define SIZE 5 // Define the size of the array

int main() {
    int arr[SIZE] = {12, 45, 23, 7, 19}; // Initialize the array

    printf("Original array: ");
    for (size_t i = 0; i < SIZE; i++) { // Loop to print original array
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, SIZE); // Call bubble sort function

    printf("Sorted array: ");
    for (size_t i = 0; i < SIZE; i++) { // Loop to print sorted array
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0; // Return 0 to indicate successful execution
}