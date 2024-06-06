#include <stdio.h>

// Function to calculate the square of a number
int square(int num) {
    return num * num;
}

// Function to calculate the sum of squares of an array
int sumOfSquares(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += square(arr[i]);
    }
    return sum;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int squares[5];

    // Calculate squares
    for (int i = 0; i < size; i++) {
        squares[i] = square(numbers[i]);
    }

    // Calculate sum of squares
    int sum_of_squares = sumOfSquares(numbers, size);

    // Print the squares
    printf("Squares: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", squares[i]);
    }
    printf("\n");

    // Print the sum of squares
    printf("Sum of squares: %d\n", sum_of_squares);

    return 0;
}
