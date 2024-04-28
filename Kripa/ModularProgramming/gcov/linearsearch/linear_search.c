#include "linear_search.h"

int linearSearch(int array[], int size, int key) {
    // Iterate through the array
    for (int i = 0; i < size; i++) {
        // If the current element is equal to the key, return its index
        if (array[i] == key) {
            return i;
        }
    }
    // If the key is not found, return -1
    return -1;
}

