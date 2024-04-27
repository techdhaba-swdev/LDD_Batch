#include<stdio.h>
#include"binary.h"
int main() {
    int arr[] = {3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result != -1)
        printf("Element %d found at index %d.\n", x, result);
    else
        printf("Element %d not found.\n", x);

    return 0;
}
