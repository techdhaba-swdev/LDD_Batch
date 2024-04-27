#ifndef BST_H
#define BST_H

struct node {
    int data; // Integer value stored in the node
    struct node* left; // Pointer to the left child node
    struct node* right; // Pointer to the right child node
};

struct node* createNode(int data); // Function to create a new node
struct node* insert(struct node* root, int data); // Function to insert a new node into the BST
int search(struct node* root, int data); // Function to search for a node with a given data
void inorderTraversal(struct node* root); // Function to perform an in-order traversal of the BST
int findMin(struct node* root); // Function to find the minimum value in the BST
int findMax(struct node* root); // Function to find the maximum value in the BST
struct node* deleteNode(struct node* root, int data); // Function to delete a node from the BST
struct node* minValueNode(struct node* node); // Function to find the inorder successor (smallest in the right subtree)
int height(struct node* root); // Function to calculate the height of the BST

#endif /* BST_H */
