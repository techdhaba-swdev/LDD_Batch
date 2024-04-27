#include "bst.h"      // Include the custom header file for the BST implementation
#include <stdio.h>    // Include the standard input/output header file for printf
#include <stdlib.h>   // Include the standard library header file for malloc, free, and exit

// Function to create a new node with the given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));  // Allocate memory for the new node
    if (newNode == NULL) {  // Check if memory allocation failed
        fprintf(stderr, "Memory allocation failed\n");  // Print an error message to stderr
        exit(EXIT_FAILURE);  // Exit the program with a failure status
    }
    newNode->data = data;  // Set the data of the new node
    newNode->left = NULL;  // Set the left child of the new node to NULL
    newNode->right = NULL; // Set the right child of the new node to NULL
    return newNode;  // Return a pointer to the new node
}

// Function to insert a node with the given data into the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) {  // If the root is NULL, create a new node as the root
        return createNode(data);
    }

    if (data < root->data) {  // If the data is less than the root's data, insert into the left subtree
        root->left = insert(root->left, data);
    } else if (data > root->data) {  // If the data is greater than the root's data, insert into the right subtree
        root->right = insert(root->right, data);
    }

    return root;  // Return the root of the modified tree
}

// Function to search for a node with the given data in the BST
int search(struct node* root, int data) {
    if (root == NULL) {  // If the root is NULL, the node is not found
        return 0;
    }

    if (root->data == data) {  // If the data is equal to the root's data, the node is found
        return 1;
    } else if (data < root->data) {  // If the data is less than the root's data, search in the left subtree
        return search(root->left, data);
    } else {  // If the data is greater than the root's data, search in the right subtree
        return search(root->right, data);
    }
}

// Function to perform an in-order traversal of the BST
void inorderTraversal(struct node* root) {
    if (root != NULL) {  // If the root is not NULL
        inorderTraversal(root->left);  // Recursively traverse the left subtree
        printf("%d ", root->data);     // Print the data of the current node
        inorderTraversal(root->right); // Recursively traverse the right subtree
    }
}

// Function to delete a node with the given data from the BST
struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) {  // If the root is NULL, return NULL
        return root;
    }

    if (data < root->data) {  // If the data is less than the root's data, delete from the left subtree
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {  // If the data is greater than the root's data, delete from the right subtree
        root->right = deleteNode(root->right, data);
    } else {  // If the data is equal to the root's data (node to be deleted found)
        if (root->left == NULL) {  // If the node has no left child
            struct node* temp = root->right;  // Store the right child in a temporary variable
            free(root);  // Free the memory occupied by the root
            return temp; // Return the right child to be the new root
        } else if (root->right == NULL) {  // If the node has no right child
            struct node* temp = root->left;  // Store the left child in a temporary variable
            free(root);  // Free the memory occupied by the root
            return temp; // Return the left child to be the new root
        }

        // If the node to be deleted has two children
        struct node* temp = minValueNode(root->right);  // Find the inorder successor (minimum value in the right subtree)
        root->data = temp->data;  // Copy the inorder successor's data to the root
        root->right = deleteNode(root->right, temp->data);  // Delete the inorder successor
    }

    return root;  // Return the root of the modified BST
}

// Function to find the node with the minimum value in the BST
struct node* minValueNode(struct node* node) {
    struct node* current = node;  // Initialize current as the given node
    while (current && current->left != NULL) {  // Traverse down the left subtree to find the minimum value
        current = current->left;  // Update current to the left child
    }
    return current;  // Return the node with the minimum value
}

// Function to find the node with the maximum value in the BST
struct node* maxValueNode(struct node* node) {
    struct node* current = node;  // Initialize current as the given node
    while (current && current->right != NULL) {  // Traverse down the right subtree to find the maximum value
        current = current->right;  // Update current to the right child
    }
    return current;  // Return the node with the maximum value
}

// Function to calculate the height of the BST
int height(struct node* root) {
    if (root == NULL) {  // If the root is NULL
        return -1;       // Return -1 (height of an empty tree)
    }

    int leftHeight = height(root->left);    // Recursively calculate the height of the left subtree
    int rightHeight = height(root->right);  // Recursively calculate the height of the right subtree

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);  // Return the maximum height of the two subtrees + 1 (for the root)
}
