#include <stdio.h>

void findMinMax(int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i]; 
        }
    }
}

int main() {
    int arr[] = {3, 8, 2, 1, 5, 7, 4, 6}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
      int min, max;

    findMinMax(arr, size, &min, &max); 

    printf("The smallest element is: %d\n", min);
    printf("The largest element is: %d\n", max);

    return 0;
}