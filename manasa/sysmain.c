#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "system.h"
#include <string.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Creating a graph for user connections
    GraphNode *graph = NULL;

    // Creating user profiles
    createUserProfile(&graph, "Alice", "Music, Travel");
    createUserProfile(&graph, "Bob", "Sports, Reading");
    createUserProfile(&graph, "Charlie", "Cooking, Movies");

    // Adding friends
    addFriend(graph, searchUserByName(graph, "Alice"), searchUserByName(graph, "Bob"));
    addFriend(graph, searchUserByName(graph, "Alice"), searchUserByName(graph, "Charlie"));
    addFriend(graph, searchUserByName(graph, "Bob"), searchUserByName(graph, "Charlie"));

    // Recommend friends based on mutual connections or interests
    recommendFriends(graph, "Alice");

    // Display a user's friend list and news feed
    displayFriendList(searchUserByName(graph, "Alice"));
    displayNewsFeed(searchUserByName(graph, "Alice"));

    // Measure time taken
    start = clock();
    // Perform operations here...
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
