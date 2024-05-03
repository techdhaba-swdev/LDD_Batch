#ifndef GRAPH_H
#define GRAPH_H

// Structure to represent the graph
typedef struct {
    int **adjMatrix;
    int numVertices;
} Graph;

// Function prototypes

void initializeGraph(Graph *graph);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);
void destroyGraph(Graph *graph);

#endif
