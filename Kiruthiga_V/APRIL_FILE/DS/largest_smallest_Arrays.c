#include <stdio.h>

// Function to find the largest element in an integer array
int findLargest(int arr[], int size) {
    int largest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

// Function to find the smallest element in an integer array
int findSmallest(int arr[], int size) {
    int smallest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

int main() {
    int arr[] = {5, 3, 7, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int largest = findLargest(arr, size);
    int smallest = findSmallest(arr, size);

    printf("Largest element in the array: %d\n", largest);
    printf("Smallest element in the array: %d\n", smallest);

    return 0;
}


