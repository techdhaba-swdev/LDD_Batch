#include<stdio.h>
#include "graph.h"

int main() {
  int numVertices = 4; // Number of vertices in the graph

  initializeGraph(numVertices); // Initialize the graph with no edges

  addEdge(0, 1); // Add a edge from vertex 0 to vertex 1
  addEdge(1, 2); // Add a edge from vertex 1 to vertex 2
  addEdge(2, 3); // Add a edge from vertex 2 to vertex 3

  printGraph(numVertices); // Print the adjacency matrix of the graph

  return 0; 
}

