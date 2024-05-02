#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insertNode(struct Node* root, int data);
void printInorder(struct Node* root);
int addNumbers(struct Node* root);

#endif /* BINARY_TREE_H */
