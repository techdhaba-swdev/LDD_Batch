#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

                                           // Function to search for a node with the given data in the BST
int search(struct node* root, int data) {
    if (root == NULL)
        return 0;

    if (root->data == data)
        return 1;
    else if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}
