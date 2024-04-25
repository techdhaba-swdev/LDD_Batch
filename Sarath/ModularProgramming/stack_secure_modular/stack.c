#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
struct stack
{
        int data;
        struct stack *next;
};
struct stack *head=NULL;
void push(int data)
{
        struct stack *ptr=malloc(sizeof(struct stack));
        struct stack *temp=head;
        ptr->data=data;
        if(head==NULL)
        {
                head=ptr;
                return;
        }
        while(temp->next!=NULL)
        {
                temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
}
int pop()
{
        struct stack *ptr=head;
        while(ptr->next!=NULL && ptr->next->next!=NULL)
        {
                ptr=ptr->next;
        }
        printf("\n");
        if(ptr->next==NULL)
        {
                head=NULL;
                return ptr->data;
        }
        if(ptr->next->next==NULL)
        {
                int p=ptr->next->data;
                ptr->next=NULL;
                return p;
        }
}
void print()
{
        struct stack *ptr=head;
        while(ptr!=NULL)
        {
                printf("%d ",ptr->data);
                ptr=ptr->next;
        }
}

