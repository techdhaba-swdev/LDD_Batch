#ifndef BST_H
#define BST_H
// creating a structure with data , left and right node pointers 
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
};
// function prototypes used in the binary search tree
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void inOrderTraversal(struct Node* root);
void preordertraversal(struct Node* root);
void postordertraversal(struct Node* root);
bool isbst(struct Node* root);
bool isbstutil(struct Node *root, struct Node *prev);
int height(struct Node *root);
void find_min_max(struct Node *node, int* min_val, int* max_val);
#endif 
