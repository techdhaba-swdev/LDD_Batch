#ifndef BST_H
#define BST_H
#include "node.h"

// Function to insert a new node into the tree while maintaining the BST property
struct node* insert(struct node* root, int data);

// Function to search for a node with the given data in the tree
int search(struct node* root, int data);

// Function to perform an in-order traversal of the tree (prints node values)
void inorderTraversal(struct node* root);

#endif 
