#include "clink.h"      // Include the header file that contains the structure definition and function prototypes
#include <stdio.h>      // Include standard I/O functions
#include <stdlib.h>     // Include standard library functions for memory allocation

// Create a new node with the given data
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed\n");  // Print an error message
        exit(EXIT_FAILURE);  // Exit the program
    }
    // Assign the data to the new node
    newNode->data = data;
    // Set the next pointer to NULL (not yet connected to any other node)
    newNode->next = NULL;
    // Return a pointer to the new node
    return newNode;
}

// Add a new node with the given data to the end of the list
void addNode(struct Node** head, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNode(data);
    // Check if the list is empty
    if (*head == NULL) {
        // If so, make the new node the head of the list
        *head = newNode;
        // Point the new node to itself to create a circular list
        newNode->next = *head;
    } else {
        // If the list is not empty, traverse to the last node
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        // Connect the last node to the new node
        temp->next = newNode;
        // Point the new node back to the head to maintain circularity
        newNode->next = *head;
    }
}

// Calculate the sum of all node values in the list
int calculateSum(struct Node* head) {
    // Initialize the sum to 0
    int sum = 0;
    // Check if the list is empty
    if (head == NULL) {
        return sum;
    }
    // Create a pointer to traverse the list
    struct Node* current = head;
    // Traverse the list and add each node's data to the sum
    do {
        sum += current->data;
        current = current->next;
    } while (current != head);  // Continue until we reach the head again
    // Return the sum
    return sum;
}

// Print all node values in the list
void printList(struct Node* head) {
    // Check if the list is empty
    if (head == NULL) {
        return;
    }
    // Create a pointer to traverse the list
    struct Node* current = head;
    // Traverse the list and print each node's data
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);  // Continue until we reach the head again
    // Print a newline character to end the line
    printf("\n");
}

// Free all memory allocated for the list
void freeList(struct Node** head) {
    // Check if the list is empty
    if (*head == NULL) {
        return;
    }
    // Create a pointer to traverse the list
    struct Node* current = *head;
    // Create a temporary pointer to hold the next node to be freed
    struct Node* temp;
    // Traverse the list and free each node
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != *head);  // Continue until we reach the head again
    // Set the head pointer to NULL to indicate that the list is empty
    *head = NULL;
}
