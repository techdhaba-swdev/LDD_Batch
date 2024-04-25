#include<stdio.h>
#include<stdlib.h>
#include"mystruct.h"

// Function to insert a node at the beginning
void insertAtStart(struct Node** head, int value)  //insertAtStart is the function with parameter of struct Node** head and int value 
						   //it is pointer to the pointer to head of the linked list it allow us to modify head
{                                                   //and int value that new node will hold
    struct Node* newNode = createNode(value); //newNode will create new node using memory allowcation
    newNode->next = *head;                         //next is pointter to new node is set to head
    *head = newNode;                       //head pointer updated to the new node
}
