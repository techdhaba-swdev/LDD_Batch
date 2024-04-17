#include "linklist.h"
#include <stdlib.h>
struct node *createLinkedlist(){
         struct node *head = malloc(sizeof(struct node));
         head->data = 10;
         head->next = NULL;

         struct node *ptr1 = malloc(sizeof(struct node));
         ptr1->data = 20;
         ptr1->next = NULL;

         struct node *ptr2 = malloc(sizeof(struct node));
         ptr2->data = 30;
         ptr2->next = NULL;

         struct node *ptr3 = malloc(sizeof(struct node));
         ptr3->data = 40;
         ptr3->next = NULL;

         struct node *ptr4 = malloc(sizeof(struct node));
         ptr4->data = 50;
         ptr4->next = NULL;

         head->next = ptr1;
         ptr1->next = ptr2;
         ptr2->next = ptr3;
         ptr3->next = ptr4;

         return head;
}
int sum(struct node *head){

         struct node *ptr = head;
         int sum = 0;
         
	 while(ptr !=NULL){
                 sum += ptr->data;
                 ptr = ptr->next;
         }
         return sum;
 }
