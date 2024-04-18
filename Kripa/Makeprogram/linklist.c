#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

void append(struct Node** head_ref, int new_data){
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
struct Node* last = *head_ref;

new_node->data=new_data;
new_node->next=NULL;

if(*head_ref ==NULL)
   *head_ref = new_node;
return;
}

while(last->next != NULL)
	last=last->next;
last->next=new_node;
}

int linklist(struct Node* head){
   int sum = 0;
   struct Node* current =head;
   while(current !=NULL){
	   sum+= current->data;
	   current=current->next;
}
return sum;

} 
