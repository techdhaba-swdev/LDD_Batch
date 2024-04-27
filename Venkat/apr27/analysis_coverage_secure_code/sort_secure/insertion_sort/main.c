#include <stdio.h>

// Function prototype for insertion sort
void insertionSort(int arr[], int n);

int main() {
    int arr[6] = {4, 3, 6, 1, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the insertion sort function
    insertionSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
	

