#include"network.h"

int main() {
    
    clock_t start=clock();
    Graph social_network;
    social_network.num_users = 0;

    // Create users
    add_user(&social_network, "Alice", "coding, reading");
    add_user(&social_network, "Bob", "sports, cooking");
    add_user(&social_network, "Charlie", "coding, gaming");

    // Add friendships
    add_friendship(&social_network, "Alice", "Bob");
    add_friendship(&social_network, "Bob", "Charlie");

    // Search for users
    search_users_by_name(&social_network, "Alice");
    search_users_by_interest(&social_network, "coding");

    // Recommend friends
    recommend_friends(&social_network, "Alice");
    clock_t end=clock();
    double time_taken=((double)(end-start));
    printf("time taken is %f\n",time_taken);

    return 0;
}

   