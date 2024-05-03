#ifndef BSTFUNC_H
#define BSTFUNC_H

// Structure for a Node in BST
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

// Function declarations
TreeNode* createNode(int data);
TreeNode* insert(TreeNode* root, int data);
TreeNode* deleteNode(TreeNode* root, int key);
TreeNode* search(TreeNode* root, int key);
void inorderTraversal(TreeNode* root);
void preorderTraversal(TreeNode* root);
void postorderTraversal(TreeNode* root);
int isBST(TreeNode* root);
int findHeight(TreeNode* root);
void findMinMax(TreeNode* root, int* min, int* max);

#endif /* BSTFUNC_H */
