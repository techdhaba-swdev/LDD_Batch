#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Forward declaration of the structure
typedef struct Node Node;

// Function prototypes
Node* createNode(int data); // Function to create a new node
Node* insert(Node* root, int data); // Function to insert a node into the binary tree
void inOrder(Node* root); // Function to perform in-order traversal of the binary tree
void freeTree(Node* root); // Function to free memory allocated for the binary tree
int sumNodes(Node* root); // Function to calculate the sum of all nodes in the binary tree

#endif /* BINARY_TREE_H */
