#include <stdio.h>
#include <time.h>

int binary_search(int arr[], int low, int high, int key, int *comparisons) {
    while (low <= high) {
        (*comparisons)++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[1000000]; // Array with 1 million elements
    for (int i = 0; i < 1000000; i++) {
        arr[i] = i + 1; // Initialize array with values from 1 to 1000000
    }
    int key = 999999; // Key to search for (last element in the array)
    int comparisons = 0;
    clock_t start = clock();
    int index = binary_search(arr, 0, 999999, key, &comparisons);
    clock_t stop = clock();
    double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    printf("Number of comparisons: %d\n", comparisons);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
