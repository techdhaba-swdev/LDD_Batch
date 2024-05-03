#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include"network.h"

int main()
{
    clock_t start = clock();
    // Example usage:
    struct UserProfile* profiles = NULL;
    // Create user profiles (add to linked list)
    struct UserProfile* user1 = createUserProfile("Alice", "Programming, Music");
    struct UserProfile* user2 = createUserProfile("Bob", "Hiking, Photography");
    profiles = user1;
    user1->next = user2;

    // Initialize the graph (add edges for friend connections)
    struct Graph* socialGraph = createGraph(2);
    addFriend(socialGraph, 0, 1); // Alice and Bob are friends

    // Search for users
    searchUsers(profiles, "Programming");
    searchUsers(profiles, "Hiking");

    // Recommend friends for Alice (user ID 0)
    recommendFriends(socialGraph, 0);

    // Display friend list
    displayFriendList(socialGraph, 0); // Alice's friend list

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
      printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
