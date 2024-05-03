#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Node structure for the Binary Search Tree (BST)
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototypes
Node* createNode(int data);
Node* insert(Node* root, int data);
Node* delete(Node* root, int data);
Node* minValueNode(Node* node);
Node* search(Node* root, int data);
void inOrderTraversal(Node* root);
void preOrderTraversal(Node* root);
void postOrderTraversal(Node* root);
bool isBST(Node* root);
int height(Node* root);
void findMinMax(Node* root, int* min, int* max);

int main() {
    Node* root = NULL;

    // Insert some nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print in-order traversal (should be sorted)
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Print pre-order traversal
    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    // Print post-order traversal
    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    // Check if BST
    printf("Is BST? %s\n", isBST(root) ? "Yes" : "No");

    // Find height of BST
    printf("Height of BST: %d\n", height(root));

    // Find minimum and maximum values
    int min, max;
    findMinMax(root, &min, &max);
    printf("Minimum value in BST: %d\n", min);
    printf("Maximum value in BST: %d\n", max);

    // Search for a value
    int searchValue = 30;
    Node* searchResult = search(root, searchValue);
    printf("Search for value %d: %s\n", searchValue, searchResult ? "Found" : "Not found");

    // Delete a node
    int deleteValue = 20;
    root = delete(root, deleteValue);
    printf("In-order traversal after deleting %d: ", deleteValue);
    inOrderTraversal(root);
    printf("\n");

    // Free memory (optional)
    // Implement your own function for deleting the tree nodes

    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to delete a node from BST
Node* delete(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Function to find the node with the minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to search for a node in BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to perform in-order traversal (left, root, right)
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform pre-order traversal (root, left, right)
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal (left, right, root)
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to check if a binary tree is a binary search tree (BST)
bool isBSTUtil(Node* root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    if (root->data < min || root->data > max) {
        return false;
    }
    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Function to find the height of a binary tree
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function to find the minimum and maximum values in a binary tree
void findMinMax(Node* root, int* min, int* max) {
    if (root == NULL) {
        return;
    }
    if (root->data < *min) {
        *min = root->data;
    }
    if (root->data > *max) {
        *max = root->data;
    }
    findMinMax(root->left, min, max);
    findMinMax(root->right, min, max);
}




