#include"stack2.h"
static struct stack{
	int data;
	struct stack *next;
};
static struct stack *head=NULL;
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

