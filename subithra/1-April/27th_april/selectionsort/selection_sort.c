#include "selection_sort.h" // Include the header file

void selection_sort(int arr[], size_t n) { // Define selection sort function
    for (size_t i = 0; i < n - 1; i++) { // Loop through the array
        size_t min_index = i; // Assume the current index has the minimum value

        // Find the index of the minimum element in the unsorted part of the array
        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j; // Update the index of the minimum element
            }
        }

        // Swap the minimum element with the first element of the unsorted part
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}
