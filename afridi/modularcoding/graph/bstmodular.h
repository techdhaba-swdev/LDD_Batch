#ifndef BST_H
#define BST_H

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* deleteNode(struct Node* root, int data);
struct Node* search(const struct Node* root, int data);
void inOrderTraversal(const struct Node* root);
void freeBST(struct Node* root);

#endif /* BST_H */
