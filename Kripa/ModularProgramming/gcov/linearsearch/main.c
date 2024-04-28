#include <stdio.h>
#include "linear_search.h"

int main() {
    int array[] = {5, 3, 9, 7, 2, 1, 6};
    int size = sizeof(array) / sizeof(array[0]);
    int key = 7;

    // Perform linear search
    int result = linearSearch(array, size, key);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}

