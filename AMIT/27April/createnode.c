#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"


                                                                              // Function to create a new node
struct node* createNode(int data) {                                           //alowcating size to newNode
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {                                                  
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

