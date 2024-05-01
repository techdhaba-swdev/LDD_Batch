#include"tree.h"

struct Node {
 	int data;
 	struct Node* left;
 	struct Node* right;
 };

struct Node* createNode(int data) {
 	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 	newNode->data = data;
 	newNode->left = NULL;
 	newNode->right = NULL;
 	return newNode;
 }

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
 
// Function to perform in-order traversal of the binary tree
 void inOrder(struct Node* root) {
 	if (root != NULL) {
     	inOrder(root->left);  // Visit left subtree
     	printf("%d ", root->data);  // Visit current node
     	inOrder(root->right); // Visit right subtree
 	}
 }

int sumOfNodes(struct Node* root) {
    if (root == NULL) {
        return 0; // Base case: empty subtree contributes 0 to the sum
    }

    // Recursively calculate sum of left and right subtrees, and add current node's value
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}


