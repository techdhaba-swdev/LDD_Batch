#ifndef LINK_LIST_BY_MAYUR
#define LINK_LIST_BY_MAYUR
#include<stdio.h>
#include<stdlib.h>

//thats the declaration of the node
typedef struct Node LinkList;

//init initialias the new link list set the root value NULL;
LinkList* link_list_init();
void append(LinkList* , int);
void delete_node(LinkList*,int );
void print_link_list(LinkList*);




#endif 
