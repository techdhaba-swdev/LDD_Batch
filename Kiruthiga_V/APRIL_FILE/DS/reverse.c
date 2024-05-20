#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define stack structure
typedef struct {
    int top;
    unsigned capacity;
    char* array;
} Stack;

// Function to create a stack
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push a character onto the stack
void push(Stack* stack, char item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) return '\0';
    return stack->array[stack->top--];
}

// Function to reverse a string using stack
char* reverseString(const char* str) {
    int len = strlen(str);
    Stack* stack = createStack(len);
    int i;

    // Push characters onto the stack
    for (i = 0; i < len; i++) {
        push(stack, str[i]);
    }

    // Create an empty character array to hold the reversed string
    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    int j = 0;

    // Pop characters from the stack and store them in the reversed string array
    while (!isEmpty(stack)) {
        reversed[j++] = pop(stack);
    }
    reversed[j] = '\0';

    return reversed;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    char* reversed = reverseString(str);

    printf("Reversed string: %s\n", reversed);

    free(reversed);

    return 0;
}


