//The KISS principle suggests that systems should be kept as simple as possible, avoiding unnecessary complexity. The idea is to favor simplicity over unnecessary sophistication, making systems easier to understand, maintain, and debug. It emphasizes clarity and straightforwardness in design and implementation.

#include <stdio.h>  

// Function to calculate the average of an array of integers
float calculateAverage(int arr[], int n) {
    int sum = 0;  // Initialize 'sum' to 0
    // Loop through each element of the array
    for (int i = 0; i < n; i++) {
        sum += arr[i];  // Add each element to 'sum'
    }
    // Return the average by dividing the sum by the number of elements
    return (float)sum / n;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};  // Initialize the array with 5 elements
    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function to calculate the average and store the result
    float average = calculateAverage(arr, n);
    // Print the average value with 2 decimal places
    printf("Average: %.2f\n", average);

    return 0;  
}
