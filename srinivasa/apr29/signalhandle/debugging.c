#include <stdio.h>

int main() {
    int x = 5;
    int y = 1;
    int z;

    // Divide by zero to cause an error
    z = x / y;

    printf("Result: %d\n", z);

    return 0;
   
}
