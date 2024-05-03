#include "header.h"//includes headerfile containing stdio.h , stdlib.h , stdbool.h , linit.h
#include "node.h"//includes node.h containing node fuction declaration
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));// Allocate memory for a new node
    if (newNode == NULL) {// Check if memory allocation failed
        fprintf(stderr, "Memory allocation failed\n");// Print error message to the os 
        exit(1);// Exit program if allocation failed unsuccesfull termination of program
    }
    newNode->data = data;// Assign data to the new node
    newNode->left = NULL;// Initialize left child pointer to NULL
    newNode->right = NULL;// Initialize right child pointer to NULL
    return newNode;// Return the new node
}
