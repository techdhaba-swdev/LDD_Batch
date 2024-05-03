#include "profile.h"
void freeMemory(UserProfile* profiles[], GraphNode* graph[]) { // Function to free allocated memory for user profiles and graph nodes.
    for (int i = 0; i < 26; i++) { // Looping through each index of the profiles and graph arrays.
        UserProfile* currentProfile = profiles[i]; // Getting the current user profile.
        while (currentProfile != NULL) { // Looping through each user profile at the current index.
            UserProfile* nextProfile = currentProfile->next; // Getting the next user profile.
            free(currentProfile); // Freeing memory for the current user profile.
            currentProfile = nextProfile; // Moving to the next user profile.
        }
        GraphNode* currentGraph = graph[i]; // Getting the current graph node.
        while (currentGraph != NULL) { // Looping through each graph node at the current index.
            GraphNode* nextGraph = currentGraph->next; // Getting the next graph node.
            free(currentGraph); // Freeing memory for the current graph node.
            currentGraph = nextGraph; // Moving to the next graph node.
        }
    }
}
