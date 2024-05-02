#ifndef BST_H
#define BST_H

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

TreeNode* createNode(char data);
TreeNode* buildTree(char* expression);
int evaluate(TreeNode* root);
void inOrderTraversal(TreeNode* root);

#endif /* BST_H */
