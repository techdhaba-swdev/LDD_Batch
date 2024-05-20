#ifndef BST_H
#define BST_H

/*
 * Header file for Binary Search Tree (BST) operations
 * This file contains declarations for functions and structures related to BST.
 */

// Forward declaration of the Node structure
struct Node;

// Function declarations

struct Node* createNode(int data);
/*
 * Function to create a new node with the given data.
 * Parameters:
 *   - data: The data value to be stored in the new node.
 * Returns:
 *   - A pointer to the newly created node.
 */

struct Node* insert(struct Node* root, int data);
/*
 * Function to insert a value into the binary search tree.
 * Parameters:
 *   - root: A pointer to the root node of the binary search tree.
 *   - data: The value to be inserted.
 * Returns:
 *   - A pointer to the root of the modified binary search tree.
 */

struct Node* deleteNode(struct Node* root, int key);
/*
 * Function to delete a node with the given key from the binary search tree.
 * Parameters:
 *   - root: A pointer to the root node of the binary search tree.
 *   - key: The value to be deleted from the tree.
 * Returns:
 *   - A pointer to the root of the modified binary search tree.
 */

struct Node* search(struct Node* root, int key);
/*
 * Function to search for a value in the binary search tree.
 * Parameters:
 *   - root: A pointer to the root node of the binary search tree.
 *   - key: The value to search for in the tree.
 * Returns:
 *   - A pointer to the node containing the searched value, or NULL if not found.
 */

void inorderTraversal(struct Node* root);
/*
 * Function to perform in-order traversal of the binary search tree.
 * Parameters:
 *   - root: A pointer to the root node of the binary search tree.
 */

void preorderTraversal(struct Node* root);
/*
 * Function to perform pre-order traversal of the binary search tree.
 * Parameters:
 *   - root: A pointer to the root node of the binary search tree.
 */

void postorderTraversal(struct Node* root);
/*
 * Function to perform post-order traversal of the binary search tree.
 * Parameters:
 *   - root: A pointer to the root node of the binary search tree.
 */

int isBST(struct Node* root);
/*
 * Function to check if the binary tree is a binary search tree (BST).
 * Parameters:
 *   - root: A pointer to the root node of the binary tree.
 * Returns:
 *   - 1 if the tree is a BST, 0 otherwise.
 */

int height(struct Node* root);
/*
 * Function to calculate the height of the binary tree.
 * Parameters:
 *   - root: A pointer to the root node of the binary tree.
 * Returns:
 *   - The height of the binary tree.
 */

int minValue(struct Node* root);
/*
 * Function to find the minimum value in the binary search tree.
 * Parameters:
 *   - root: A pointer to the root node of the binary search tree.
 * Returns:
 *   - The minimum value in the binary search tree.
 */

int maxValue(struct Node* root);
/*
 * Function to find the maximum value in the binary search tree.
 * Parameters:
 *   - root: A pointer to the root node of the binary search tree.
 * Returns:
 *   - The maximum value in the binary search tree.
 */
#endif /* BST_H */