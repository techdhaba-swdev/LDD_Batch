#include "quickSort.h"
#include "partition.h" // include the partition function

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);//partition the array and getting the pivot index
        quickSort(arr, low, pi - 1);// recursive sort the elements before the pivot
        quickSort(arr, pi + 1, high);// recusively sort the elements after the pivot
    }
}
