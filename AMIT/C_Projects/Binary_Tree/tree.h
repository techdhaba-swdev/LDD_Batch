#ifndef TREE
#define TREE

// Node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void inOrderTraversal(struct Node* root);
struct Node* search(struct Node* root, int data);
struct Node* findMin(struct Node* root);
struct Node* findMax(struct Node* root);
struct Node* deleteNode(struct Node* root, int data);
bool isBSTUtil(struct Node* root, int min, int max);
bool isBST(struct Node* root);
int height(struct Node* root);

#endif

