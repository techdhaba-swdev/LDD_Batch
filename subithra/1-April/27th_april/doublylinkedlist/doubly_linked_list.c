#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL) { // Check if memory allocation failed
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data; // Assign data to the new node
    newNode->prev = NULL; // Set previous pointer to NULL
    newNode->next = NULL; // Set next pointer to NULL
    return newNode; // Return the new node
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
    if (head == NULL) { // Check if head pointer is NULL
        fprintf(stderr, "Invalid parameter: head is NULL\n");
        return;
    }
    Node *newNode = createNode(data); // Create a new node
    if (*head == NULL) { // Check if the list is empty
        *head = newNode; // Set the new node as the head
    } else {
        newNode->next = *head; // Set the next pointer of the new node to the current head
        (*head)->prev = newNode; // Set the previous pointer of the current head to the new node
        *head = newNode; // Set the new node as the head
    }
}

// Function to display the doubly linked list
void displayList(Node *head) {
    printf("Doubly Linked List: ");
    while (head != NULL) { // Traverse the list
        printf("%d ", head->data); // Print the data of the current node
        head = head->next; // Move to the next node
    }
    printf("\n");
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data) {
    if (head == NULL) { // Check if head pointer is NULL
        fprintf(stderr, "Invalid parameter: head is NULL\n");
        return;
    }
    Node *newNode = createNode(data); // Create a new node
    if (*head == NULL) { // Check if the list is empty
        *head = newNode; // Set the new node as the head
    } else {
        Node *temp = *head; // Create a temporary pointer to traverse the list
        while (temp->next != NULL) { // Traverse the list until the last node
            temp = temp->next; // Move to the next node
        }
        temp->next = newNode; // Set the next pointer of the last node to the new node
        newNode->prev = temp; // Set the previous pointer of the new node to the last node
    }
}

// Function to delete a node from the list
void deleteNode(Node **head, int key) {
    if (head == NULL || *head == NULL) { // Check if head pointer is NULL or list is empty
        fprintf(stderr, "Invalid parameter: head is NULL or list is empty\n");
        return;
    }
    Node *temp = *head; // Create a temporary pointer to traverse the list
    if (temp->data == key) { // Check if the node to be deleted is the head node
        *head = temp->next; // Update the head pointer
        if (*head != NULL) { // Check if the new head exists
            (*head)->prev = NULL; // Set the previous pointer of the new head to NULL
        }
        free(temp); // Free memory for the deleted node
        return;
    }
    while (temp != NULL && temp->data != key) { // Traverse the list to find the node to be deleted
        temp = temp->next; // Move to the next node
    }
    if (temp == NULL) { // Check if the node with the given key is not found
        printf("Node with data %d not found in the list.\n", key);
        return;
    }
    if (temp->next != NULL) { // Check if the node to be deleted is not the last node
        temp->next->prev = temp->prev; // Update the previous pointer of the next node
    }
    if (temp->prev != NULL) { // Check if the node to be deleted is not the first node
        temp->prev->next = temp->next; // Update the next pointer of the previous node
    }
    free(temp); // Free memory for the deleted node
}

// Function to free the memory allocated to the list
void freeList(Node **head) {
    if (head == NULL || *head == NULL) { // Check if head pointer is NULL or list is empty
        fprintf(stderr, "Invalid parameter: head is NULL or list is empty\n");
        return;
    }
    Node *temp = *head; // Create a temporary pointer to traverse the list
    Node *next; // Create a pointer to store the next node
    while (temp != NULL) { // Traverse the list
        next = temp->next; // Store the next node
        free(temp); // Free memory for the current node
        temp = next; // Move to the next node
    }
    *head = NULL; // Set the head pointer to NULL
}
