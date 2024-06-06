#include "quicksort.h"

// Function to swap two elements
void swap(int* a, int* b) {
	 if (a != NULL && b != NULL) {  // SECURING BY CHECKING NULL POINTER

    int temp = *a;
    *a = *b;
    *b = temp;
	 }
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
	  if (arr == NULL) return 0;  // SECURED BY HANDLING ARRAY NULL POINTER
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform the QuickSort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) 
if (arr == NULL || size <= 0) return; //SECURED BY HANDLING ARRAY  NULL POINTER
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

