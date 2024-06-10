/* KISS stands for keep it simple , stupid 
 *here in above program we are keeping program simple without giving complicated functions */

//without using kiss principle
#include <stdio.h>

int sum(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Sum of first %d natural numbers = %d\n", n, sum(n));

    return 0;
}

//with kiss principle
#include <stdio.h>

int main() {
    int n, sum;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    sum = (n * (n + 1)) / 2; // Using the formula for the sum of the first n natural numbers

    printf("Sum of first %d natural numbers = %d\n", n, sum);

    return 0;
}
