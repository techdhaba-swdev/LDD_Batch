#include <stdio.h>
#include <string.h>
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverseString(char *str, int start, int end) {
    if (start >= end)
        return;
        swap(&str[start], &str[end]);
        reverseString(str, start + 1, end - 1);
}

int main() {
    char str[] = "Hello, World!";
    int length = strlen(str);

    printf("Original String: %s\n", str);
    reverseString(str, 0, length - 1);

    printf("Reversed String: %s\n", str);

    return 0;
}