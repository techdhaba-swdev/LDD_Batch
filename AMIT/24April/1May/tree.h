#ifndef BINARY_H
#define BINARY_H

// Structure definition for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void inOrder(struct Node* root);
int sumOfNodes(struct Node* root);


#endif
