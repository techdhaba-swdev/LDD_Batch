#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
        int data;
        struct node *next;
};
struct node *createLinkedlist(){ // function to create and return linked list
         struct node *head = malloc(sizeof(struct node)); // dynamical allocate memory which includes data and memory address
							  // of next node

         head->data = 10;  // set head data
         head->next = NULL; // intialize next pointer 

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

	 // link the all nodes together 

         head->next = ptr1; // head hold address of next node(ptr1), head->ptr1
         ptr1->next = ptr2; // ptr1 hold address of next node(ptr2),head->ptr1->ptr2
         ptr2->next = ptr3; 
         ptr3->next = ptr4;

	 return head; // we are return head 
}
void show(struct node *head){ // argument head which holds head address

         struct node *ptr = head; // the pointer*ptr  holds the address of head current address

         while(ptr !=NULL){ // it will run untill the addrees of current node is not null which holds value
		 printf("%d\n",ptr->data); // print the thedata of each node
                
		 ptr = ptr->next; // now ptr updated and pointed to next node 
	 }
}
void freelinkedlist(struct node *head) {
	struct node *temp ;
	while (head !=NULL){
		temp =head;
		head = head->next;
		free(temp);
	}
}

