#include "binarysearch.h"
#include<stdio.h>

// Binary search function
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if key is present at mid
        if (arr[mid] == key)
            return mid;

        // If key greater, ignore left half
        if (arr[mid] < key)
            left = mid + 1;

        // If key is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If key not found, return -1
    return -1;
}

