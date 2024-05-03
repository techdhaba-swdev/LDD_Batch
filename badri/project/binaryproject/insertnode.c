#include "node.h"//includes node.h header file which contains node structure
// Function to insert a new node
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {//checks  If the root is NULL or not
        return createNode(data); //returns to  CreateNode function to create a new node as the root if the root is null
    }
    if (data < root->data) {// If the data is less than root data
        root->left = insert(root->left, data);// Recursively insert into the left subtree
    } else if (data > root->data) {// If the data is greater than root data
        root->right = insert(root->right, data);// Recursively insert into the right subtree
    }
    return root;// Return the root to the insert function
}

