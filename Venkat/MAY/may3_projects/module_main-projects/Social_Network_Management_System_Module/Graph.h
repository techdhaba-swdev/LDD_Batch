#ifndef GRAPH_H
#define GRAPH_H

#include "User.h"

// Define the maximum number of users in the graph.
#define MAX_USERS 100

// Graph structure to hold all users.
typedef struct Graph {
    int numUsers; // Number of users currently in the graph.
    User users[MAX_USERS]; // Array of users.
} Graph;

#endif // GRAPH_H
