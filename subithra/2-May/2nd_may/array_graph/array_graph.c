// array_graph.c

#include "array_graph.h"
#include <stdio.h>

// Global variable to store the adjacency matrix
int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// Function to initialize the graph with no edges
bool initializeGraph(int numVertices) {
  // Check for invalid number of vertices
  if (numVertices <= 0 || numVertices > MAX_VERTICES) {
    fprintf(stderr, "Error: Invalid number of vertices.\n");
    return false;
  }

  // Initialize the adjacency matrix with all 0s
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      adjMatrix[i][j] = 0;
    }
  }
  return true;
}

// Function to add a directed edge from src to dest
bool addEdge(int src, int dest, int numVertices) {
  // Check for invalid source or destination vertex
  if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
    fprintf(stderr, "Error: Invalid source or destination vertex.\n");
    return false;
  }

  // Mark 1 to indicate an edge from src to dest
  adjMatrix[src][dest] = 1;
  return true;
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
