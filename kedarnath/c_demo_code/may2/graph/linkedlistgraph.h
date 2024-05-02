#ifndef GRAPH_L
#define GRAPH_L

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct node;
struct Graph;

void printGraph(struct Graph*);
void addEdge(struct Graph*, int, int);
struct Graph* createGraph(int);
struct Node* createNode(int);


#endif
