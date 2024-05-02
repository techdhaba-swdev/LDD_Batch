#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void inOrder(struct Node* root);
int sumOfData(struct Node* root); // Function to calculate sum of data
void freeTree(struct Node* root);

#endif
