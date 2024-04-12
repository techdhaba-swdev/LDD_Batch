#include <stdio.h>
#include <string.h>

void reverse_string(char *str, int start, int end) {
    if (start >= end) {
        return;
    } else {
        // Swap characters at start and end positions
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move to the next pair of characters
        reverse_string(str, start + 1, end - 1);
    }
}

int main() {
    char str[100];
    printf("enter a string\n");
    scanf("%s", &str);
    int length = strlen(str);
    reverse_string(str, 0, length - 1);
    printf("Reversed string: %s\n", str); 
    return 0;
}