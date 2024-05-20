#include <stdio.h>

void swap(int a, int b) {
    printf("Before swap: a = %d, b = %d\n", a, b);
    a = a + b; 
    b = a - b;
    a = a - b;
    printf("After swap: a = %d, b = %d\n", a, b);
}

int main() {
    int x, y;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);
    swap(x, y);
    return 0;
}