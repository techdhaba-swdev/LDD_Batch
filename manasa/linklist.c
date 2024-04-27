#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>


//global variable to store the head of the linklist

struct node *head = NULL;

//function to print the element of the linkedlist

void printList() {
    struct node *p = head;
    printf("\n[");
    while (p != NULL) {
        printf(" %d ", p->data);//print the the data of the element node
        p = p->next;//move to the next node
    }
    printf("]");
}

//function to insert a node at the beginning of the ll

void insertAtBegin(int data) {
    struct node *lk = (struct node*)malloc(sizeof(struct node));//allocating memory
    lk->data = data;//set the data of the new node
    lk->next = head;//pointing to the next of the new node to current head
    head = lk;//updated head
}

//function to insert the node at the end of ll
void insertAtEnd(int data) {
    struct node *lk = (struct node*)malloc(sizeof(struct node));
    lk->data = data;//set the data of the new node
    lk->next = NULL;//next ..new node is null
    if (head == NULL) {
        head = lk;//if the list is empty new node will be head
        return;
    }
    struct node *linkedlist = head;
    while (linkedlist->next != NULL)
        linkedlist = linkedlist->next;
    linkedlist->next = lk;//insert new node at end
}

//func to create a node after a given node int l
void insertAfterNode(struct node *list, int data) {
    struct node *lk = (struct node*)malloc(sizeof(struct node));
    lk->data = data;
    lk->next = list->next;//pointing to the new node to next of the given node
    list->next = lk;
}

//func to delete the first node from l
void deleteAtBegin() {
    head = head->next;
}

//func to del the last node from th ll
void deleteAtEnd() {
    struct node *linkedlist = head;
    while (linkedlist->next->next != NULL)
        linkedlist = linkedlist->next;
    linkedlist->next = NULL;//set the next node to sec last node to null
}

//func to del the node with a given key from the l
void deleteNode(int key) {
    struct node *temp = head, *prev;
    if (temp != NULL && temp->data == key) { //to check the key is in 1st node
        head = temp->next;//move head to nxt node
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) { //find node with key
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) //if key not found
	    return;
    prev->next = temp->next; // skip node with key
    free(temp);
}

 //func to search the key in the l
int searchList(int key) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1;//element found
        }
        temp = temp->next;
    }
    return 0;//elem not found
}
