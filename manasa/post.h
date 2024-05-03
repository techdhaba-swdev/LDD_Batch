#ifndef POST_H_
#define POST_H_

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);

#endif /* POST_H_ */
