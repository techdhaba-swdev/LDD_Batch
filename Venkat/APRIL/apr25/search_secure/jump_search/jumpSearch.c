#include "jumpSearch.h"
#include <math.h>

// Macro for finding the minimum of two values
#define min(x, y) ((x) < (y) ? (x) : (y))

// Jump search function implementation
int jumpSearch(int a[], int n, int k) {
    int t = 0;  // Initialize the variable t to 0
    int b = (int) sqrt(n);  // Calculate the jump size using square root of n

    // Perform jump until the element at position t is less than k
    while (a[min(b, n) - 1] < k) {
        t = b;
        b += b + (int) sqrt(n);  // Update jump size

        // If the jump position exceeds array size, return -1 (element not found)
        if (t >= n) {
            return -1;
        }
    }

    // Perform linear search within the block where k is expected to be
    while (a[t] < k) {
        t = t + 1;
        // If t reaches the minimum of jump size and array size, return -1 (element not found)
        if (t == min(b, n)) {
            return -1;
        }
        // If k is found at position t, return the index t
        if (a[t] == k) {
            return t;
        }
    }

    return -1;  // Return -1 if k is not found in the array
}
