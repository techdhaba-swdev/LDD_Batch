#include "ll.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize the linked list
void initLinkedList(struct LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Add a new node with the given value to the linked list
void addNode(struct LinkedList *list, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }
    list->tail = newNode;
    list->size++;
}
