#include<stdio.h>
#include<stdlib.h>
#include "lkadd.h"



void printlist(struct Node* node){ //traveses and prints the entire ll starting fromthe given node
        while (node != NULL){
                printf("%d", node->data);
                node = node->next;
        }
      printf("\n");
}

