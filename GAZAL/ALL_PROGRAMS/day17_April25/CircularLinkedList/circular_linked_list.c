#include "circular_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
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
        (*head)->next = *head; // Make the new node point to itself
    } else {
        Node *last = *head; // Find the last node in the list
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head; // Set the next pointer of the new node to the current head
        last->next = newNode; // Make the last node point to the new node
        *head = newNode; // Set the new node as the head
    }
}

// Function to display the circular linked list
void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head; // Create a temporary pointer to traverse the list
    do { // Traverse the list
        printf("%d ", temp->data); // Print the data of the current node
        temp = temp->next; // Move to the next node
    } while (temp != head); // Continue until we reach the head node again
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
        (*head)->next = *head; // Make the new node point to itself
    } else {
        Node *last = *head; // Find the last node in the list
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode; // Make the last node point to the new node
        newNode->next = *head; // Make the new node point to the head
    }
}

// Function to delete a node from the list
void deleteNode(Node **head, int key) {
    if (head == NULL || *head == NULL) { // Check if head pointer is NULL or list is empty
        fprintf(stderr, "Invalid parameter: head is NULL or list is empty\n");
        return;
    }
    Node *temp = *head; // Create a temporary pointer to traverse the list
    Node *prev = NULL; // Create a pointer to store the previous node
    while (temp->data != key) { // Find the node to be deleted
        prev = temp; // Store the previous node
        temp = temp->next; // Move to the next node
        if (temp == *head) { // Check if we have traversed the entire list
            printf("Node with data %d not found in the list.\n", key);
            return;
        }
    }
    if (temp == *head) { // Check if the node to be deleted is the head node
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = temp->next; // Update the head pointer
        prev->next = *head; // Update the next pointer of the last node
        free(temp); // Free memory for the deleted node
    } else {
        prev->next = temp->next; // Update the next pointer of the previous node
        free(temp); // Free memory for the deleted node
    }
}

// Function to free the memory allocated to the list
void freeList(Node **head) {
    if (head == NULL || *head == NULL) { // Check if head pointer is NULL or list is empty
        fprintf(stderr, "Invalid parameter: head is NULL or list is empty\n");
        return;
    }
    Node *current = *head; // Create a pointer to traverse the list
    Node *next; // Create a pointer to store the next node
    do { // Traverse the list
        next = current->next; // Store the next node
        free(current); // Free memory for the current node
        current = next; // Move to the next node
    } while (current != *head); // Continue until we reach the head node again
    *head = NULL; // Set the head pointer to NULL
}
