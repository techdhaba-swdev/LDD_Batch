#include <stdio.h>
int main() {
    char dest[10];
    char src[] = "Hello,............ World!";
    strcpy(dest, src); // Unsafe copy
    printf("Copied string: %s\n", dest);
    return 0;
}
