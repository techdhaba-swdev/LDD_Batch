#include <stdio.h>
#include "sus.h"
#include <time.h>

int main() {
	//intialise an empty binary search tree represented by the root node
    struct Node* root = NULL;
    clock_t start = clock();
    //insert node with various values
   root = insert(root, 50);
   root= insert(root, 30);
   root= insert(root, 20);
   root= insert(root, 40);
   root=insert(root, 70);
   root=insert(root, 60);
   root= insert(root, 80);
//print elements in sorted order using in order traversal
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    int sum = calculateSum(root);
    printf("Sum of all node values: %d\n", sum);
    clock_t stop = clock();//stop the clock
    double time = ((double)stop-start);//cal the stop-start time
    printf("Time = %f\n",time);


    return 0;
}
