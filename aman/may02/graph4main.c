#include "graph4.h"
#include<stdlib.h>
#include<stdio.h>
int main() {
  int numVertices = 4;
  struct Graph* graph = createGraph(numVertices);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph);

  for (int i = 0; i < numVertices; ++i) {
    struct Node* temp = graph->adjLists[i];
    while (temp) {
      struct Node* prev = temp;
      temp = temp->next;
      free(prev);
    }
  }
  free(graph->adjLists);
  free(graph);

  return 0;
}
//secure code - Error check for memory allocation is added in both createNode and createGraph functions.Memory allocated for the adjacency lists is freed in the main function before exit. error messages are displayed if memory allocation fails.
