#include <stdio.h>

void my_strcpy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
}

int main() {
    char src[] = "Hello, world!";
    char dest[20];

    my_strcpy(dest, src);

    printf("Copied string: %s\n", dest);

    return 0;
}