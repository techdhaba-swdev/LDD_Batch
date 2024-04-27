#include<stdio.h>
#include"binarysearchtree.h"
//create node API
struct node* createnode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node)); //creating space everytime to store
    temp->data = data; //storing data into temp
    temp->left = NULL; //Initializing left child of parent node to NULL
    temp->right = NULL; //Initializing right child of parent node to NULL
    return temp;
}

// Insert API
struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return createnode(data);
    }

    // Recursively insert based on data value
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Search API
struct node* search(struct node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }

    // Recursively search based on data value
    if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

// Find minimum API
struct node* find_min(struct node* node) {
    if (node == NULL) {
        return node;
    }
    else if (node->left != NULL) {
        return find_min(node->left);
    }
    return node; // Traverse left subtree for minimum
}

// Find maximum API
struct node* find_max(struct node* node) {
    if (node == NULL || node->right == NULL) {
        return node;
    }

    return find_max(node->right); // Traverse right subtree for maximum
}
void inordertraversal(struct node* root) //Inordertraversal API that takes parent as argument and prints all elements
{
    if (root != NULL) {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
}

// Delete API (handles one child, two children, and leaf node cases)
struct node* delete(struct node* node, int data)
{
    if (node == NULL) {
        return node; // Node not found, do nothing
    }

    // Recursively search for the node to delete
    if (data < node->data) {
        node->left = delete(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = delete(node->right, data);
    } else { // Node found
        // Handle one child or no child case
        if (node->left == NULL)
        {
            struct node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->left == NULL
                 || node->right == NULL) {
            struct node* temp;
            if (node->left == NULL) {
                temp = node->right;
            }
            else {
                temp = node->left;
            }
            free(node);
            return temp;
        }
        else {
            struct node* temp
                = find_min(node->right);
            node->data = temp->data;
            node->right = delete (node->right, temp->data);
        }
    }
    return node;
}


