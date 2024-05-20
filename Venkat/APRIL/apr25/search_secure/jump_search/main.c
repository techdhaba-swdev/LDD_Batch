#include <stdio.h>
#include "jumpSearch.h"

int main() {
    int a[] = {3, 7, 9, 13, 14, 15, 16};
    int k = 14;

    // Call the jump search function to find the index of element k in array a
    int result = jumpSearch(a, 7, k);

    // Print the result based on whether k is found or not
    if (result != -1) {
        printf("Element %d found at index %d\n", k, result);
    } else {
        printf("Element %d not found in the array\n", k);
    }

    return 0;
}
