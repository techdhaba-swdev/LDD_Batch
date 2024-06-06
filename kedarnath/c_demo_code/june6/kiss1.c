#include <stdio.h>

int main() {
    int num, sum = 0;

    // Read numbers from the user and calculate the sum
    printf("Enter integers to sum (enter 0 to end):\n");

    while (1) {
        printf("Enter an integer: ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        sum += num;
    }

    // Print the result
    printf("The sum of the entered integers is: %d\n", sum);

    return 0;
}




