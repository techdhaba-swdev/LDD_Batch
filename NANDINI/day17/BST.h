#ifndef TREE_H_
#define TREE_H_

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);

#endif /* TREE_H_ */
