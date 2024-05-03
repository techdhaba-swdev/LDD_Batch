#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);

#endif /* GRAPH_H */
