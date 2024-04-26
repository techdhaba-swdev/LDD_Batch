#ifndef NODE_H
#define NODE_H

// Define structure for a node in the doubly linked list
typedef struct Node {
    int data; // Data stored in the node
    struct Node* prev; // Pointer to the previous node
    struct Node* next; // Pointer to the next node
} Node;

// Function to create a new node
Node* createNode(int data);

#endif //terminates the header processor
