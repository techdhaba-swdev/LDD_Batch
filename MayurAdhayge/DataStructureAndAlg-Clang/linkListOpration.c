#include<stdio.h>
#include<stdlib.h>
void printLinkList();
void insert(int data);
<<<<<<< HEAD
=======
void deleteNode(int data);
>>>>>>> main
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

<<<<<<< HEAD
=======
void deleteNode(int data)
{

struct node *tmpRoot=root;
struct node *tmpDelete;

while(1)
{
 tmpDelete=tmpRoot;
 tmpRoot=tmpRoot->next;
if (tmpRoot->data == data){
tmpDelete->next=tmpRoot->next;

free(tmpRoot);
break;
}
 
}
if (tmpRoot->data == data){
printf("deletion done");
}
else
{
printf("data not found");

}
}

>>>>>>> main
int main()
{

root=addNode(1);

root->next= addNode(2);
root->next->next= addNode(3);
appendNode(9);
<<<<<<< HEAD
=======
printLinkList();
deleteNode(2);
>>>>>>> main

printLinkList();
return 0;

}
