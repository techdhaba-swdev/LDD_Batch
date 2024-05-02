#ifndef SUS_H
#define SUS_H
//define a structure representing a node
struct Node {
    int data;   
    struct Node* left;
    struct Node* right;
};
//it will creates new node
struct Node* createNode(int data);
//insert a new node
struct Node* insert(struct Node* root, int data);
//to perform in order traversal
void inOrder(struct Node* root);
// calculates the sum of all node values
int calculateSum(struct Node* root);

#endif
