#include <stdio.h>//header file for standard input-output file
#include "graph1.h"

#define MAX_VERTICES 100//macro define for MAX_VERTICES
 
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
 
// Function to initialize the graph with no edges
void initializeGraph(int numVertices) {//which takes the no. of vertices in the graph and initializes matrix to zero
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      adjMatrix[i][j] = 0;
    }
  }
}
 
// Function to add a directed edge from src to dest
void addEdge(int src, int dest) {//which takes 2 arguments src and dest 
  adjMatrix[src][dest] = 1;  // Mark 1 to indicate an edge
}
 
// Function to print the adjacency matrix representation of the graph
void printGraph(int numVertices) {
  printf("Adjacency Matrix:\n");
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }
}
 
