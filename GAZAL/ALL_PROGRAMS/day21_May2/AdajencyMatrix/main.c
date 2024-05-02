#include "graph1.h" // Include the header file for function prototypes
#include<stdio.h>
#include<stdlib.h>
int main() {
  int numVertices = 4; // Number of vertices in the graph

  initializeGraph(numVertices); // Initialize the graph with the specified number of vertices

  addEdge(0, 1); // Add a directed edge from vertex 0 to vertex 1
  addEdge(1, 2); // Add a directed edge from vertex 1 to vertex 2
  addEdge(2, 3); // Add a directed edge from vertex 2 to vertex 3

  printGraph(numVertices); // Print the adjacency matrix representation of the graph

  return 0; // Return 0 to indicate successful execution
}