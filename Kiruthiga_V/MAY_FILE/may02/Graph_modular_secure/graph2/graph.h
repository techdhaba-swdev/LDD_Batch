#ifndef GRAPH_H
#define GRAPH_H
struct Node {
  int vertex;
  struct Node* next;
};
// Structure to represent the graph
struct Graph {
  int numVertices;
  struct Node** adjLists;  // Array of pointers to linked list heads

};
 
//function prototypes
struct Node* createNode(int vertex);
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);

#endif
