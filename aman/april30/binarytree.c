#include <stdio.h>
#include <stdlib.h>
#include<time.h>
// Structure definition for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    // Initialize node's data and child pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new root node
    if (root == NULL) {
        return createNode(data);
    }
    
    // If data is less than current node's data, insert into the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If data is greater than current node's data, insert into the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // Handle duplicates (optional: can modify to overwrite or reject)
    else {
        printf("Duplicate value: %d\n", data);
    }
    
    return root;
}

// Function to perform in-order traversal of the binary tree
void inOrder(struct Node* root) {
    if (root != NULL) {
        // Traverse left subtree
        inOrder(root->left);
        // Visit current node
        printf("%d ", root->data);
        // Traverse right subtree
        inOrder(root->right);
    }
}
// Function to add all the values in the binary tree
int sumAll(struct Node* root) {
    // Base case: if root is NULL (empty tree), return 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursive case: add the current node's value
    // to the sum of values in its left and right subtrees
    int sum = root->data;
    sum += sumAll(root->left);
    sum += sumAll(root->right);
    
    return sum;
}


// Main function: Example usage
int main() {
	clock_t start = clock();
    struct Node* root = NULL;
    
    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    // Print in-order traversal of the binary tree
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");
     int totalSum = sumAll(root);
    
    // Print the total sum
    printf("Total sum of all values in the binary tree: %d\n", totalSum);
    clock_t stop = clock();
    double time_taken = ((double)(stop - start));
    printf("time taken %f\n", time_taken);
    // Free memory allocated for the binary tree (optional)
    // FreeTree(root);
    
    return 0;
}
