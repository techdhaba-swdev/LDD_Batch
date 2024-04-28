#include <stdio.h>
#include "linearsearch.h"

int main() {
    int arr[] = {5, 3, 8, 4, 2};//some of value in array is given 
    int size = sizeof(arr) / sizeof(arr[0]);//it is a size of array
    int target = 8;//this target value can search in agiven arrays

    // Perform linear search
    int index = linearSearch(arr, size, target);

    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);//
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
