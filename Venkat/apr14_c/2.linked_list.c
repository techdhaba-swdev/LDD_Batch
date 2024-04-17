#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data ;
    struct node* next;          
} node;
node* insertion(node*head , int data){
    node newnode;
    newnode.data = data;
    newnode.next = head;
    return &newnode;
}
void  traversing(node* head){
    node* temp =head;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
}
int main()
{
    node* head =NULL;
    head  = insertion(head,3);
    head = insertion(head,2);
    head = insertion(head,1);
    traversing(head);
    
}