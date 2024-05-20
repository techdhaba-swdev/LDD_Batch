#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdbool.h>
// Node structure for Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
struct Node* search(struct Node* root, int key);
bool isBSTUtil(struct Node* root, int min, int max);
bool isBST(struct Node* root);
int maxDepth(struct Node* root);
struct Node* minValueNode(struct Node* node);
struct Node* deleteNode(struct Node* root, int key);
int minValue(struct Node* root);
int maxValue(struct Node* root);
#endif
