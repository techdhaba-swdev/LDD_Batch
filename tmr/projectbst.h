#ifndef BST_H
#define BST_H

// Node structure definition
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function declarations



struct Node* newNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* search(struct Node* root, int key);
struct Node* deleteNode(struct Node* root, int key);
void inorderTraversal(struct Node* root);

#endif
