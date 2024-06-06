#include"stack2.h"
static struct stack
{
	int data;
	struct stack *next;
};
static struct stack *head=NULL;
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

