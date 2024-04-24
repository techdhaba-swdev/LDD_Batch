#include "stringmain.h"

int main()
{
	char *strings[MAX_SIZE] = {NULL};
	int nstrings = 0;
	stringread(strings, &nstrings);
	stringsort(strings, nstrings);
	stringprint(strings, nstrings);

	for(int i = 0;i < nstrings; i++)
	{
		free(strings[i]);
	}

	return 0;
}

