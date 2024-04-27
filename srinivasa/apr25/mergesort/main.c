#include <stdio.h>    // including standred input/output headerfiles
#include "merge_sort.h"  // including merge_sort header files

int main() {
    int arr[] = {15, 2, 16, 4, 9, 33};  // array to be sorted
    int arr_size = sizeof(arr) / sizeof(arr[0]); // caliculate size of the array

    printf("Given array is \n"); // printing the original array
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    merge_sort(arr, 0, arr_size - 1);  // function for merge_sort

    printf("Sorted array is \n");      // printing the sorted array
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;       // executing the programe without errors
}
