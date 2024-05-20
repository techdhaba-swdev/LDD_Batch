#include <stdio.h>
#include <string.h>

void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }
    // Swap characters at start and end indices
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    // Recursive call with updated indices
    reverseString(str, start + 1, end - 1);
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    scanf("%s", inputString);

    int length = strlen(inputString);
    reverseString(inputString, 0, length - 1);

    printf("Reversed string: %s\n", inputString);

    return 0;
}