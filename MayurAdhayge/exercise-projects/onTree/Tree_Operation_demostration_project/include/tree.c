#include "tree.h"

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    else if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = root->right;
        while (temp->left != NULL) temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to search for a value in BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) return root;
    else if (data < root->data) return search(root->left, data);
    else return search(root->right, data);
}

// Function to perform in-order traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform pre-order traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform post-order traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to check if a binary tree is a BST
bool isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) return true;
    if (root->data < min || root->data > max) return false;
    return (isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max));
}

bool isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Function to find the height of a binary tree
int maxDepth(struct Node* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

// Function to find the minimum value in a binary tree
int minValue(struct Node* root) {
    if (root == NULL) return -1; // Error handling
    while (root->left != NULL) root = root->left;
    return root->data;
}

// Function to find the maximum value in a binary tree
int maxValue(struct Node* root) {
    if (root == NULL) return -1; // Error handling
    while (root->right != NULL) root = root->right;
    return root->data;

         
}

