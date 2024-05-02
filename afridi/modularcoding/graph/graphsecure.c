#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

#define MAX_VERTICES 100

// Global variable to store the adjacency matrix of the graph
int **adjMatrix;

/* Function to initialize the graph with no edges */
void initializeGraph(int numVertices) {
    // Allocate memory for adjacency matrix
    adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    if (adjMatrix == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        if (adjMatrix[i] == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            exit(EXIT_FAILURE);
        }
    }

    // Loop through all vertices
    for (int i = 0; i < numVertices; i++) {
        // For each vertex, loop through all vertices again to set all edges to 0
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

/* Function to add a directed edge from src to dest */
void addEdge(int src, int dest, int numVertices) {
    // Check if vertices are within range
    if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
        printf("Invalid vertex indices. Exiting...\n");
        exit(EXIT_FAILURE);
    }
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
    addEdge(0, 1, numVertices); // Directed edge from vertex 0 to vertex 1
    addEdge(1, 2, numVertices); // Directed edge from vertex 1 to vertex 2
    addEdge(2, 3, numVertices); // Directed edge from vertex 2 to vertex 3

    // Print the adjacency matrix representation of the graph
    printGraph(numVertices);

    // Free allocated memory
    for (int i = 0; i < numVertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
