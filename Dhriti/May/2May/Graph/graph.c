#include <stdio.h>
#include "graph.h"

#define MAX_VERTICES 100 // Maximum number of vertices in the graph

int adjMatrix[MAX_VERTICES][MAX_VERTICES]; //Its a 2D array- Adjacency matrix to represent the graph. stores info about edges between vertice

// Function to initialize the graph with no edges
void initializeGraph(int numVertices) {
  for (int i = 0; i < numVertices; i++) { // Loop through each row
    for (int j = 0; j < numVertices; j++) { // Loop through each column
      adjMatrix[i][j] = 0; // Set the value to 0, indicating no edge between vertices i and j
    }
  }
}

// Function to add a directed edge from source to destination
void addEdge(int src, int dest) {
  adjMatrix[src][dest] = 1;  //  1 to indicate an edge from src to dest
}

// Function to print the adjacency matrix representation of the graph
void printGraph(int numVertices) {
  printf("Adjacency Matrix:\n"); // Print a header
  for (int i = 0; i < numVertices; i++) { // Loop through each row
    for (int j = 0; j < numVertices; j++) { // Loop through each column
      printf("%d ", adjMatrix[i][j]); // Print the value at position (i, j) in the adjacency matrix
    }
    printf("\n"); 
  }
}

