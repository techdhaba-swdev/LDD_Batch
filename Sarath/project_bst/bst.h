#ifndef BST_H_
#define BST_H_
#include<math.h>
#include<stdlib.h>
struct node *createnode(int data);
struct node *insert(struct node *node,int data);
struct node* search(struct node* node, int data);
struct node* find_min(struct node* node);
struct node* find_max(struct node* node);
struct node* delete(struct node* node, int data);
void inordertraversal(struct node* node);
void preorder(struct node *node);
void postorder(struct node *node);
int calculatesum(struct node *root);
int height(struct node *root);
int count(struct node *root);

#endif
