#include "linklist.h" // Include the header file for function prototypes
#include<stdlib.h>
#include<stdio.h>
// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode != NULL) { // Check if memory allocation was successful
        newNode->data = data; // Set the data of the new node
        newNode->next = NULL; // Initialize the next pointer to NULL
    }
    return newNode; // Return the pointer to the new node
}

// Function to insert a new node at the end of the list
Node* insertNode(Node* head, int data) {
    if (head == NULL) { // If list is empty, create a new node and return it
        return createNode(data);
    }
    Node* current = head;
    while (current->next != NULL) { // Traverse to the end of the list
        current = current->next;
    }
    current->next = createNode(data); // Create a new node and link it at the end
    return head; // Return the head of the list
}

// Function to display the elements of the list
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) { // Traverse the list until the end
        printf("%d -> ", current->data); // Print the data of the current node
        current = current->next; // Move to the next node
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the list
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) { // Traverse the list
        Node* temp = current; // Store the current node in a temporary variable
        current = current->next; // Move to the next node
        free(temp); // Free the memory of the current node
    }
}
