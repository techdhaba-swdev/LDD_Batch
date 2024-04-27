#include <stdio.h>         // Include standard I/O library for printf function
#include "main.h"    // Include the header file for merge sort function declarations

int main() {                               // Start of the main function
    int arr[] = {12, 11, 13, 5, 6, 7};     // Initialize an unsorted array
    size_t n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Perform merge sort
    merge_sort(arr, n);                    // Call the merge sort function to sort the array

    // Print sorted array
    printf("Sorted array: ");              // Print a message indicating the sorted array is being printed
    for (size_t i = 0; i < n; i++)         // Iterate through each element of the array
        printf("%d ", arr[i]);             // Print each element of the sorted array
    printf("\n");                          // Move to the next line after printing the sorted array

    return 0;                              // Return 0 to indicate successful execution
}                                         // End of the main function