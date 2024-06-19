#include <stdio.h>

float calculate_average(int *arr, int size) {
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return (float)sum / size;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    float average = calculate_average(arr, size);
    printf("Average: %.2f\n", average);

    return 0;
}




