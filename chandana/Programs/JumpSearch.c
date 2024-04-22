#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;
    while (arr[(int)fmin(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    while (arr[prev] < x) {
        prev++;
        if (prev == fmin(step, n)) {
            return -1;
        }
    }
    if (arr[prev] == x) {
        return prev;
    }
    return -1;
}

int main() {
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 55;
    int index = jumpSearch(arr, n, x);
    if (index != -1) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not found\n");
    }
    return 0;
}
