#include "profile.h"
#include <time.h> 
int main() { // Main function.
	clock_t start = clock();	
    UserProfile* profiles[26] = { NULL }; // Array of linked lists to store user profiles.
    GraphNode* graph[26] = { NULL }; // Array of linked lists to represent the graph of user connections.

    UserProfile* user1 = createProfile("Alice", "Reading, Traveling"); // Creating a user profile for Alice.
    UserProfile* user2 = createProfile("Bob", "Photography, Cooking"); // Creating a user profile for Bob.
    UserProfile* user3 = createProfile("Charlie", "Programming, Gaming"); // Creating a user profile for Charlie.

    profiles[user1->name[0] - 'A'] = user1; // Storing Alice's profile in the profiles array.
    profiles[user2->name[0] - 'A'] = user2; // Storing Bob's profile in the profiles array.
    profiles[user3->name[0] - 'A'] = user3; // Storing Charlie's profile in the profiles array.

    addFriend(graph, user1, user2); // Adding Bob as a friend of Alice.
    addFriend(graph, user1, user3); // Adding Charlie as a friend of Alice.

    UserProfile* searchedUser = searchUser("Bob", profiles); // Searching for a user with name "Bob".
    if (searchedUser != NULL) { // Checking if the user is found.
        printf("User found: %s\n", searchedUser->name); // Printing the name of the found user.
    } else {
        printf("User not found.\n"); // Printing a message if the user is not found.
    }

    printf("Friend list of Alice:\n"); // Printing a message.
    displayFriendList(graph[user1->name[0] - 'A']); // Displaying the friend list of Alice.

    freeMemory(profiles, graph); // Freeing allocated memory for user profiles and graph nodes.
	clock_t end = clock();
	double time_used = ((double)(start - end)) / CLOCKS_PER_SEC;
	printf("time taken : %f\n" , time_used);
    return 0; // Returning from the main function.
}
