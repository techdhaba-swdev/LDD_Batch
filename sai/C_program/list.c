#include<stdio.h>

typedef struct
{
	int arr[MAX];
	int max;
	int size;
}LIST;

void insert(int j, int it, LIST*pl)
{
	int i;
	for ( i = pl->size; i >= j; i=i-1)
	{
		pl->

