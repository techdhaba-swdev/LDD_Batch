#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

struct node *head = NULL;

void printList() {
    struct node *p = head;
    printf("\n[");
    while (p != NULL) {
        printf(" %d ", p->data);
        p = p->next;
    }
    printf("]");
}

void insertAtBegin(int data) {
    struct node *lk = (struct node*)malloc(sizeof(struct node));
    lk->data = data;
    lk->next = head;
    head = lk;
}

void insertAtEnd(int data) {
    struct node *lk = (struct node*)malloc(sizeof(struct node));
    lk->data = data;
    lk->next = NULL;
    if (head == NULL) {
        head = lk;
        return;
    }
    struct node *linkedlist = head;
    while (linkedlist->next != NULL)
        linkedlist = linkedlist->next;
    linkedlist->next = lk;
}

void deleteAtBegin() {
    head = head->next;
}

void deleteAtEnd() {
    struct node *linkedlist = head;
    while (linkedlist->next->next != NULL)
        linkedlist = linkedlist->next;
    linkedlist->next = NULL;
}

void deleteNode(int key) {
    struct node *temp = head, *prev;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

int searchList(int key) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
