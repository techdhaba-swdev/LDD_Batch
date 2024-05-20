#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for new node.\n");
        exit(EXIT_FAILURE);
    }
    
    // Assign data to the new node
    new_node->data = new_data;
    
    // Make the next of new node as head
    new_node->next = (*head_ref);
    
    // Move the head to point to the new node
    (*head_ref) = new_node;
}

void printList(const struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
