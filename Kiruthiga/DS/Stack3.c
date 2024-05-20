#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a stack node
struct StackNode {
    char* state;
    struct StackNode* next;
};

typedef struct StackNode StackNode;

// Function to create a new stack node
StackNode* createNode(char* state) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->state = strdup(state); // Make a deep copy of the state
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(StackNode* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(StackNode** top_ref, char* state) {
    StackNode* newNode = createNode(state);
    newNode->next = *top_ref;
    *top_ref = newNode;
}

// Function to pop an element from the stack
char* pop(StackNode** top_ref) {
    if (isEmpty(*top_ref)) {
        printf("Stack underflow.\n");
        exit(1);
    }
    StackNode* temp = *top_ref;
    *top_ref = (*top_ref)->next;
    char* popped = temp->state;
    free(temp);
    return popped;
}

// Function to free memory allocated for the stack
void freeStack(StackNode* top) {
    StackNode* current = top;
    while (current != NULL) {
        StackNode* temp = current;
        current = current->next;
        free(temp->state); // Free memory allocated for the state
        free(temp);
    }
}

// Main function to test the "undo" functionality
int main() {
    StackNode* undoStack = NULL;

    // Simulate some text editing actions
    push(&undoStack, "Initial text");
    push(&undoStack, "Inserted some text");
    push(&undoStack, "Deleted some text");
    push(&undoStack, "Edited some text");

    // Undo the last action
    printf("Undo last action:\n");
    char* prevState = pop(&undoStack);
    printf("Previous state: %s\n", prevState);
    free(prevState); // Free memory allocated for the previous state

    // Undo the next action
    printf("\nUndo last action:\n");
    prevState = pop(&undoStack);
    printf("Previous state: %s\n", prevState);
    free(prevState);

    // Free memory allocated for the stack
    freeStack(undoStack);
    
    return 0;
}


