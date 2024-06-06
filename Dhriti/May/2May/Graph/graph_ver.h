#ifndef GRAPH_VER_H
#define GRAPH_VER_H


// Structure to represent a node in the linked list
struct Node {
  int vertex;         // Data field to store the vertex number
  struct Node* next;  // Pointer to the next node in the linked list
};

// Structure to represent the graph
struct Graph {
  int numVertices;     // Number of vertices in the graph
  struct Node** adjLists;  // Array of pointers to linked list heads (adjacency lists)
};

struct Node* createNode(int vertex);
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);

#endif
