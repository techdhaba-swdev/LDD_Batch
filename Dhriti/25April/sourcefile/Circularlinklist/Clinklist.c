#include "Clinklist.h"
#include <stdio.h>

// Function to append a new node with the given data to the end of the list
void append(struct CircularLinkedList* list, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNode(data);
    // Check if memory allocation was successful
    if (newNode != NULL) {
        // If the list is empty
        if (list->head == NULL) {
            list->head = newNode;
            newNode->next = list->head;
        } else {
            // Traverse to the end of the list
            struct Node* temp = list->head;
            while (temp->next != list->head) {
                temp = temp->next;
            }
            // Insert the new node at the end of the list
            temp->next = newNode;
            newNode->next = list->head;
        }
    } else {
        printf("Memory allocation failed. Node could not be created.\n");
    }
}

// Function to display the elements of the circular linked list
void display(struct CircularLinkedList* list) {
    // If the list is empty
    if (list->head == NULL) {
        printf("List is empty\n");
    } else {
        // Traverse the list and print each element
        struct Node* temp = list->head;
        printf("Circular Linked List: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != list->head);
        printf("\n");
    }
}

