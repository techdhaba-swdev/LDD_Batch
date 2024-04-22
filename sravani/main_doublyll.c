#include<stdio.h>
#include "doublylinklist.h"
int main(){
        Node *head =NULL;
        for(int i; i<6; i++)
        {
                insert(&head,i);
        }
printf("sum of numbers:%d\n",sumList(head));
return 0;
}
