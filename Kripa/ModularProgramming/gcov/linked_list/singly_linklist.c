#include "singly_linklist.h"
#include <stdlib.h>

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to append a new node to the end of the list
void append(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (newNode != NULL) {
        if (*headRef == NULL) {
            *headRef = newNode;
        } else {
            Node* current = *headRef;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

// Function to perform linear search on the linked list
int linearSearch(Node* head, int key) {
    int index = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

