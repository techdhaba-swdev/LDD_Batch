#include "circularlist.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node with given data from the circular linked list
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* current = *head;
    Node* prev = NULL;
    while (current->data != data) {
        if (current->next == *head) {
            printf("Node with data %d not found!\n", data);
            return;
        }
        prev = current;
        current = current->next;
    }
    if (current == *head && current->next == *head) {
        free(current);
        *head = NULL;
    } else if (current == *head) {
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        *head = (*head)->next;
        prev->next = *head;
        free(current);
    } else if (current->next == *head) {
        prev->next = *head;
        free(current);
    } else {
        prev->next = current->next;
        free(current);
    }
}

// Function to display the circular linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
