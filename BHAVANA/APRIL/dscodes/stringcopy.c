#include <stdio.h>

void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

int main() {
    char source[] = "Hello, world!";
    char destination[100];

    my_strcpy(destination, source);

    printf("Copied string: %s\n", destination);

    return 0;
}
