#include <stdio.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) { // Outer loop for pass through the array
        for (int j = 0; j < size - i - 1; j++) { // Inner loop for comparison and swapping
            if (arr[j] > arr[j + 1]) { // If current element is greater than the next, swap
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) { // Loop through array and print each element
        printf("%d ", arr[i]);
    }
    printf("\n"); // Print newline after printing all elements
}

int main() {
    int arr[] = {64, 25, 12, 22, 11}; // Initialize array with values
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of array

    printf("Array before sorting: ");
    printArray(arr, size); // Print array before sorting

    bubbleSort(arr, size); // Sort array using bubble sort algorithm

    printf("Array after sorting: ");
    printArray(arr, size); // Print array after sorting

    return 0; // Return 0 to indicate successful execution
}


