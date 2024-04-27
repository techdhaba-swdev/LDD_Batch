#include <stdio.h>

// Function prototype for bubble sort
void bubbleSort(int arr[], int n);

int main() {
    int arr[5] = {4, 2, 5, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the bubble sort function
    bubbleSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
