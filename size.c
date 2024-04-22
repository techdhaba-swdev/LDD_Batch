#include <stdio.h>

#define MAX 5 // Define the maximum array size

typedef struct {
    int arr[MAX];
    int max;
    int size;
} LIST;

void insert(int j, int it, LIST *pl) {
 
    int i;
    for (i = pl->size; i >= j; i--) {
        pl->arr[i + 1] = pl->arr[i];
    }

    // Step 2: Write to gap
    pl->arr[j] = it;

    // Step 3: Update size
    pl->size++;
}


int main()
{


