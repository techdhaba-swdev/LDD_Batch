#include <stdio.h>
#include "binarysearch.h"

int main() {
    int arr[] = {11, 24, 37, 45, 55, 61, 73, 96, 98};
    int target = 55;

    int ans = binarysearch(arr, target);

    if (ans != -1)
        printf("The target %d is at index %d\n", target, ans);
    else
        printf("The target %d is not in the array\n", target);

    return 0;
}
	

