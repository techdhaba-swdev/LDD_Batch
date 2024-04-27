#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

                                            // Function for inorder traversal for verification
void inorderTraversal(struct node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
