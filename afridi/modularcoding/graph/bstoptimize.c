#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
Node* insert(Node* root, int data) {
    if (!root) return createNode(data);

    Node* current = root;
    Node* parent = NULL;
    while (current) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return root; // Duplicate values not allowed
    }

    if (data < parent->data)
        parent->left = createNode(data);
    else
        parent->right = createNode(data);
    
    return root;
}

// Function to find the minimum value node in a subtree
static Node* minValueNode(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// Function to delete a node from BST
Node* deleteNode(Node* root, int data) {
    if (!root) return root;

    Node* current = root;
    Node* parent = NULL;
    while (current && current->data != data) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (!current) return root; // Node not found

    if (!current->left) {
        Node* temp = current->right;
        free(current);
        if (!parent) return temp; // If root node is to be deleted
        if (parent->left == current)
            parent->left = temp;
        else
            parent->right = temp;
    } else if (!current->right) {
        Node* temp = current->left;
        free(current);
        if (!parent) return temp; // If root node is to be deleted
        if (parent->left == current)
            parent->left = temp;
        else
            parent->right = temp;
    } else {
        Node* temp = minValueNode(current->right);
        current->data = temp->data;
        current->right = deleteNode(current->right, temp->data);
    }
    return root;
}

// Function to search for a value in BST
Node* search(const Node* root, int data) {
    const Node* current = root;
    while (current) {
        if (data == current->data)
            return (Node*)current;
        else if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return NULL;
}

// Function to perform in-order traversal of BST
void inOrderTraversal(const Node* root) {
    if (!root) return;

    Node* current = root;
    Node* stack[100];
    int top = -1;

    while (current || top != -1) {
        while (current) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function to free memory allocated for BST
void freeBST(Node* root) {
    if (!root) return;

    Node* current = root;
    Node* stack[100];
    int top = -1;

    do {
        while (current) {
            if (current->right)
                stack[++top] = current->right;
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if (current->right && stack[top] == current->right) {
            stack[top--] = current;
            stack[++top] = current->right;
            current = current->right;
        } else {
            free(current);
            current = NULL;
        }
    } while (top != -1);
}

int main() {
    Node* root = NULL;

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
    Node* searchResult = search(root, searchValue);
    if (searchResult)
        printf("%d found in the BST\n", searchValue);
    else
        printf("%d not found in the BST\n", searchValue);

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
