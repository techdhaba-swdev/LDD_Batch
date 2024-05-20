#include <stdlib.h>

int main() {
    int* ptr = (int*)malloc(sizeof(int) * 10);
    // Memory allocated but never freed
    return 0;
}
