#include "merge.h" // Include the header file for function declarations

#include <stdio.h>

// Merge two sorted subarrays arr[l..m] and arr[m+1..r]
void merge(int arr[], size_t l, size_t m, size_t r) {
    if (arr == NULL) { // Check if the array pointer is NULL
        fprintf(stderr, "Error: NULL pointer passed to merge function\n"); // Print error message
        return; // Return without performing any operation
    }

    size_t n1 = m - l + 1; // Calculate the size of the left subarray
    size_t n2 = r - m;     // Calculate the size of the right subarray

    // Create temporary arrays for left and right subarrays
    int *L = malloc(n1 * sizeof(int)); // Secure: Check if memory allocation is successful
    int *R = malloc(n2 * sizeof(int)); // Secure: Check if memory allocation is successful

    if (L == NULL || R == NULL) { // Check if memory allocation failed for any array
        fprintf(stderr, "Error: Memory allocation failed in merge function\n"); // Print error message
        if (L != NULL) // Secure: Free memory if it was allocated before error occurred
            free(L);
        if (R != NULL)
            free(R);
        return; // Return without performing any operation
    }

    // Copy data to temporary arrays L[] and R[]
    for (size_t i = 0; i < n1; i++) // Copy elements to the left subarray
        L[i] = arr[l + i];
    for (size_t j = 0; j < n2; j++) // Copy elements to the right subarray
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    size_t i = 0, j = 0, k = l; // Initialize indices for merging
    // Merge the elements from left and right subarrays into arr[]
    while (i < n1 && j < n2) { // Iterate until either left or right subarray is exhausted
        if (L[i] <= R[j]) {    // If element in left subarray is smaller or equal to element in right subarray
            arr[k] = L[i];     // Copy the element from left subarray to arr[]
            i++;               // Move to the next element in left subarray
        } else {               // If element in right subarray is smaller
            arr[k] = R[j];     // Copy the element from right subarray to arr[]
            j++;               // Move to the next element in right subarray
        }
        k++;                   // Move to the next position in arr[]
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {           // If there are remaining elements in left subarray
        arr[k] = L[i];         // Copy them to arr[]
        i++;                   // Move to the next element in left subarray
        k++;                   // Move to the next position in arr[]
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {           // If there are remaining elements in right subarray
        arr[k] = R[j];         // Copy them to arr[]
        j++;                   // Move to the next element in right subarray
        k++;                   // Move to the next position in arr[]
    }

    free(L); // Free dynamically allocated memory for left subarray
    free(R); // Free dynamically allocated memory for right subarray
}

// Recursive function to perform merge sort on array arr[l..r]
void merge_sort_recursive(int arr[], size_t l, size_t r) {
    if (arr == NULL || l >= r) // Check if the array pointer is NULL or if the subarray has only one element
        return; // Return without performing any operation

    size_t m = l + (r - l) / 2; // Calculate the middle index

    // Sort first and second halves recursively
    merge_sort_recursive(arr, l, m);
    merge_sort_recursive(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
}

// Main merge sort function
void merge_sort(int arr[], size_t n) {
    if (arr == NULL || n == 0) { // Check if the array pointer is NULL or if the array size is zero
        fprintf(stderr, "Error: Invalid input to merge_sort function\n"); // Print error message
        return; // Return without performing any operation
    }

    // Call the recursive function to perform merge sort
    merge_sort_recursive(arr, 0, n - 1);
}