#ifndef GRAPH_A
#define GRAPH_A

#include <stdio.h>
#include<time.h>

#define MAX_VERTICES 100
 
//int adjMatrix[MAX_VERTICES][MAX_VERTICES];


// Function to initialize the graph with no edges
void initializeGraph(int numVertices);
 
// Function to add a directed edge from src to dest
void addEdge(int src, int dest);

// Function to print the adjacency matrix representation of the graph
void printGraph(int numVertices); 
 
 
#endif
