#ifndef BINARY_TREE_H // Start of include guard: checks if BINARY_TREE_H is not defined
#define BINARY_TREE_H // Define BINARY_TREE_H to prevent multiple inclusion

// Structure definition for a node in the binary tree
struct Node ;

// Function prototypes
struct Node* createNode(int data); // Function to create a new node
struct Node* insert(struct Node* root, int data); // Function to insert a node into the binary tree
void inOrder(struct Node* root); // Function to perform in-order traversal of the binary tree
int sumOfNodes(struct Node* root); // Function to calculate the sum of all nodes in the binary tree
void freeTree(struct Node* root); // Function to deallocate memory for the binary tree

#endif /* BINARY_TREE_H */ // End of include guard
