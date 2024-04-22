#include<stdio.h>
#include<stdlib.h>
#include "doublylinklist.h"
void insert(Node **head, int a){
        Node *newNode = (Node*)malloc(sizeof(Node));
        if(newNode==NULL){
                printf("failed \n");
        }
        newNode->a=a;
	newNode->prev=NULL;
        newNode->next=*head;
	if(*head != NULL){
	(*head)->prev = newNode;
}
        *head=newNode;
}
int   sumList(Node *head){
        int sum=0;
        Node *current=head;
        while(current!=NULL){
                sum +=current->a;
                current=current->next;
        }
        return sum;
}

