#include "linklist.h"
#include <stdlib.h>

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the end of the linked list
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *headRef;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to calculate the sum of all nodes in the linked list
int sumNodes(struct Node* head) {
    int sum = 0;
    struct Node* current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}
