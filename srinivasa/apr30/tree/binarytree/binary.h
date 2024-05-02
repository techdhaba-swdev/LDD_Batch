#ifndef BINARY_H_
#define BINARY_H_
//structure of a binary tree
struct node {
	int data;
	struct node* left;
	struct node* right;
};
//funcction prototypes
struct node* createnode(int data);
struct node* insert(struct node* root, int data);
void inorder(struct node* root);
#endif
