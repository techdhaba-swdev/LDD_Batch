#include "ll.h"
#include<stdio.h>
#include<stdlib.h>

//global variable to store the head of linkedlist

struct node *head = NULL;

//function to print the element of linkedlist

void printList()
{
	struct node *p = head;
	printf("\n[");
	while (p != NULL)
	{
		printf("%d->", p->data); //print the data of current node
		p = p->next;    //move to next node
	}
	printf("]");
}

//function to insert a node at beginning of linkedlist

void insertAtBegin(int data)
{
	struct node *lk = (struct node*)malloc(sizeof(struct node));  //allocating memory
	lk->data = data;  //set data of new node
	lk->next = head;  //pointing to next node of new node to current node
	head = lk;  //updated head
}	


//function to insert a node to end of linked list

void insertAtEnd(int data)
{
	struct node *lk = (struct node*)malloc(sizeof(struct node));
	lk->data = data; //set data of new node
	lk->next = NULL; //next of new node null
	if(head == NULL)
	{
		head = lk; //if the list is empty new node has head
		return;
	}
	struct node *linkedlist = head;
	while(linkedlist->next != NULL)
		linkedlist = linkedlist->next;
	linkedlist->next = lk;  //insert new node at end
}	



//function to create a node after a given node in list


void insertAfterNode(struct node *list, int data)
{
	struct node *lk = (struct node*)malloc(sizeof(struct node));
	lk->data = data;
	lk->next = list->next; //pointing to next new node to next of given node
	list->next = lk;
}


//function to delete the first node from linked list


void deleteAtBegin()
{
	head = head->next; //move head to next node
}


//function to delete last node from linked list


void deleteAtEnd()
{
	struct node *linkedlist = head;
	while(linkedlist->next->next != NULL)
		linkedlist = linkedlist->next;
	linkedlist->next = NULL; //set next to second last node to null
}


//function to delete the node with a given key


void deleteNode(int key)
{
	struct node *temp = head, *prev; 
	if(temp != NULL && temp->data == key) //check if the key is first node
	{
		
		head = temp->next; // move head to next node
		free(temp);
		return;
	}
	while(temp != NULL && temp->data != key) //finding node with key
	{
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL)return; //if key is not found
	prev->next = temp->next; //skip the node with key
	free(temp);
}



//function to search a key in list



int searchList(int key)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		if(temp->data == key)
		{
			return 1;  //element found
		}
		temp = temp->next;
	}
	return 0;  //element not found
}

