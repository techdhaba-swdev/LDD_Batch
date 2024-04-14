typedef struct
{
	int arr[max];
	int max;
	int size;
}

LIST
void insert (int j, int it, LIST *PL)
	int i;
	for(i=pl->size; i>=j; i=i-1)
	{
		pl->arr[i+1] = pl->arr[i];
	};
pl->arr[j] = it;
pl-> = pl->size + 1;
}

