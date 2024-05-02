#include "graph2.h"
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int vertex;         // Vertex value
    struct Node* next;  // Pointer to the next node
};

// Structure to represent a graph
struct Graph {
    int numVertices;          // Number of vertices in the graph
    struct Node** adjLists;   // Array of pointers to linked list heads
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for a new node
    if (!newNode) {  // Check if memory allocation failed
        perror("Memory allocation failed for creating a new node");  // Print error message
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }
    newNode->vertex = vertex;  // Assign the vertex value to the new node
    newNode->next = NULL;  // Set the next pointer to NULL
    return newNode;  // Return the new node
}

// Function to create a graph with numVertices vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));  // Allocate memory for the graph
    if (!graph) {  // Check if memory allocation failed
        perror("Memory allocation failed for creating the graph");  // Print error message
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }
    graph->numVertices = numVertices;  // Assign the number of vertices to the graph

    // Create an array of pointers to Node to represent adjacency lists
    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    if (!graph->adjLists) {  // Check if memory allocation failed
        perror("Memory allocation failed for adjacency lists");  // Print error message
        free(graph);  // Free the previously allocated memory for the graph
        exit(EXIT_FAILURE);  // Exit the program with failure status
    }

    // Initialize all adjacency lists as empty
    for (int i = 0; i < numVertices; ++i) {
        graph->adjLists[i] = NULL;  // Set each adjacency list head to NULL
    }

    return graph;  // Return the graph
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    if (!graph || src < 0 || src >= graph->numVertices || dest < 0 || dest >= graph->numVertices) {
        fprintf(stderr, "Invalid graph or vertex indices\n");  // Print error message to standard error
        return;  // Return if graph is invalid or vertex indices are out of range
    }

    // Create a new node for the destination vertex
    struct Node* newNode = createNode(dest);
    if (!newNode) {  // Check if memory allocation failed
        fprintf(stderr, "Memory allocation failed for new edge\n");  // Print error message
        return;  // Return if memory allocation failed
    }

    // Add the node to the front of the adjacency list of source vertex
    newNode->next = graph->adjLists[src];  // Point the new node to the current head of the adjacency list
    graph->adjLists[src] = newNode;  // Update the head of the adjacency list to the new node
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    if (!graph) {  // Check if graph is NULL
        fprintf(stderr, "Graph is NULL\n");  // Print error message to standard error
        return;  // Return if graph is NULL
    }

    for (int v = 0; v < graph->numVertices; ++v) {  // Loop through each vertex
        printf("\nAdjacency list of vertex %d\n head ", v);  // Print the vertex and heading message
        struct Node* temp = graph->adjLists[v];  // Get the head of the adjacency list
        while (temp) {  // Loop through the adjacency list
            printf("-> %d ", temp->vertex);  // Print the vertex value
            temp = temp->next;  // Move to the next node in the adjacency list
        }
        printf("\n");  // Move to the next line after printing the adjacency list for a vertex
    }
}

// Function to free the graph memory
void freeGraph(struct Graph* graph) {
    if (!graph) {  // Check if graph is NULL
        fprintf(stderr, "Graph is NULL\n");  // Print error message to standard error
        return;  // Return if graph is NULL
    }

    for (int i = 0; i < graph->numVertices; ++i) {  // Loop through each vertex
        struct Node* temp = graph->adjLists[i];  // Get the head of the adjacency list for the current vertex
        while (temp) {  // Loop through the adjacency list
            struct Node* prev = temp;  // Store the current node
            temp = temp->next;  // Move to the next node
            free(prev);  // Free the memory of the current node
        }
    }
    free(graph->adjLists);  // Free the memory allocated for adjacency lists array
    free(graph);  // Free the memory allocated for the graph
}
