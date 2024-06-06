#include"stack2.h"
static struct stack{
	int data;
	struct stack *next;
};
static struct stack *head=NULL;
void print()
{
        struct stack *ptr=head;
        while(ptr!=NULL)
        {
                printf("%d ",ptr->data);
                ptr=ptr->next;
        }
}

