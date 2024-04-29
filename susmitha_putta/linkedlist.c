#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
//global variable to store the head of the linkedlist
struct node *head = NULL;
//function to print the elements of the linkedlist
void printlist() {
    struct node *p = head;
    printf("\n[");
    while (p != NULL) {
        printf(" %d-> ", p->data);//print the data of the current node
        p = p->next;//it will move to next node
    }
    printf("]");
}
//function to insert a node at the beginning of the linkedlist
void insertAtBegin(int data) {
    struct node *lk = (struct node*)malloc(sizeof(struct node));//allocation
    lk->data = data;//set the data of the new node
    lk->next = head;// pointing to  the next new  node tp the current head
    head = lk;//updated head
}
//function to insert a node at the end of the linkedlist
void insertAtEnd(int data) {
    struct node  *lk = (struct node*)malloc(sizeof(struct node));
    lk->data = data;//set the data of the new node
    lk->next = NULL;//pointing to the next of new node to the current head
    if (head == NULL) 
		     {
        head = lk;//if the list is empty it will take head as a new node
        return;
    }
    struct node *linkedlist = head;
    while (linkedlist->next != NULL)
        linkedlist = linkedlist->next;
    linkedlist->next = lk;//insert new node at end
}
//function to create a node after a given node in the list
void insertAfterNode(struct node *list, int data) {
    struct node *lk = (struct node*)malloc(sizeof(struct node));
    lk->data = data;
    lk->next = list->next;//pointing to the next of new node
    list->next = lk;
}
//function to delete the first node from the list
void deleteAtBegin() {
    head = head->next;
}
//function to create a node after a givien node in the list
void deleteAtEnd() {
    struct node *linkedlist = head;
    while (linkedlist->next->next != NULL)
        linkedlist = linkedlist->next;
    linkedlist->next = NULL;
}
//function to delete a node with a given key from the list
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
    if (temp == NULL)
	    return;
    prev->next = temp->next;
    free(temp);
}
//function to search a key
int searchList(int key) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;//elements not found
}

