#include "graph.h"//Including the header file for the graph.h 
#include <time.h>
int main() {
	clock_t start,end;
	double cpu_time_used;

    SocialNetwork* network = createSocialNetwork();//creating a new social network

    //Measure the time taken by the addUserProfile function
    start=clock();

    // Adding user profiles
    addUserProfile(network, "Seetha", "Art, Music");//Adding user profile for seetha with interests
    addUserProfile(network, "Ram", "Sports, Movies");//Adding user profile for ram with interests
addUserProfile(network, "Charlie", "Technology, Reading");//Adding user profile for Charlie with interests
    addUserProfile(network, "Radha", "Gaming, Cooking");//Adding user profile for Radha with interests
    addUserProfile(network, "Raman", "Travel, Photography");//Adding user profile foe Raman with interests
							    

    // Adding friendships
    addFriend(network, "Seetha", "Ram");//seetha become friends with ram
    addFriend(network, "Seetha", "Charlie");//seetha become friends with charlie
    addFriend(network, "Seetha", "Radha");//seetha become friends with radha
    addFriend(network, "Seetha", "Raman");//seetha become friends with raman
    addFriend(network, "Ram", "Charlie");//ram become friends with charlie
    addFriend(network, "Ram", "Radha");//ram become friends with radha
    addFriend(network, "Ram", "Raman");//ram become friends with raman
    addFriend(network, "Charlie", "Radha");//charlie become friends with radha
    addFriend(network, "Charlie", "Raman");//charlie become friends with raman
    //addFriend(network, "Radha", "Raman");//radha become friends with raman 

    // Displaying friend list
    displayFriendList(network, "Seetha");//displaying seetha's friend list
    displayFriendList(network, "Ram");//displaying ram's friend list
    displayFriendList(network, "Charlie");//displaying charlie friend list
    displayFriendList(network, "Radha");//displaying radha freind list
    displayFriendList(network, "Raman");//displaying raman friend list

    // Recommending friends
    recommendFriends(network, "Seetha");//recommending friends for seetha
    recommendFriends(network, "Ram");//recommending friends for ram
    recommendFriends(network, "Charlie");//recommending freinds for charlie
    recommendFriends(network, "Radha");//recommending friends for radha
    recommendFriends(network, "Raman");//recommending friends for raman

    // More functionality testing...
    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total time taken %f seconds to excute.\n",cpu_time_used);


    return 0;//Returning 0 to indicate successful execution.
}
