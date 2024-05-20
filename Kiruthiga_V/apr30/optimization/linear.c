#include <stdio.h>
#include <time.h>

int linear_search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 25; // Element to search for
    
    clock_t start = clock();
    int linear_search_result = linear_search(arr, size, key);
    clock_t end = clock();
    
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    if (linear_search_result != -1)
        printf("Element found at index: %d\n", linear_search_result);
    else
        printf("Element not found\n");
    
    printf("Time taken for Linear Search: %f seconds\n", cpu_time_used);
    
    return 0;
}


