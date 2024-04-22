#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize stack
void initialize(struct Stack s) {
    s.top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack s) {
    return s.top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack s) {
    return s.top == -1;
}

// Function to push element into stack
void push(struct Stack s, char c, struct Stack *result) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    result->items[++(result->top)] = c;
}

// Function to pop element from stack
char pop(struct Stack s, struct Stack *result) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return result->items[(result->top)--];
}

// Function to reverse a string using stack
void reverseString(char str[]) {
    int len = strlen(str);
    struct Stack s;
    initialize(s);
    struct Stack result;
    initialize(result);

    // Push characters of string onto stack
    for (int i = 0; i < len; i++) {
        push(s, str[i], &result);
    }

    // Pop characters from stack and store in reversed string array
    for (int i = 0; i < len; i++) {
        str[i] = pop(s, &result);
    }
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverseString(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}