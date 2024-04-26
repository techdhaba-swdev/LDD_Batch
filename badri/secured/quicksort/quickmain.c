#include <stdio.h>
#include "quicksort.h" // Includes the header file for quicksort.

int main() {
    int arr[] = {9, 3, 7, 5, 6, 4, 8, 2, 1}; // Initializes an array.
    int n = sizeof(arr) / sizeof(arr[0]); // Calculates the size of the array.
    quicksort(arr, 0, n - 1); // Sort the array
    printf("Sorted array: "); 
    for (int i = 0 ; i< n ; i++ ) {
        printf("%d ", arr[i]); // Print the sorted array
    }
    printf("\n");
    return 0; // Returns 0 to indicate successful termination.
}
