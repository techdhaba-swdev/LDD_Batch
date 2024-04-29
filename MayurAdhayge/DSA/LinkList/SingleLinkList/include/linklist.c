#include "linklist.h"
struct Node{
int data;
struct Node* next;
};

struct Node* link_list_init(){

	//struct Node* root =(struct Node*) malloc(sizeof(struct Node));
	struct Node* root;
	
	return root;
}



void append(struct Node* root ,int data)
{

	struct Node* tmp=root;
	printf("\nroot:-%p tmp:-%p",root,tmp);
	while (tmp!=NULL)
	{
       tmp=tmp->next;
       printf("\t %p",tmp);
	}
	
	tmp=(struct Node*) malloc(sizeof(struct Node));
	tmp->data=data;
	tmp->next=NULL;
	

}

void delete_node(struct Node* root,int target)
{
	struct Node* tmp=root;
	struct Node* prev=root;
	while(tmp->data!=target && tmp->next!=NULL)
        {
		prev=tmp;
		tmp=tmp->next;
	}
	if (tmp->data == target)
	{
		if (tmp==root)
		{
			root=tmp->next;
			free(tmp);
		}
		prev->next=tmp->next;
		free(tmp);


	}
}

void print_link_list(struct Node* root)
        {
	if (root == NULL) return;
	printf("%d",root->data);
	print_link_list(root->next);
	}
