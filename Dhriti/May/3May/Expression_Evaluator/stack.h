#ifndef STACK_H  
#define STACK_H   

// Structure for stack node
typedef struct Node {
    char data;  // Data element stored in the node (character in this case)
    struct Node* next;  // Pointer to the next node in the stack
} Node;

// Structure for stack
typedef struct {
    Node* top;  // Pointer to the topmost node of the stack
} Stack;

// Function prototypes
void push(Stack* stack, char data);  // Push data onto the stack
char pop(Stack* stack);                // Pop data from the stack
char peek(Stack* stack);                // Peek at the top element without popping
int isEmpty(Stack* stack);              // Check if the stack is empty

#endif 
