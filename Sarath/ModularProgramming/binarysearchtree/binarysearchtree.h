#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <stdlib.h>

// Function prototypes which used in main
struct node* insert(struct node* node, int data);
struct node* search(struct node* node, int data);
struct node* find_min(struct node* node);
struct node* find_max(struct node* node);
struct node* delete(struct node* node, int data);
void inordertraversal(struct node* node);
int calculatesum(struct node* root);
#endif
