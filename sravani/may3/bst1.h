#ifndef BST_H
#define BST_H

//define a structure to represent a node in the bst
 struct node{
	 int data;
	 struct node* left;
	 struct node* right;
 };
//function declarations
struct node* createNode(int data);
struct node* insert(struct node* root,int data);
int search(struct node * root,int data);
struct node* minValueNode(struct node* node);
struct node* deleteNode(struct node* root, int data);
void inorderTraversal(struct node* root);

#endif /*BST_H*/

