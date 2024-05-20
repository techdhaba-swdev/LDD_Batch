#include "selection_sort.h"

// Function to perform selection sort
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i; // Assume the current index has the minimum element

        // Find the index of the minimum element in the remaining unsorted array
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        // Swap the minimum element with the current element (if they are different)
        if (min_index != i) {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}
