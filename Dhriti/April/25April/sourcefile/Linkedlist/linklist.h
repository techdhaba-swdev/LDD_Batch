#ifndef LINKLIST_H
#define LINKlIST_H


struct node {
   int data;
   struct node *next;
};


extern struct node *head;


void printlist();
void insertatbegin(int data);
void insertatend(int data);
void insertafternode(struct node *list, int data);
void deleteatend();
void deleteatbegin();
void deletenode(int key);
int searchlist(int key);

#endif
