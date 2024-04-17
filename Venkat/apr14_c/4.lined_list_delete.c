#include <stdio.h>
#include <stdlib.h>
struct node {
    int data ;
    struct node *next;
};
struct node* delete(struct node *head)
{
    if(head == NULL){
        printf("list is empty");
    }
    else {
        struct node *temp = head;
        head = head->next;
        free(temp);
        temp =NULL;
    }
    return head;
}

int main() 
{
struct node *head = malloc(sizeof(struct node));
    head->data = 10;       
    head->next = NULL;
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 20;
    ptr->next = NULL;
    head->next =ptr;
    
    head = delete(head);
    ptr= head;
    while(ptr!=NULL){
        printf("%d",ptr->data);

    }
}