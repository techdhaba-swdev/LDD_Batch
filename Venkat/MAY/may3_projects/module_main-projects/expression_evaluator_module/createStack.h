// createStack.h

#ifndef CREATESTACK_H
#define CREATESTACK_H

#include "Node.h"

// Structure for Stack which holds the top node.
typedef struct Stack {
    Node* top;
} Stack;

// Function  for creating a new stack.
Stack* createStack();

#endif // CREATESTACK_H
