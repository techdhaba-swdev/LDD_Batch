#ifndef BST_H
#define BST_H

// Structure for a binary tree node
typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} Node;

// Function to create a new node
Node* newNode(int data);

// Function to check if a binary tree is a BST
int is_bst(Node* node, int min_val, int max_val);

// Function to find the height of a binary tree
int height(Node* node);

// Function to find the minimum and maximum values in a binary tree
void find_min_max(Node* node, int* min_val, int* max_val);


#endif
