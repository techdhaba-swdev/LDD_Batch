#include<stdio.h>
#include<stdlib.h>
#include"circular.h"

struct Node
{
        int value;
        struct Node* next;
};


int main()
{
        struct Node* head=NULL;
        int num_node;
        printf("Enter the number of nodes:");
        scanf("%d",&num_node);

        for(int i=0;i<num_node;++i)
        {
                int value;
                printf("Enter the value for the node %d: ",i+1);
                scanf("%d",&value);
                insert_node(&head,value);
        }

        printf("Circular linked list: ");
        print_list(head);

        struct Node* current=head;
        while(current!=NULL)
        {
                struct Node* temp=current;
                current=current->next;
                free(temp);
        }
        return 0;
}


