#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    // Initialize the node's data and pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        // If the root is NULL, create a new node and return it
        return createNode(data);
    }
    if (data < root->data) {
        // If data is smaller than root's data, go to the left subtree
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // If data is greater than root's data, go to the right subtree
        root->right = insert(root->right, data);
    }
    // Return the unchanged root pointer
    return root;
}

// Function to find the minimum value node in a subtree
static struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        // Return if the tree is empty
        return root;
    }
    if (data < root->data) {
        // If the data to be deleted is smaller, go to the left subtree
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        // If the data to be deleted is greater, go to the right subtree
        root->right = deleteNode(root->right, data);
    } else {
        // If the data is the same as the root's data, then this is the node to be deleted
        if (root->left == NULL) {
            // If the node has only one child or no child
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // If the node has two children, get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    // Return the unchanged root pointer
    return root;
}

// Function to search for a value in BST
struct Node* search(const struct Node* root, int data) {
    const struct Node* current = root;
    // Traverse the tree until the node is found or the end is reached
    while (current != NULL && current->data != data) {
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // Return the found node or NULL if not found
    return (struct Node*)current;
}

// Function to perform in-order traversal of BST
void inOrderTraversal(const struct Node* root) {
    if (root != NULL) {
        // Traverse the left subtree
        inOrderTraversal(root->left);
        // Print the current node's data
        printf("%d ", root->data);
        // Traverse the right subtree
        inOrderTraversal(root->right);
    }
}

// Function to free memory allocated for BST
void freeBST(struct Node* root) {
    if (root != NULL) {
        // Free memory for left and right subtrees recursively
        freeBST(root->left);
        freeBST(root->right);
        // Free memory for the current node
        free(root);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert some values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the in-order traversal of the BST
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    // Search for a value in the BST
    int searchValue = 70;
    struct Node* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("%d found in the BST\n", searchValue);
    } else {
        printf("%d not found in the BST\n", searchValue);
    }

    // Delete a value from the BST
    int deleteValue = 30;
    root = deleteNode(root, deleteValue);

    // Print the in-order traversal after deletion
    printf("In-order traversal after deleting %d: ", deleteValue);
    inOrderTraversal(root);
    printf("\n");

    // Free memory allocated for the BST
    freeBST(root);

    return 0;
}
