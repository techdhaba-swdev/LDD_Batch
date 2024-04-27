#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
int main()
{
	//Enqueuing element to the queue from first
	enqueue(40); 
   	enqueue(30); 
   	enqueue(20);
   	enqueue(10);
        print(); //printing enqueued elements using print() API
        int d1=dequeue(); //returned dequeued value from dequeue API and taken to another variable
        printf("Dequeuing element is %d\n",d1); //Printing the dequeued element 
        print();
        int d2=dequeue();
        printf("Dequeuing element is %d\n",d2);
        print();

        return 0;
}
