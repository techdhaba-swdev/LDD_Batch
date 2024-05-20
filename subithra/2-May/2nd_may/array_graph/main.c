// main.c

#include "array_graph.h"

int main() {
  // Define the number of vertices
  int numVertices = 4;

  // Initialize the graph
  initializeGraph(numVertices);

  // Add directed edges
  addEdge(0, 1, numVertices);
  addEdge(1, 2, numVertices);
  addEdge(2, 3, numVertices);

  // Print the adjacency matrix
  printGraph(numVertices);

  return 0;
}
