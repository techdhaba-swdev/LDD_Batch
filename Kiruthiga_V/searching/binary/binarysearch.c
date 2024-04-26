#include <stdio.h>
#include <stdlib.h>
#include "binarysearch.h"
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the key is present at the middle
        if (arr[mid] == key)
            return mid;

        // If the key is greater, ignore the left half
        if (arr[mid] < key)
            left = mid + 1;

        // If the key is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If the key is not present in the array
    return -1;
}
