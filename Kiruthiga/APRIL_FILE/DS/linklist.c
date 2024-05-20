#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"
void insert(Node **head, int a){
Node *newNode = (Node*)malloc(sizeof(Node));
if(newNode==NULL){
printf("failed \n");
return 1;
}
newNode->a=a;
newNode->next=*head;
*head=newNode;
}
int sumList(Node *head){
int sum=0;
Node *current=head;
while(current!=NULL){
sum +=current->a;
current=current->next;
}
return sum;
}
