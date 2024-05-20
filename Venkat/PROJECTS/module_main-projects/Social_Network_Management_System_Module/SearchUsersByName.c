#include "SearchUsersByName.h"
#include <string.h>
#include <stdio.h>

// Function to search for users by name.
void searchUsersByName(Graph *graph, char *name) {
    for (int i = 0; i < graph->numUsers; i++) {
        if (strcmp(graph->users[i].profile.name, name) == 0) {
            printf("User found: %s\n", graph->users[i].profile.name);
            // Display additional user details here if needed.
        }
    }
}
