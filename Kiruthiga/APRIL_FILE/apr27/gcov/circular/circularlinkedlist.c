#include <stdio.h>
#include <stdlib.h>
#include "circularlinkedlist.h"
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = *head_ref;

    // If the linked list is not NULL, then set the next of the last node
    if (*head_ref != NULL) {
        while (last->next != *head_ref)
            last = last->next;
        last->next = new_node;
    } else {
        new_node->next = new_node; // For the first node
    }

    *head_ref = new_node;
}

// Function to traverse and print the circular linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

