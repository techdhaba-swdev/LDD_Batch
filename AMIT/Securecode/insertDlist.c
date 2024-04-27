#include<stdio.h>
#include<stdlib.h>
#include"doublylist.h"

// Function to insert a node at the beginning of the list
void insertAtStart(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

