#ifndef NODE_H
#define NODE_H

// Structure definition for a node in the binary tree
struct Node {
    int data;             // Data stored in the node
    struct Node* left;    // Pointer to the left child node
    struct Node* right;   // Pointer to the right child node
};

// Function to create a new node
struct Node* createNode(int data);

#endif

