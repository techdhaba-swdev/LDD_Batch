#include "partition.h"
#include "swap.h"//includes swap function

int partition(int arr[], int low, int high) {
    int pivot = arr[high];// choose the pivt element as the last element of the array
    int i = (low - 1); // intialize the index of the smaller element 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;   // increment the index of smaller element
            swap(&arr[i], &arr[j]); // swap
        }
    }
    swap(&arr[i + 1], &arr[high]); // placing the pivot element in correct order
    return (i + 1); // return the index of pivot element
}
