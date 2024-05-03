#ifndef BST_H
#define BST_H

// Node structure for BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data);
Node* insert(Node* root, int data);
void inOrderTraversal(const Node* root);
void preOrderTraversal(const Node* root);
void postOrderTraversal(const Node* root);
Node* search(const Node* root, int data);
int isBST(const Node* root, int min, int max);
int height(const Node* root);
int findMin(const Node* root);
int findMax(const Node* root);
void freeBST(Node* root);

#endif /* BST_H */
