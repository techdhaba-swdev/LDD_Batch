#include<stdio.h>
#include "graph.h"
int main() {
  int numVertices = 4;

  initializeGraph(numVertices);

  addEdge(0, 1,numVertices); // Directed edge from 0 to 1
  addEdge(1, 2,numVertices); // Directed edge from 1 to 2
  addEdge(2, 3,numVertices); // Directed edge from 2 to 3

  printGraph(numVertices);

  return 0;
}

