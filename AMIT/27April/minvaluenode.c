#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

struct node* maxValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->right)
        current = current->right;
    return current;
}
