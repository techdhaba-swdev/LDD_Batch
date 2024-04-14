#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
void insert_at_start(int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
    ptr->next=head;
    head->prev=ptr;
    /*temp->next=NULL;
    ptr->prev=NULL;*/
    head=ptr;
}
void insert_at_end(int data)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    struct node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
    ptr->next=NULL;
}
void delete_at_start()
{
    printf("\n");
    head=head->next;
    head->prev=NULL;
}
void delete_at_end()
{
    struct node *ptr=head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    printf("\n");
    ptr->next=NULL;
}
void print()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    insert_at_start(20);
    insert_at_start(10);
    insert_at_end(30);
    insert_at_end(40);
    print();
    delete_at_start();
    print();
    delete_at_end();
    print();
    return 0;
}
