#ifndef BINARY_TREE_H // ifndef header gaurds checks if binarytreeh has not been defined yet
#define BINARY_TREE_H // defines binary treeh to prevent multiple inclusions

struct Node // Defines a structure named node to represent a node in the binary tree
{
	int data; // integer variable to store the data value
	struct Node *Left; //a pointer to the left child node
	struct Node *Right;//a pointer to the right child node
};
struct Node *createnode(int data); //a function to create newnode in the binarytree
struct Node *insert(struct Node *root , int data);// a function to insert a new node into the binary tree
void inOrder(struct Node *root);//traverse the binary tree inorder traversal
int sumNodes(struct Node *root);// a function to calculate sum of nodes in a tree

#endif // end of the #ifndef directive
