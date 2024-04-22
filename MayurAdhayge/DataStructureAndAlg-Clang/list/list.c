// -- coding: utf-8 --
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
   Node* newNode = createNode(data);
    Node* current = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int sum(Node* head) 
{
int sum=0;
    while (head != NULL) {
        sum=sum+head->data;
        head = head->next;
    }
    return sum;
}

void displayList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
  
}

void freeList(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

