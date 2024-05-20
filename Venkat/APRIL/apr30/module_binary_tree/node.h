#ifndef NODE_H
#define NODE_H


// Node structure definition
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data); 
#endif
