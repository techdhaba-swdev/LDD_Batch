#ifndef STACK_H // Check if STACK_H hasn't been included yet
#define STACK_H // Define header guard to prevent multiple inclusions

// Structure for stack node
typedef struct Node {
    char data; // Data element stored in the node (character in this case)
    struct Node* next; // Pointer to the next node in the stack
} Node;

// Structure for stack
typedef struct {
    Node* top; // Pointer to the topmost node of the stack
} Stack;

// Function prototypes
void push(Stack* stack, char data); // Push data onto the stack
char pop(Stack* stack); // Pop data from the stack
char peek(Stack* stack); // Peek at the top element without popping
int is_empty(Stack* stack); // Check if the stack is empty

#endif /* STACK_H */
