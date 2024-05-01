#ifndef BTREE_H//preproccessor directive which check  that given identifier btree_h has defined in file or not
#define BTREE_H//preprocessor useed to define macro btree_h

// Structure definition for a node in the binary tree
struct Node {
    int data;//integer variable to hold data of node
    struct Node* left;// pointer to left child node
    struct Node* right;//pointer to righ childnode
};


struct Node* createNode(int data);//function prototype for createnode function defined in btree.c
struct Node* insert(struct Node* root, int data);//function prototype for insert function
void inOrder(struct Node* root);//function for inorder traversal
int sumAll(struct Node* root);//function for sum of allvalues of nodes

#endif //end 
