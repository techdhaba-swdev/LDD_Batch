#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure definition for a node in the binary tree
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

// Function to insert a node into the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {  // Base case: Empty tree, create a new root node
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in left subtree for smaller values
    } else if (data > root->data) {
        root->right = insert(root->right, data);  // Insert in right subtree for larger values
    } else { // Handle duplicates (optional: can modify to overwrite or reject)
        // printf("Duplicate value: %d\n", data);
    }

    return root;  // Return the (potentially modified) root node
}

// Function to perform in-order traversal of the binary tree and calculate the sum
int sumNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// Function to perform in-order traversal of the binary tree and print the nodes
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);  // Visit left subtree
        printf("%d ", root->data);  // Visit current node
        inOrder(root->right); // Visit right subtree
    }
}

// Main function: Example usage
int main() {
    clock_t start = clock();

    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 10); // Additional nodes
    insert(root, 25); // Additional nodes
    insert(root, 35); // Additional nodes

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    int totalSum = sumNodes(root);
    printf("Sum of all nodes: %d\n", totalSum);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}


