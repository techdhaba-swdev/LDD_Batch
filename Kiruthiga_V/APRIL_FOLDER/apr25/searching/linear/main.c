#include<stdio.h>
#include"linearsearch.h"
int main() {
    int arr[] = {12, 34, 54, 2, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    int result = linearSearch(arr, n, key);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found\n", key);
    }
    return 0;
}


