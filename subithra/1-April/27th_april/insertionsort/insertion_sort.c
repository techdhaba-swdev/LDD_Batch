#include "insertion_sort.h" // Include the header file

void insertion_sort(int arr[], size_t n) { // Define insertion sort function
    for (size_t i = 1; i < n; i++) { // Loop through elements starting from the second one
        int key = arr[i]; // Store the current element
        size_t j = i - 1; // Initialize a variable for the previous index

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) { // Iterate through the sorted part of the array
            arr[j + 1] = arr[j]; // Move elements one position ahead
            j--; // Move to the previous index
        }
        arr[j + 1] = key; // Place the key element in its correct position
    }
}
