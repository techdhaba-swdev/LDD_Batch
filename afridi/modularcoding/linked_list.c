#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node with the given data
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Check if memory allocation was successful
    if (newNode != NULL) {
        newNode->data = data;   // Assign data to the new node
        newNode->next = NULL;   // Initialize the next pointer to NULL
    }
    return newNode; // Return the pointer to the new node
}

// Function to insert a new node at the beginning of the list
void insertNode(struct Node** head, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNode(data);
    // Check if node creation was successful
    if (newNode != NULL) {
        newNode->next = *head;  // Set the next pointer of the new node to the current head
        *head = newNode;        // Update the head to point to the new node
    }
}

// Function to print the elements of the list
void printList(struct Node* head) {
    struct Node* current = head; // Start from the head of the list
    // Traverse the list and print each element
    while (current != NULL) {
        printf("%d -> ", current->data); // Print the data of the current node
        current = current->next;         // Move to the next node
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the list
void freeList(struct Node* head) {
    struct Node* current = head; // Start from the head of the list
    // Traverse the list and free the memory of each node
    while (current != NULL) {
        struct Node* temp = current; // Store the current node temporarily
        current = current->next;     // Move to the next node
        free(temp);                  // Free the memory of the current node
    }
}
