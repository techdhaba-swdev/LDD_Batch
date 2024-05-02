#ifndef GRAPH_STRUCT_H_
#define GRAPH_STRUCT_H_
#include<stdio.h>
#include<stdlib.h>
struct Node *createNode(int vertex);
struct Graph *createGraph(int numVertices);
void addEdge(struct Graph *graph,int src,int dest);
void printGraph(struct Graph *graph);
#endif

