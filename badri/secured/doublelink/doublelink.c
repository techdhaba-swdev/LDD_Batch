#include "doublelink.h"
#include <stdio.h> // Include standard input/output library

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data); // Create a new node
    if (*head == NULL) { // Check if the list is empty
        *head = newNode; // Set the new node as the head
    } else {
        newNode->next = *head; // Link new node to the current head
        (*head)->prev = newNode; // Link current head to the new node
        *head = newNode; // Update the head to the new node
    }
}

// Function to display the doubly linked list
void displayList(Node* head) {
    while (head != NULL) { // Traverse the list until NULL is reached
        printf("%d ", head->data); // Print data of the current node
        head = head->next; // Move to the next node
    }
    printf("\n");
}
