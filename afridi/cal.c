#include <stdio.h>

int add_dynamic(int x, int y) {
    int sum = x + y;
    printf("Sum of two numbers: %d\n", sum);
    return sum;
}

int sub_dynamic(int x, int y) {
    int sub = x - y;
    printf("Subtraction of two numbers: %d\n", sub);
    return sub;
}

int mul_dynamic(int x, int y) {
    int mul = x * y;
    printf("Multiplication of two numbers: %d\n", mul);
    return mul;
}

int div_dynamic(int x, int y) {
    if (y == 0) {
        printf("Arithmetic exception: Division by zero\n");
        return 0;
    } else {
	    int div = x / y;
        printf("Division of two numbers: %d\n", div);
        return div;
    }
}

int main() {
    int a = 10, b = 5;
    add_dynamic(a, b);
    sub_dynamic(a, b);
    mul_dynamic(a, b);
    div_dynamic(a, b);
    return 0;
}
