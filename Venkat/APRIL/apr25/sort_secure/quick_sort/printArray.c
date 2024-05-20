#include "printArray.h" 
#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) // print each element of array
        printf("%d ", arr[i]);
    printf("\n");
}
