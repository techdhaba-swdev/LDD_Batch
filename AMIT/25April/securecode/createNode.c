#include<stdio.h>
#include<stdlib.h>
#include"mystruct.h"

// Function to create a new node
struct Node* createNode(int value)                                   //createNode is the function with return type is struct Node*
{                                                                    //allowcating dynamic memory to newNode using malloc to create new node  
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {                                            //memory allocation will fail if newNode is NULL
        print_message("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;                                          //the value parameter is assign to the data 

    newNode->next = NULL;                                         //newNode is set to NULL
    return newNode;
}
