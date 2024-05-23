#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//Define the structure for a node in the linkedlist

struct node{
	int data;
	struct node *next;
};

//Function declaration for linkedlist operations

void printlist();
void insertAtBegin(int data);
void insertAtEnd(int data);
void insertAfterNode(struct node *list,int data);
void deleteAtBegin();
void deleteAtEnd();
void deleteNode(int key);
int searchList(int key);

#endif