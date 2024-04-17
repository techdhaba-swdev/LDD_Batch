// linklist.c

#include <stdio.h>
#include <stdlib.h>
#include "linklist2.h"

void insert(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int sumList(Node *head) {
    int sum = 0;
    Node *current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}
