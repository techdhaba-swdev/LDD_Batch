#include <stdio.h>

float calculateAverage(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    float average = (float)sum / n;
    return average;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    float average = calculateAverage(arr, n);
    printf("The average of the elements in the array is: %.2f\n", average);

    return 0;
}
