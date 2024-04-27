#include "linked_list.h"  //including the files in linked_list
#include <stdio.h>        // incliding the standerd input/output files
#include <stdlib.h>       // including the standerd library functions

struct node *head = NULL;
// this function is used to print elements of the linkedlist 
void printList() {
    struct node *p = head;
    printf("\n[");
    while(p != NULL) {
        printf(" %d ", p->data); // printing the element until the loop exit
        p = p->next;             // move to the next node
    }
    printf("]");
}
// this function is used to insert the element at begining of the linklist
void insertatbegin(int data) {
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    // allocating the memory dynamically
    lk->data = data;           //assiging the data
    lk->next = head;           //assiging the head value to the next node
    head = lk;                 //updating the head
}
// this function is used to insert the element at end of the linkedlist
void insertatend(int data) {
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = NULL;        // setting the next value to NULL
    if (head == NULL) {     
        head = lk;         // if the list is empty new node is head
        return;
    }
    struct node *last = head;
    while (last->next != NULL)
        last = last->next;     
    last->next = lk;        //inserting the new node at end 
}
// this function is used to create a node at given node in the list
void insertafternode(struct node *list, int data) {
    if (list == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = list->next;
    list->next = lk;
}
// this function is used to delete the node at beggining of the linkedlsit
void deleteatbegin() {
    if (head == NULL) 
        return;
    struct node *temp = head;
    head = head->next;  // assigining the head value to the next node
    free(temp);       // deallocating the temp pointer 
}
// this function is used to delete the node at the end 
void deleteatend() {
    if (head == NULL)
        return;
    if (head->next == NULL) {
        free(head);     
        head = NULL;
        return;
    }
    struct node *last = head;
    while (last->next->next != NULL)
        last = last->next;
    free(last->next);
    last->next = NULL;
}
 // function to delete a node at the specified given key
void deletenode(int key) {
    struct node *temp = head, *prev = NULL;
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
// function to search an element in the linkedlist is present or not
int searchlist(int key) {
    struct node *temp = head;
    while(temp != NULL) {
        if (temp->data == key)
            return 1;       // return 1 if the element is found
        temp = temp->next;
    }
    return 0;              // return 0 if the element not found
}
