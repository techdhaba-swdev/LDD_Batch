#include <stdio.h> // Include standard input/output library.
#include <stdlib.h> // Include standard library.
#include "graph.h" // Include the header file containing the declaration of Graph struct and related functions.

int main() { // Main function.
  int numVertices = 4; // Number of vertices in the graph.
  struct Graph* graph = createGraph(numVertices); // Create a new graph with the given number of vertices.

  addEdge(graph, 0, 1); // Add edges to the graph.
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph); // Print the adjacency list representation of the graph.

  return 0; // Return 0 to indicate successful execution.
}
