#include<stdio.h>
#include"linear.h"

// Linear search function (iterative approach)
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}
