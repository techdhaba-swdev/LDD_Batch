#ifndef GRAPH1_H
#define GRAPH1_H

#define MAX_VERTICES 100

extern int adjMatrix[MAX_VERTICES][MAX_VERTICES];

void initializeGraph(int numVertices);

void addEdge(int src,int dest);

void printGraph(int numvertices);

#endif