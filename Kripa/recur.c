#include <stdio.h>

// Function to print elements of an array recursively
void printArray(int arr[], int size, int index) {
    // Base case: if index exceeds the size of the array, return
    if (index >= size) {
        return;
    }

    // Print the element at the current index
    printf("%d ", arr[index]);

    // Recursive call to print the next element
    printArray(arr, size, index + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements: ");
    printArray(arr, size, 0); // Start printing from index 0

    return 0;
