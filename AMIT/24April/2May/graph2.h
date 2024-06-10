#ifndef GRAPH
#define GRAPH

#define MAX_VERTICES 100
int adjMatrix[MAX_VERTICES][MAX_VERTICES];

void initializeGraph(int numVertices);
void addEdge(int src, int dest);
void printGraph(int numVertices);

#endif
