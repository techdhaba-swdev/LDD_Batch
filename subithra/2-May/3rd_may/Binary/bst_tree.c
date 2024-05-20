#include <stdio.h> // Standard input-output header
#include <stdlib.h> // Standard library header
#include <limits.h> // Header for limits of integral types
#include "bst_tree.h" // Header file for BST operations

// Structure representing a node in the binary search tree
struct Node {
    int data; // Data stored in the node
    struct Node *left; // Pointer to the left child node
    struct Node *right; // Pointer to the right child node
};

// Function to create a new node with the given data
// Used to secure: Memory allocation (malloc) is checked for errors
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    if (newNode == NULL) { // Check if memory allocation was successful
        printf("Memory allocation error.\n"); // Print error message
        exit(EXIT_FAILURE); // Exit the program with failure status
    }
    newNode->data = data; // Assign data to the new node
    newNode->left = NULL; // Initialize left child as NULL
    newNode->right = NULL; // Initialize right child as NULL
    return newNode; // Return the pointer to the new node
}

// Function to insert a value into the binary search tree
// Used to secure: Proper insertion into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) { // If the tree is empty
        return createNode(data); // Create a new node and return it as the root
    }
    if (data < root->data) { // If data is less than the current node's data
        root->left = insert(root->left, data); // Recursively insert into the left subtree
    } else if (data > root->data) { // If data is greater than the current node's data
        root->right = insert(root->right, data); // Recursively insert into the right subtree
    }
    return root; // Return the modified root
}

// Function to find the node with the minimum value in the tree
// Used to secure: Proper deletion of a node
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node; // Initialize current node as the given node
    while (current && current->left != NULL) { // Traverse to the leftmost node
        current = current->left; // Move to the left child
    }
    return current; // Return the leftmost node
}

// Function to delete a node with the given key from the binary search tree
// Used to secure: Proper deletion of a node and memory deallocation
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) { // If the tree is empty
        return root; // Return NULL
    }
    if (key < root->data) { // If the key is less than the current node's data
        root->left = deleteNode(root->left, key); // Recursively delete from the left subtree
    } else if (key > root->data) { // If the key is greater than the current node's data
        root->right = deleteNode(root->right, key); // Recursively delete from the right subtree
    } else { // If the key is found
        if (root->left == NULL) { // If the node has no left child
            struct Node* temp = root->right; // Store the right child
            free(root); // Free memory allocated for the node
            return temp; // Return the right child as the new root
        } else if (root->right == NULL) { // If the node has no right child
            struct Node* temp = root->left; // Store the left child
            free(root); // Free memory allocated for the node
            return temp; // Return the left child as the new root
        }
        struct Node* temp = minValueNode(root->right); // Find the inorder successor
        root->data = temp->data; // Copy the inorder successor's data to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root; // Return the modified root
}

// Function to search for a value in the binary search tree
// Used to secure: Proper search operation
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) { // If the tree is empty or the key is found
        return root; // Return the current node
    }
    if (root->data < key) { // If the key is greater than the current node's data
        return search(root->right, key); // Search in the right subtree
    }
    return search(root->left, key); // Search in the left subtree
}

// Function to perform in-order traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) { // If the current node is not NULL
        inorderTraversal(root->left); // Recursively traverse the left subtree
        printf("%d ", root->data); // Print the current node's data
        inorderTraversal(root->right); // Recursively traverse the right subtree
    }
}

// Function to perform pre-order traversal of the binary search tree
void preorderTraversal(struct Node* root) {
    if (root != NULL) { // If the current node is not NULL
        printf("%d ", root->data); // Print the current node's data
        preorderTraversal(root->left); // Recursively traverse the left subtree
        preorderTraversal(root->right); // Recursively traverse the right subtree
    }
}

// Function to perform post-order traversal of the binary search tree
void postorderTraversal(struct Node* root) {
    if (root != NULL) { // If the current node is not NULL
        postorderTraversal(root->left); // Recursively traverse the left subtree
        postorderTraversal(root->right); // Recursively traverse the right subtree
        printf("%d ", root->data); // Print the current node's data
    }
}

// Function to check if the binary tree is a binary search tree (BST)
// Used to secure: Verification if the tree is BST
int isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) { // If the current node is NULL
        return 1; // Return true
    }
    if (root->data < min || root->data > max) { // If the current node's data is out of range
        return 0; // Return false
    }
    return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max); // Recursively check left and right subtrees
}

// Function to check if the binary tree is a binary search tree (BST)
int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX); // Check if the tree is a BST within the specified range
}

// Function to calculate the height of the binary tree
int height(struct Node* root) {
    if (root == NULL) { // If the current node is NULL
        return 0; // Return 0
    }
    int leftHeight = height(root->left); // Calculate height of the left subtree
    int rightHeight = height(root->right); // Calculate height of the right subtree
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1); // Return the maximum height
}

// Function to find the minimum value in the binary search tree
int minValue(struct Node* root) {
    struct Node* current = root; // Start from the root node
    while (current->left != NULL) { // Traverse to the leftmost node
        current = current->left; // Move to the left child
    }
    return current->data; // Return the data of the leftmost node
}

// Function to find the maximum value in the binary search tree
int maxValue(struct Node* root) {
    struct Node* current = root; // Start from the root node
    while (current->right != NULL) { // Traverse to the rightmost node
        current = current->right; // Move to the right child
    }
    return current->data; // Return the data of the rightmost node
}