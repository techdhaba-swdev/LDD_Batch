#include <stdio.h>
#include <stdlib.h>
#include<time.h>
// Node structure definition
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
void freeTree(struct Node* root); // Function to free memory used by tree nodes

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to recursively free memory used by the tree nodes
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left); // Free left subtree
    freeTree(root->right); // Free right subtree
    free(root); // Free current node
}

// inserting data into the binary tree
struct Node* insert(struct Node* root, int data);

//  in-order traversal
void inOrder(struct Node* root);

// sum of all node data elements
int sumOfNodes(struct Node* root);

// insert data into the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data); // Create new node if tree is empty

    if (data < root->data) root->left = insert(root->left, data); // Insert in left subtree for smaller values
    else if (data > root->data) root->right = insert(root->right, data); // Insert in right subtree for larger values

    return root; // Return the  root node
}

// Function to perform in-order traversal of the binary tree
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left); // Visit left subtree
        printf("%d ", root->data); // Visit current node
        inOrder(root->right); // Visit right subtree
    }
}

// Function to calculate the sum of all node data elements
int sumOfNodes(struct Node* root) {
    if (root == NULL) return 0; // Base case: empty node, sum is 0
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right); // Sum of current node and its subtrees
}

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

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    int totalSum = sumOfNodes(root);
    printf("Sum of all node data elements: %d\n", totalSum);
     clock_t end = clock();
     double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
     printf("Time taken: %f seconds\n", time_taken);


    freeTree(root); // Free memory used by tree nodes

    return 0;
}
