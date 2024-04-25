#include <stdlib.h>

int* create_int() {
    int x = 42;
    int* ptr = &x;
    return ptr; // Returning a pointer to a local variable
}

int main() {
    int* ptr = create_int(); // Dangling pointer: accessing memory that's no longer valid
    return 0;
}
