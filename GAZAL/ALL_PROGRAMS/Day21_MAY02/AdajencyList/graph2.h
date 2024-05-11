#ifndef LINKLIST_GRAPH_H
#define LINKLIST_GRAPH_H

// Function prototypes
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void freeGraph(struct Graph* graph);

#endif
