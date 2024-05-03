#ifndef BST1_H
#define BST1_H

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
struct node* find_min(struct node* node);
struct node* deletetion(struct node* root, int data);
void inorderTraversal(struct node* root);

#endif
