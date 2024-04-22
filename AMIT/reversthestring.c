#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the stack structure
struct Stack {
    char* items;  // Pointer to an array to store characters
    int top;      // Index of the top element
    int capacity; // Maximum capacity of the stack
};

// Function to create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;  // Initialize top index to -1 (empty stack)
    stack->items = (char*)malloc(capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char ch) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %c.\n", ch);
        return;
    }
    stack->items[++stack->top] = ch;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop from an empty stack.\n");
        return '\0'; // Return a sentinel value for empty stack
    }
    return stack->items[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char* input) {
    int len = strlen(input);
    struct Stack* charStack = createStack(len);

    // Push characters onto the stack
    for (int i = 0; i < len; ++i) {
        push(charStack, input[i]);
    }

    // Pop characters from the stack to create the reversed string
    for (int i = 0; i < len; ++i) {
        input[i] = pop(charStack);
    }

    // Print the reversed string
    printf("Reversed string: %s\n", input);

    // Clean up memory
    free(charStack->items);
    free(charStack);
}

int main() {
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);

    reverseString(inputString);

    return 0;
}
