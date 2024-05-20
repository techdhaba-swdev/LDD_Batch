#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void reverseString(char *inputString) {
    int length = strlen(inputString);
    char stack[MAX_SIZE];
    int top = -1;

    
    for (int i = 0; i < length; i++) {
        stack[++top] = inputString[i];
    }

    for (int i = 0; i < length; i++) {
        inputString[i] = stack[top--];
    }
}

int main() {
    char inputString[MAX_SIZE];
    printf("Enter a string: ");
    fgets(inputString, MAX_SIZE, stdin);
    inputString[strcspn(inputString, "\n")] = '\0';
    reverseString(inputString);
    printf("Reversed string: %s\n", inputString);

    return 0;
}
