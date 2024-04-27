#ifndef BST_H
#define BST_H

struct node {int data;     
	struct node* left;
	struct node* right;
};


struct node* createNode(int data);
struct node* insert(struct node* root, int data);
int search(struct node* root, int data);
void inorderTraversal(struct node* root);
struct node* minValueNode(struct node* node);
struct node* maxValueNode(struct node* node);
int treeHeight(struct node* root) ;
//struct node* deleteNode(struct node* root, int key);


#endif
