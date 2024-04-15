#include<stdio.h>
#include<stdlib.h>
void printLinkList();
void insert(int data);
struct node* addNode(int data);

struct node *root;



struct node{
int data;
struct node* next;
};




struct node* addNode(int data)
{
 struct node* node= (struct node*) malloc(sizeof(struct node));
 node->data= data;
 node->next= NULL;
return node;
}

void printLinkList(){

struct node* temp=root;
while (temp != NULL){
printf("\n%d",temp->data);
temp=temp->next;
}

}

void appendNode(int data)
{

struct node *tmpRoot=root;
while(tmpRoot->next != NULL)
{
 tmpRoot=tmpRoot->next;
}
tmpRoot->next=addNode(data);

}

int main()
{

root=addNode(1);

root->next= addNode(2);
root->next->next= addNode(3);
appendNode(9);

printLinkList();
return 0;

}
