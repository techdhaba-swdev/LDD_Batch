#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

// Function to create a new node
DoublyNode* createNode(int data) {
    DoublyNode *newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(DoublyNode **head, int data) {
    DoublyNode *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        DoublyNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to print all nodes in the list
void printList(DoublyNode *head) {
    printf("Nodes in the list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

