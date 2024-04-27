#ifndef TREENODE_H // This checks whether the macro BST_H is not defined. If it's not defined, it means that the header file hasn't been included yet.

#define TREENODE_H // This defines the macro BST_H. By defining it here, we ensure that subsequent inclusions of the header file won't enter the #ifndef block because BST_H is already defined.


#include <stdio.h> // it includes the standard input output function 
#include <stdlib.h> // it includes the standard library function



// Define the structure for a node in the BST
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function prototypes
struct node* createNode(int data);
struct node* insert(struct node* root, int data);
int search(struct node* root, int data);
void inorderTraversal(struct node* root);
struct node* deleteNode(struct node* root, int data);
int findMinValue(struct node* root);
int findMaxValue(struct node* root);
int findHeight(struct node* root);


#endif // This defines the macro BST_H. By defining it here, we ensure that subsequent inclusions of the header file won't enter the #ifndef block because BST_H is already defined.


