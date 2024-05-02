#include <stdio.h>

#define MAX_VERTICES 100

// Global variable to store the adjacency matrix of the graph
int adjMatrix[MAX_VERTICES][MAX_VERTICES];

/* Function to initialize the graph with no edges */
void initializeGraph(int numVertices) {
    // Loop through all vertices
    for (int i = 0; i < numVertices; i++) {
        // For each vertex, loop through all vertices again to set all edges to 0
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

/* Function to add a directed edge from src to dest */
void addEdge(int src, int dest) {
    // Mark 1 to indicate an edge from src to dest
    adjMatrix[src][dest] = 1;
}

/* Function to print the adjacency matrix representation of the graph */
void printGraph(int numVertices) {
    // Print the header
    printf("Adjacency Matrix:\n");
    // Loop through all vertices
    for (int i = 0; i < numVertices; i++) {
        // For each vertex, loop through all vertices again to print its adjacent vertices
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]); // Print the value in the adjacency matrix
        }
        printf("\n"); // Move to the next line for the next vertex
    }
}

// Main function
int main() {
    int numVertices = 4; // Number of vertices in the graph

    // Initialize the graph
    initializeGraph(numVertices);

    // Add directed edges to the graph
    addEdge(0, 1); // Directed edge from vertex 0 to vertex 1
    addEdge(1, 2); // Directed edge from vertex 1 to vertex 2
    addEdge(2, 3); // Directed edge from vertex 2 to vertex 3

    // Print the adjacency matrix representation of the graph
    printGraph(numVertices);

    return 0;
}
