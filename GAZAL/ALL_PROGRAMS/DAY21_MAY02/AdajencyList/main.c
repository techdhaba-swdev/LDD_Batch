#include "graph2.h"  // Include the header file containing function prototypes
#include <stdio.h>            // Include standard I/O library for printf, etc.

int main() {
    int numVertices = 4;                          // Number of vertices in the graph
    struct Graph* graph = createGraph(numVertices);  // Create a graph with the specified number of vertices

    addEdge(graph, 0, 1);  // Add edges between vertices
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);     // Print the adjacency list representation of the graph

    freeGraph(graph);      // Free the memory allocated for the graph

    return 0;              // Return 0 to indicate successful execution
}
