#include <stdio.h>

int main() {
    float a = 1234567890/0;

    printf("Value of a: %f\n", a); 
    return 0;
}

// Division by zeo leads to overflow or a negative value
