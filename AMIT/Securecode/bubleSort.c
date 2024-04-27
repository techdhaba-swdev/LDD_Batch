#include<stdio.h>
#include"buble.h"

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, N);

    bubbleSort(arr, N);

    printf("Sorted array: ");
    printArray(arr, N);

    return 0;
}
