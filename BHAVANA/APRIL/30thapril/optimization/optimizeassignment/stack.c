#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct {
    int *array;
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack) {
    stack->array = (int *)malloc(MAX_SIZE * sizeof(int));
    stack->top = -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int main() {
    // Initialize the stack
    Stack stack;
    initialize(&stack);

    // Start the clock
    clock_t start = clock();

    // Push elements onto the stack
    for (int i = 0; i < MAX_SIZE; ++i) {
        push(&stack, i);
    }

    // Pop and print elements from the stack
    printf("Popped elements from the stack:\n");
    for (int i = 0; i < MAX_SIZE; ++i) {
        int element = pop(&stack);
        if (element != -1) {
            printf("%d\n", element);
        }
    }

    // Stop the clock
    clock_t end = clock();

    // Calculate the elapsed time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Time taken: %f seconds\n", time_taken);

    // Free memory allocated for the stack array
    free(stack.array);

    return 0;
}
