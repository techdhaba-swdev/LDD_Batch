#include <stdio.h>

int main() {
    int a = 1234567890/0;

    printf("Value of a: %d\n", a); 
    return 0;
}

// Division by zeo leads to overflow or a negative value
