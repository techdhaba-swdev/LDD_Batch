#include <stdio.h>
#include "heapSort.h"
#include "printArray.h"

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);

    return 0;
}
