#ifndef GRAPH_H
#define GRAPH_H

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int vertex);
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);

#endif /* GRAPH_H */
