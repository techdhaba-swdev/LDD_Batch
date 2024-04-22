#include<stdio.h>
#include<stdlib.h>
#include"circular.h"


struct Node
{
        int value;
        struct Node* next;
};

struct Node* create_node(int value)
{
        struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
        new_node->value=value;
        new_node->next=NULL;
        return new_node;
}
void insert_node(struct Node **head,int value)
{
        struct Node* new_node=create_node(value);
        if(*head==NULL)
        {
                *head=new_node;
                new_node->next=*head;
        }
        else
        {
                struct Node* tail=*head;
                while(tail->next!=*head)
                {
                        tail=tail->next;
                }
                tail->next=new_node;
                new_node->next=*head;
        }
}

void print_list(struct Node* head)
{
        if(head==NULL)
        {
                printf("list is empty.\n");
                return;
        }

        struct Node* current =head;
        do
        {
                printf("%d",current->value);
                current=current->next;
        }while(current!=head);

        printf("\n");
}


