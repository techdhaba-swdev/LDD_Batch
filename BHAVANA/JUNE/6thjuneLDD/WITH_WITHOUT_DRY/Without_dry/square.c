#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int squares[5];
    int sum_of_squares = 0;

    // Calculate squares
    for (int i = 0; i < size; i++) {
        squares[i] = numbers[i] * numbers[i];
    }

    // Calculate sum of squares
    for (int i = 0; i < size; i++) {
        sum_of_squares += squares[i];
    }

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
