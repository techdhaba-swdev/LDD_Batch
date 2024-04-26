#include<stdio.h>
#include"binarysearch.h"
    int main() {
    int arr[] = {2, 3, 9, 12, 34, 54, 71};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 12;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found\n", key);
    }
    return 0;
}

