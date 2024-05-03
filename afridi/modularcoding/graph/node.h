#ifndef NODE_H//ifndef header guard checks wheather header file is included previously or not
#define NODE_H// it is first step of header file and it prevent node.h from multiple includions
#include "header.h" // includes header file that contains all header functions
// Node structure for binary search tree
struct Node {                  
    int data; // Data of the node to be stored
    struct Node *left;  // Pointer to the left child node
    struct Node *right; // Pointer to the right child node
};
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void inOrderTraversal(struct Node* root);
struct Node* search(struct Node* root, int data);
struct Node* findMin(struct Node* root);
struct Node* findMax(struct Node* root);
struct Node* deleteNode(struct Node* root, int data);
bool isBSTUtil(struct Node* root, int min, int max);
int height(struct Node* root);
void preOrderTraversal(struct Node* root);
void postOrderTraversal(struct Node* root);
			

#endif // end of the indef header guard
