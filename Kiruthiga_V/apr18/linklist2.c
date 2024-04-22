#include<stdio.h>
#include<stdlib.h>
#include "linklist2.h"
struct Node* createNode(int data){
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if(newNode == NULL){
printf("memory allocation failed!\n");
exit(EXIT_FAILURE);
}
newNode->data = data;
newNode->next = NULL;
return newNode;
}
void insertAtBeginning(struct Node** headRef, int data){
struct Node* newNode = createNode(data);
if(*headRef == NULL){
*headRef = newNode;
newNode->next = *headRef;
}
else
{
struct Node* temp = *headRef;
while(temp->next != *headRef){
temp = temp->next;
}
temp->next = newNode;
newNode->next = *headRef;
*headRef = newNode;
}
}
void insertAtEnd(struct Node** headRef, int data){
struct Node* newNode = createNode(data);
if(*headRef == NULL){
*headRef = newNode;
newNode->next = *headRef;
}
else{
struct Node* temp = *headRef;
while(temp->next != *headRef){
temp = temp->next;
}
temp->next = newNode;
newNode->next = *headRef;
}
}
void displayList(struct Node* head){
if(head == NULL){
printf("list is empty.\n");
return;
}
struct Node* temp = head;
do{
printf("%d",temp->data);
temp = temp->next;
}while(temp != head);
printf("\n");
}


