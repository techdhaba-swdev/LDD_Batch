#include <stdio.h>
#include <stdlib.h>
#include "network.h"
#include <time.h>

int main() {
	clock_t start = clock();
    Graph social_network;
    social_network.num_users = 0;

    // Create users
    add_user(&social_network, "nandu", "coding, reading");
    add_user(&social_network, "nandini", "sports, cooking");
    add_user(&social_network, "nanditha", "coding, gaming");

    // Add friendships
    add_friendship(&social_network, "nandu", "nandini");
    add_friendship(&social_network, "nandini", "nanditha");

    // Search for users
    search_users_by_name(&social_network, "nandu");
    search_users_by_interest(&social_network, "coding");

    // Recommend friends
    recommend_friends(&social_network, "nandu");
    
    //Time taken
    clock_t end = clock();
    double time_spent = ((double)(end - start));
    printf("Time taken: %f seconds \n",time_spent);

    return 0;
}

