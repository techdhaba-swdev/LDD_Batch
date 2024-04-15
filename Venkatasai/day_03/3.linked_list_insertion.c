#include <stdio.h>
#include <stdlib.h>
struct node {
    int data ;
    struct node *next;
};

struct node *insertion(struct node*head,int value){
struct node *ptr = malloc(sizeof(struct node));
ptr->data = value;
ptr->next =NULL;  

ptr->next = head ;
head = ptr ;
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
    
    int data = 1 ;
    head = insertion(head,data);
    ptr = head ;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
     }                   
}
