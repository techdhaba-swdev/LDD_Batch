#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

//Global variable to store the head of the linkedlist

struct node *head=NULL;

//function to print the eelemet of the linkedlist

void printlist(){
	struct node *p=head;
	printf("\n[");
	while(p != NULL) {
		printf("%d",p->data);//print the data of current node
		p = p->next;//move to the next node
	}
	printf("]");
}
//function to insert a node at the beggining of the linkedlist

void insertAtBegin(int data){
	struct node *lk=(struct node*)malloc(sizeof(struct node));//allocating memory
	lk->data = data; //set the data of the new node
	lk->next = head;//pointing to the next of new node to the current head
	head = lk;//upadate head
}

//function to insert a node at the end of the linked list 

void insertAtEnd(int data){
	struct node *lk=(struct node*)malloc(sizeof(struct node));
        lk->data = data;//set the data of the  new node
	lk->next = NULL;//next of new node null 
	if(head == NULL){
		head = lk;//if the list is empty new node as head
		return;
	}
	struct node *linkedlist = head;
	while(linkedlist->next != NULL)
		linkedlist = linkedlist->next;
	linkedlist->next = lk;//insert new node at end
}

//function to create a node after a given node in the list

void insertAfterNode(struct node *list,int data){
	struct node *lk=(struct node*)malloc(sizeof(struct node));
	lk->data = data;
	lk->next = list->next;//ponting to the next of new node to the next of the given node
	list->next = lk;
}

//function to delete the first node from linked list

void deleteAtBegin(){
	head = head->next;//move head to next node
}

//function to delete the last node ffrom the linkedlist

void deleteAtEnd(){
	struct node *linkedlist = head;
	while(linkedlist->next->next != NULL)
		linkedlist = linkedlist->next;
	linkedlist->next = NULL;//set the next of the second last node to null

}

//function to delete a node with a given key from the list

void deleteNode(int key){
	struct node *temp = head, *prev;
	if(temp != NULL && temp->data == key){ //check if the key is in first node
		head = temp->next;//mv head to next node
		free(temp);
		return;
	}
	while(temp != NULL && temp->data != key){ //finding node with key
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) //if key is not found
		return;
	prev->next = temp->next;//skip the node with key
	free(temp);
}

//function to search a key in the list


int searchList(int key){
	struct node *temp = head;
	while (temp != NULL){
		if (temp->data == key){
			return 1; //element found
		}
		temp = temp->next;
	}
	return 0; //element not found
}
	
