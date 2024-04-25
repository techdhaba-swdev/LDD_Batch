#include "circularlist.h"

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode != NULL) { // Check if memory allocation was successful
        newNode->data = data; // Set the data of the new node
        newNode->next = NULL; // Initialize the next pointer to NULL
    }
    return newNode; // Return the pointer to the new node
}

// Function to insert a new node at the end of the circular list
Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data); // Create a new node
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head; // Return the current head if memory allocation fails
    }
    if (head == NULL) { // If list is empty, new node becomes head
        newNode->next = newNode; // Link the node to itself to make it circular
        return newNode;
    }
    Node* current = head;
    while (current->next != head) { // Traverse to the last node
        current = current->next;
    }
    current->next = newNode; // Link new node at the end
    newNode->next = head; // Make the list circular by pointing the last node to the head
    return head; // Return the head of the list
}

// Function to display the elements of the circular list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data); // Print the data of the current node
        current = current->next; // Move to the next node
    } while (current != head); // Continue until we reach the head again
    printf("(Head)\n");
}

// Function to free the memory allocated for the circular list
void freeList(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    Node* temp;
    do {
        temp = current; // Store the current node in a temporary variable
        current = current->next; // Move to the next node
        free(temp); // Free the memory of the current node
    } while (current != head); // Continue until we reach the head again
}
