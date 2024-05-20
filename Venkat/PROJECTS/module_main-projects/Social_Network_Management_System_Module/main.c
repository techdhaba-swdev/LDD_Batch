#include "CreateUserProfile.h"
#include "AddFriend.h"
#include "SearchUsersByName.h"
#include "DisplayFriends.h"
#include <time.h>
#include <stdio.h>
int main() {
    // Start the clock
    clock_t start = clock();
    Graph graph; // Create a graph instance.
    graph.numUsers = 0; // Initialize the number of users to 0.

    // Create user profiles.
    createUserProfile(&graph, "Venkat", "Gaming, Cricket");
    createUserProfile(&graph, "messi", "Football, Golf");
    createUserProfile(&graph, "Rohit Sharma", "Cricket, Traveling");
    createUserProfile(&graph, "Sidharth Malhotra", "Music, acting");

    // Add friends.
    addFriend(&graph, 0, 1); // Venkat and messi are now friends.
    addFriend(&graph, 0, 2); // Venkat and Rohit Sharma are now friends.
    addFriend(&graph, 0, 3); // Venkat and Sidharth Malhotra are now friends.

    // Search for users by name.
    searchUsersByName(&graph, "Venkat");

    // Display a user's friend list.
    displayFriends(&graph, 0);
    // Stop the clock

    clock_t end = clock();

    // Calculate the elapsed time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);

    return 0; // End of the program.
}
