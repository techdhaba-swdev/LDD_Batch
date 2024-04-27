#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <stdlib.h>

//Created a structure to store elements
struct node { 
    int data;
    struct node* left;
    struct node* right;
};

// Function prototypes which used in main
struct node* insert(struct node* node, int data);
struct node* search(struct node* node, int data);
struct node* find_min(struct node* node);
struct node* find_max(struct node* node);
struct node* delete(struct node* node, int data);
void inordertraversal(struct node* node);
#endif
