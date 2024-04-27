#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

int treeHeight(struct node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
