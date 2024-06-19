#include <stdio.h>

float calculate_average(int *arr, int size) {
    if (arr == NULL) {
        printf("Error: Null array\n");
        return -1;
    }
    if (size <= 0) {
        printf("Error: Invalid size\n");
        return -1;
    }

    int sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            printf("Skipping negative value: %d\n", arr[i]);
            continue;
        }
        sum += arr[i];
        count++;
    }
    if (count == 0) {
        printf("Error: No valid elements\n");
        return -1;
    }

    return (float)sum / count;
}

int main() {
    int arr[] = {1, 2, -3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    float average = calculate_average(arr, size);
    if (average >= 0) {
        printf("Average: %.2f\n", average);
    }
    return 0;
}




