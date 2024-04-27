#include<stdio.h>
int* ptr = (int*)malloc(sizeof(int)); // Allocate
memoryfree(ptr); // Deallocate
memory*ptr = 42; // Using a dangling pointer can crash
