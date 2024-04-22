#include <stdio.h>
int *getRandom()
{
	static int r[10];
	int i;
	srand( (unsigned)time(NULL) );
	for ( i=0 ; i<10 ; i++ )
	{
		r[i] = rand();
		printf("r[%d] = 5d\n", i, r[i]);
	}
	return r;
}

