#include"graph_struct.h"
struct Graph
{
  int numVertices;
  struct Node** adjLists;  // Array of pointers to linked list heads
};
int main()
{
  int numVertices = 4;
  struct Graph* graph = createGraph(numVertices);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  printGraph(graph);
  return 0;
}
