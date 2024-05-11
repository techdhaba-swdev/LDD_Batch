#ifndef GRAPH_H
#define GRAPH_H
// function prototypes

// Function to initialize the graph with no edges
void initializeGraph(int numVertices);

// Function to add a directed edge from src to dest
void addEdge(int src, int dest);

// Function to print the adjacency matrix representation of the graph
void printGraph(int numVertices);

#endif /* GRAPH_H */