#ifndef LINKED_LIST_H  // ensure to complie one time only 
#define LINKED_LIST_H

struct node {        // creating a strcuture with name node
    int data;
    struct node *next;
};

void printlist(); // function prototype of printing the list
void insertatbegin(int data); //function prototype of insert the node at begining
void insertatend(int data); //function prototype of insert at end 
void insertafternode(struct node *list, int data);
void deleteatbegin(); //function prototype for delete at the begining
void deleteatend();   // function prototype of delete at end
void deletenode(int key); // function prototype of delete at a specified node
int searchlist(int key); // function prototype of search an element

#endif
