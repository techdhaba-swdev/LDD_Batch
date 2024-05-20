#include <stdio.h>
#include "quickSort.h"//include quicksort function
#include "printArray.h"//include printarray function

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);//print the original array
    quickSort(arr, 0, n - 1);//perform the quick sort array on the array
    printArray(arr, n); // printf the sorted array
    return 0;
}
