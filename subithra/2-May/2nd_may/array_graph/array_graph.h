// array_graph.h

#ifndef ARRAY_GRAPH_H
#define ARRAY_GRAPH_H

#include <stdbool.h>

#define MAX_VERTICES 100

// Function prototypes
bool initializeGraph(int numVertices);
bool addEdge(int src, int dest, int numVertices);
void printGraph(int numVertices);

#endif  // ARRAY_GRAPH_H
