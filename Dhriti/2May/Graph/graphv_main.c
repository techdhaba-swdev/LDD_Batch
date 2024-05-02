#include<stdio.h>
#include "graph_ver.h"

int main() {
  int numVertices = 4;
  struct Graph* graph = createGraph(numVertices);  // Create a graph with 4 vertices

  addEdge(graph, 0, 1);  // Add an edge from vertex 0 to vertex 1
  addEdge(graph, 1, 2);  // Add an edge from vertex 1 to vertex 2
  addEdge(graph, 2, 3);  // Add an edge from vertex 2 to vertex 3

  printGraph(graph);  // Print the adjacency lists of the graph

  return 0;
}
