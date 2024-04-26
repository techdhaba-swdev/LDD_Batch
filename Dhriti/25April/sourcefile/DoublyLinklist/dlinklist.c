#include <stdio.h>
#include <stdlib.h>
#include<stddef.h>
#include "dlinklist.h"

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE); //SECURING BY HANDLING MEMORY ALLOCATION FALIURE
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) { //SECURED IF MALLOC FAILS IN ALLOCATING IT RETURNS NULL
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("%d inserted at the beginning.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end.\n", data);
}

// Function to delete a node by its value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->data == key) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;

        free(temp); //SECURED BY DEALLOCATING THE DELETED NODE

        printf("%d deleted from the list.\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("%d deleted from the list.\n", key);
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to search for a value in the list
void search(struct Node* head, int key) {
    int position = 0;
    while (head != NULL && head->data != key) {
        head = head->next;
        position++;
    }
    if (head == NULL) {
        printf("%d not found in the list.\n", key);
    } else {
        printf("%d found at position %d.\n", key, position);
    }
}

