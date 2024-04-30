#include <stdio.h>
#include <time.h>

void bubble_sort(int arr[], int n, int *comparisons, int *swaps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                (*swaps)++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100]; // Array with 100 elements
    for (int i = 0; i < 100; i++) {
        arr[i] = 100 - i; // Initialize array with values from 1000 to 1
    }
    int comparisons = 0;
    int swaps = 0;
    clock_t start = clock();
    bubble_sort(arr, 100, &comparisons, &swaps);
    clock_t stop = clock();
    double time_taken = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of swaps: %d\n", swaps);
    printf("Sorted array: ");
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
