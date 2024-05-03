#ifndef SEARCH_H
#define SEARCH_H

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

int isBST(TreeNode* root);

#endif /* SEARCH_H */
