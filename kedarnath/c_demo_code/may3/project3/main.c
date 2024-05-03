#include"network.h"

int main() {

    clock_t start=clock();
    // Create a sample graph
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }
    graph->V = 3; // Number of users
    graph->adjList = (Node**)malloc(graph->V * sizeof(Node*));
    if (graph->adjList == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(graph);
        return EXIT_FAILURE;
    }

    // Initialize adjacency lists
    for (int i = 0; i < graph->V; i++) {
        graph->adjList[i] = createUserProfile("", ""); // Dummy node for each user
    }

    // Add connections (friends)
    addFriend(graph, "Alice", "Bob");
    addFriend(graph, "Alice", "Charlie");
    addFriend(graph, "Bob", "Charlie");

    // Example usage
    displayFriendList(graph, "Alice");
    displayFriendList(graph, "Bob");
    displayFriendList(graph, "Charlie");

    // Clean up
    destroyGraph(graph);
    
    clock_t end=clock();
    double time_taken=((double)(end-start));
    printf("time taken is %f\n",time_taken);

    return 0;
}

   
