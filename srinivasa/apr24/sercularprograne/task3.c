#include <stdlib.h>

int main() {
    int *ptr;
    ptr = (int *)malloc(sizeof(int) * -1); // Negative size leads to undefined behavior
    // Further operations...
    free(ptr);
    return 0;
}
