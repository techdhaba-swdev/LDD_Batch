#include <stdio.h>

int add_two(int a, int b) {
    return a + b;
}


int add_three(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int sum2 = add_two(3, 4);
    int sum3 = add_three(3, 4, 5);

    printf("The sum of two numbers: %d\n", sum2);
    printf("The sum of three numbers: %d\n", sum3);

    return 0;
}
