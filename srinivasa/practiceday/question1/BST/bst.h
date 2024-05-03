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
struct Node* minValueNode(struct Node* node);
struct Node* deleteNode(struct Node* root, int key);
struct Node* search(struct Node* root, int key);
void inOrderTraversal(struct Node* root);

#endif /* BST_H */
