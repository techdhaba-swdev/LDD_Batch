#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        newNode->next = *headRef;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != *headRef) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *headRef;
        *headRef = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        newNode->next = *headRef;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != *headRef) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *headRef;
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
