#include "search.h"
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

bool isBSTUtil(TreeNode* root, int min_val, int max_val) {
    if (root == NULL) 
        return true;
    
    if (root->val <= min_val || root->val >= max_val)
        return false;
    
    return isBSTUtil(root->left, min_val, root->val) && isBSTUtil(root->right, root->val, max_val);
}

int isBST(TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
