/*The KISS principle suggests that systems should be kept as simple as possible, avoiding unnecessary complexity. The idea is to favor simplicity over unnecessary sophistication, making systems easier to understand, maintain, and debug. It emphasizes clarity and straightforwardness in design and implementation.*/
#include <stdio.h>

// Function to calculate the average of an array of integers
float calculateAverage(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (float)sum / n;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    float average = calculateAverage(arr, n);
    printf("Average: %.2f\n", average);

    return 0;
}
