// tree.h

#ifndef TREE_H_
#define TREE_H_

// Structure definition for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void inOrder(struct Node* root);
int calculateSum(struct Node* root);

#endif /* TREE_H_ */
