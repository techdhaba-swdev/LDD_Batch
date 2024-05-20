#include <stdio.h>

int main() {
    int x = 2147483647;
    x++; // Integer overflow
    printf("x: %d\n", x); // Results in undefined behavior
    return 0;
}
