#include <stdio.h>
#include <time.h>

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    clock_t start = clock();
    int sum = sumArray(arr, size);
    clock_t end = clock();
    
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Sum of array elements: %d\n", sum);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    return 0;
}


