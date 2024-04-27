#include<stdio.h>
#include"binary.h"

// Binary search function (recursive approach)
int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            return binarySearch(arr, mid + 1, high, x);
        else
            return binarySearch(arr, low, mid - 1, x);
    }
    return -1; // Element not found
}
