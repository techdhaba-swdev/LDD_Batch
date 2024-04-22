#include<stdio.h>
#include"list.h"
int main(){

struct Node* root=NULL;

insert_node(root,10);

struct Node* tmp=root;
while(tmp!=NULL)
{
	printf("\n%d \n",tmp->data);
	tmp=tmp->next;
}

printf("this is the middel element %d",getmiddelOfLinkList(root));

return 0;
}
