#include "quicksort.h"

// Function definition for partitioning the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as pivot
    int i = low - 1; // Index of smaller element
    for (int j = low; j < high; j++) { // Loop through the array
        if (arr[j] < pivot) { // If current element is smaller than the pivot
            i++; // Increment index of smaller element
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1; // Return the partitioning index
}

// Function definition for recursive quicksort
void quicksort(int arr[], int low, int high) {
	 if (low < high) { // If there are more than one element in the subarray
        int pi = partition(arr, low, high); // Partition the array
        quicksort(arr, low, pi - 1); // Recursively sort elements before partition
        quicksort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}
