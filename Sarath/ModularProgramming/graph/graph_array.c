#include"graph.h"
int main()
{
  int numVertices = 4;
  initializeGraph(numVertices);
  //addEdge(0,0);
  //addEdge(0, 1); // Directed edge from 0 to 1
  //addEdge(1, 2); // Directed edge from 1 to 2
  //addEdge(2, 3); // Directed edge from 2 to 3
  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
    {
      addEdge(i,j);
    }
  }
  printGraph(numVertices);
  return 0;
}
