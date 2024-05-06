#ifndef BINARYSTREE_H
#define BINARYSTREE_H 
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int value);
struct Node* searchNodeValue(struct Node* root, int value);
struct Node* deleteNode(struct Node* root, int value);
struct Node* findMin(struct Node* root);
void inOrderTraversal(struct Node* root);
void preOrderTraversal(struct Node* root);
void postOrderTraversal(struct Node* root);
int maxHeight(struct Node* root);
int findMinValue(struct Node* root);
int findMaxValue(struct Node* root);
void freeTree(struct Node* root);

#endif 
