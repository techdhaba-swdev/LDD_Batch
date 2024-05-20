

#include <stdio.h>

// Function to perform linear search in an integer array
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index where the key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int arr[] = {5, 3, 7, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int index = linearSearch(arr, size, key);

    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
