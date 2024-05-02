#include <stdio.h>
#include "graph3.h"

int main() {
  int numVertices = 4;

  initializeGraph(numVertices);

  addEdge(0, 1, numVertices); // Directed edge from 0 to 1
  addEdge(1, 2, numVertices); // Directed edge from 1 to 2
  addEdge(2, 3, numVertices); // Directed edge from 2 to 3

  printGraph(numVertices);

  // Free allocated memory
  freeGraph(numVertices);

  return 0;
}
  //secure code -  it correctly frees the allocated memory when it is no longer neede and reducing the risk of memory leak.also addEdge function checks whether the source and destination vertices are within the range of valid vertices before adding an edgewhich helps to  prevent buffer overflows and access violations.
