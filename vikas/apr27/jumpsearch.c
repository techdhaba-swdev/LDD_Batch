#include<math.h>
#include "jumpsearch.h"

int jump_search(int arr[], int n, int target) {
    // Determining the jump size
    int step = sqrt(n);
    int prev = 0; // Previous index
    
    // Finding the block where the target might be present
    while (arr[fmin(step, n)-1] < target) {
        prev = step;
        step += sqrt(n);
        // If the previous index exceeds the array size, target cannot be present
        if (prev >= n) {
            return -1;
        }
    }
    
    // Linear search within the identified block
    while (arr[prev] < target) {
        prev++;
        // If reached the end of the block, target is not present
        if (prev == fmin(step, n)) {
            return -1;
        }
    }
    
    // Checking if the target is found
    if (arr[prev] == target) {
        return prev;
    }
    
    // If target not found
    return -1;
}
