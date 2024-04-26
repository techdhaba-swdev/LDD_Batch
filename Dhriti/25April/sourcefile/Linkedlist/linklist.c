#include<stdio.h>
#include<stdlib.h>

#include "linklist.h"

struct node *head = NULL;

// display the list
void printList(){
   struct node *p = head;
   printf("\n[");

   //Traverse the list and print each element
   while(p != NULL) {
      printf(" %d ",p->data);
      p = p->next;
   }
   printf("]");
}

//insertion at the beginning
void insertatbegin(int data){

   //create a link
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   if(lk == NULL) {
           printf("Error.\n");
           return;
   }
   //Initialize the new node with the data
   lk->data = data;

   // point it to old first node
   lk->next = head;

   //point first to new first node
   head = lk;
}
void insertatend(int data){

   //create a link
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   if(lk == NULL) {
	   printf("Error.\n");
	   return;
   }

   lk->data = data;
   //Traverse to the end of the list
   struct node *linkedlist = head;

   // point it to old first node
   while(linkedlist->next != NULL)
      linkedlist = linkedlist->next;

   //point first to new first node
   linkedlist->next = lk;
}

//Insert new node with the given data
void insertafternode(struct node *list, int data){
   struct node *lk = (struct node*) malloc(sizeof(struct node));
   
   //check if the node is valid
   if(list == NULL) {
           printf("Error.\n");
           return;
   }
   
   //Initialize new node with the data
   lk->data = data;
   lk->next = list->next;

   list->next = lk;
}


void deleteatbegin(){
   head = head->next;
}
void deleteatend(){
   struct node *linkedlist = head;
   while (linkedlist->next->next != NULL)
      linkedlist = linkedlist->next;
   linkedlist->next = NULL;
}
void deletenode(int key){
   struct node *temp = head, *prev;
   if (temp != NULL && temp->data == key) {
      head = temp->next;
      return;
   }

   // Find the key to be deleted
   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
   }

   // If the key is not present
   if (temp == NULL) return;

   // Remove the node
   prev->next = temp->next;
   
   //Deallocate the memorry. 
   free(temp);  
}
int searchlist(int key){
   struct node *temp = head;
   while(temp != NULL) {
      if (temp->data == key) {
         return 1;
      }
      temp=temp->next;
   }
   return 0;
}
