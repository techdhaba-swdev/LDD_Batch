#include "graph1.h" // Include the header file for function prototypes
#include <stdio.h>
#define MAX_VERTICES 100

static int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Define the adjacency matrix as static to limit its scope

// Function to initialize the graph with no edges
void initializeGraph(int numVertices) {
  // Loop through each vertex
  for (int i = 0; i < numVertices; i++) {
    // Loop through each vertex again (nested loop)
    for (int j = 0; j < numVertices; j++) {
      adjMatrix[i][j] = 0; // Set the value in the adjacency matrix to 0
    }
  }
}

// Function to add a directed edge from src to dest
void addEdge(int src, int dest) {
  if (src >= 0 && src < MAX_VERTICES && dest >= 0 && dest < MAX_VERTICES) { // Check if src and dest are within bounds
    adjMatrix[src][dest] = 1;  // Mark 1 in the adjacency matrix to indicate an edge from src to dest
  } else {
    // Handle invalid vertex indices (consider logging or error reporting)
  }
}

// Function to print the adjacency matrix representation of the graph
void printGraph(int numVertices) {
  printf("Adjacency Matrix:\n"); // Print the label indicating the start of adjacency matrix
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      printf("%d ", adjMatrix[i][j]); // Print the value at position [i][j] in the adjacency matrix
    }
    printf("\n"); // Move to the next line after printing all values in a row
  }
}
