#ifndef NODE_H
#define NODE_H

// Define a struct node to represent a node in the tree
struct node {
    int data;           // The integer value stored in the node
    struct node* left;  // Pointer to the left child node
    struct node* right; // Pointer to the right child node
};

// Function to create a new node with given data
struct node* createNode(int data);

#endif /* NODE_H */
