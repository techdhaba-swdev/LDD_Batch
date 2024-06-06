#include<stdio.h>
#include<stdlib.h>
#include "lkadd.h"


void insertnode(struct Node** head, int new_data){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

        new_node->data = new_data;
        new_node->next = NULL; //next pointer of new node is set to null

        if (*head == NULL){ //null means the head of the list is empty
                *head = new_node; // make the new node head
                return;
        }
        struct Node* last = *head; // create a temp ptr last
        while(last-> next != NULL)
                last = last->next;
        last->next = new_node; //appends the new node tothe end of the list making it the new last node
}
