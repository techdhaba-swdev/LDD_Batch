#include <stdio.h>
#include "quicksort.h"

#define SIZE 10

int main() {
    int arr[SIZE] = {10, 7, 8, 9, 1, 5, 11, 3, 2, 6};
    printf("Original array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call Quick Sort function
    quick_sort(arr, 0, SIZE - 1);

    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
