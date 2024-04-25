#include<stdio.h>
#include<stdlib.h>
struct node //created a structure node 
{
    int data; //declaerd a variable which stores an integer
    struct node *next; //created a pointer which points to same structure
};
struct node *head=NULL; //initilized head with NULL
void enqueue(int data) //API of enqueue 
{
    struct node*ptr=malloc(sizeof(struct node)); //allocated space to data using dynamicmemory allocation using malloc and named ptr
    ptr->data=data; //assigned data to ptr
    if(head==NULL) //condition works only once i.e for first node
    {
        head=ptr; //making ptr head for first node
        return;
    }
    ptr->next=head; //from second enqueue the conditon fails and ptr is updated
    head=ptr; //ptr is updated with head for every enqueue
}
int dequeue() //API of dequeue
{
    printf("\n");
    int p=head->data;
    head=head->next;
    return p; //returning the front elemnet as queue is FIFO(first in first out)
}
void print() //API of print
{
    struct node *ptr=head; //reinitializing head as ptr for traversing
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data); //loop runs untill last node as last node stores NULL as address in next and prints each element
        ptr=ptr->next; //updating ptr with next node address everytime
    }
}
