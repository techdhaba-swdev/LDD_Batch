#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}


int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item to the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char* string) {
    int length = strlen(string);
    struct Stack* stack = createStack(length);

    // Push each character onto the stack
    for (int i = 0; i < length; i++)
        push(stack, string[i]);

    // Pop characters from the stack and store them back in the string
    for (int i = 0; i < length; i++)
        string[i] = pop(stack);

    // Free the memory allocated for the stack
    free(stack->array);
    free(stack);
}

int main() {
    char input_string[] = "Hello, World!";
    printf("Original string: %s\n", input_string);
    reverseString(input_string);
    printf("Reversed string: %s\n", input_string);
    return 0;
}


