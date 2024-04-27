#ifndef TREE_H
#define TREE_H

// Define the structure for a node in the BST
struct node;

// Define an alias for struct node as Node
typedef struct node Node;

// Function declarations
Node* createNode(int data);             // Creates a new node
Node* insert(Node* root, int data);      // Inserts a new node into the BST
int search(Node* root, int data);        // Searches for a node with given data
void inorderTraversal(Node* root);       // Performs an in-order traversal of the BST

#endif /* TREE_H */