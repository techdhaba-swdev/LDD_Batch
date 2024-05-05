#include <stdio.h>
#include <stdlib.h>
#include "network.h"
#include <time.h>

int main() 
{
	clock_t start = clock();
    	Graph social_network;
    	social_network.num_users = 0;

    	// Create users
    	add_user(&social_network, "Vivek", "Photography, Trecking");
    	add_user(&social_network, "Koushik", "Music, Riding");
    	add_user(&social_network, "karthik", "Photography, Drinking");
	
    	// Add friendships
    	add_friend(&social_network, "Vivek", "Koushik");
    	add_friend(&social_network, "Koushik", "karthik");

    	// Search for users
    	search_by_name(&social_network, "Vivek");
    	search_by_interest(&social_network, "Photography");

    	// Recommend friends
    	recommend_friends(&social_network, "Vivek");
    	//time taken
    	clock_t end = clock();
    	double time_taken = ((double)(end - start));
    	printf("Time taken: %f seconds \n", time_taken);


    	return 0;
}
