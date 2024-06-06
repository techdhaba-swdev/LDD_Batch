#ifndef BST_H
#define BST_H

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* createnode(int data);
struct node* insert(struct node* root, int data);
int search(struct node* root, int data);
void inorderTraversal(struct node* root);

#endif




