#include <stdlib.h>
#include <stdio.h>
#include "sus.h"

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
//function to insert a node
struct Node* insert(struct Node* root, int data) {
	//create new node
    if (root == NULL) {
        return createNode(data);
    }
    //if data is less than the root it will insert into left sub tree
    if (data < root->data) {
        root->left = insert(root->left, data);
	//if data is greater than the root it will insert into right sub tree
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
     
	    // Handle duplicates
	    printf("Duplicates values: %d\n",data);
    }
    //return to the root node
    return root;
}
//function to perform in order traversal
void inOrder(struct Node* root) {
	//if root is not null
    if (root != NULL) {
	    //enter into left subtree
        inOrder(root->left);
	//enter into current node
        printf("%d ", root->data);
	//enter into right node
        inOrder(root->right);
    }
}
//function to calculate sum of all values
int calculateSum(struct Node* root) {
	//if rootr is null return 0
    if (root == NULL) {
        return 0;
    }
    return root->data + calculateSum(root->left) + calculateSum(root->right);
}

