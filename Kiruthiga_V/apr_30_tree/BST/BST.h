#ifndef BST_H
#define BST_H
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data); 
struct Node* insert(struct Node* root, int data); 
void inOrder(struct Node* root);
int add(struct Node* root);

#endif
