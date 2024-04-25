#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
int main()
{

	enqueue(40);
   	enqueue(30);
   	enqueue(20);
   	enqueue(10);
        print();
        int d1=dequeue();
        printf("Dequeued element is %d\n",d1);
        print();
        int d2=dequeue();
        printf("Dequeued element is %d\n",d2);
        print();

        return 0;
}
