#include "doublelink.h"

// Create an empty doubly linked list
DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));  // Allocate memory for the list
    if (list == NULL) {  // Check if memory allocation was successful
        perror("Error allocating memory for linked list");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;  // Initialize head to NULL
    list->tail = NULL;  // Initialize tail to NULL
    return list;        // Return the list
}

// Create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory for the new node
    if (newNode == NULL) {  // Check if memory allocation was successful
        perror("Error allocating memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;  // Set the data of the new node
    newNode->prev = NULL;   // Initialize prev pointer to NULL
    newNode->next = NULL;   // Initialize next pointer to NULL
    return newNode;         // Return the new node
}

// Add a node to the end of the list
void addNodeAtEnd(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);  // Create a new node with the given data
    if (list->head == NULL) {          // Check if the list is empty
        list->head = newNode;          // If empty, set the new node as the head
        list->tail = newNode;          // Also set the new node as the tail
    } else {
        newNode->prev = list->tail;    // Set the prev pointer of the new node to the current tail
        list->tail->next = newNode;    // Set the next pointer of the current tail to the new node
        list->tail = newNode;          // Update the tail to the new node
    }
}

// Print the elements of the list
void printList(DoublyLinkedList* list) {
    Node* current = list->head;  // Start at the head of the list
    while (current != NULL) {    // Traverse the list
        printf("%d ", current->data);  // Print the data of the current node
        current = current->next;      // Move to the next node
    }
    printf("\n");  // Print a newline at the end
}

// Calculate the sum of all elements in the list
int sumList(DoublyLinkedList* list) {
    int sum = 0;                // Initialize sum to zero
    Node* current = list->head; // Start at the head of the list
    while (current != NULL) {   // Traverse the list
        sum += current->data;    // Add the data of the current node to the sum
        current = current->next; // Move to the next node
    }
    return sum;                 // Return the sum
}
