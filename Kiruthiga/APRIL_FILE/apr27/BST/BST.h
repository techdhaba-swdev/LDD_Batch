#ifndef BST_H
#define BST_H
struct node {   // Struct definition for a node in the BST
int data;     
struct node* left;
struct node* right;
}; 
struct node* createNode(int data);
struct node* insert(struct node* root, int data);
int search(struct node* root, int data);
void inorderTraversal(struct node* root); // Optional functions for other operations
#endif

