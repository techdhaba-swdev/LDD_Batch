#include <stdio.h>

// Function to print array elements
void print_array(int *arr, int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate the sum of array elements
int sum_array(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void process_array(int *arr, int size) {
    print_array(arr, size);
    int sum = sum_array(arr, size);
    printf("Sum of array elements: %d\n", sum);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    process_array(arr, size);
    
    return 0;
}




