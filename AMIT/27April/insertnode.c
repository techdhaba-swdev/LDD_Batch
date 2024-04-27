#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

                                                          // Function to insert a new node into the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

