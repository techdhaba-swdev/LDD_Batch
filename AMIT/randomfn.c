#include<stdio.h>
int *getRandom()
{
	static int r[10];
	srand((unsigned)time(NULL));
	for(int i=0;i<10;i++)
	{
		r[i]=rand();
		printf("r[%d]=%d\n",i,r[i]);
	}
	return r;
}
	int main()
	{
		int *p;
		int i;
		p=getRandom();
		for(i=0;i<10;i++)
		{

			printf("*(p+%d) : %d\n",i,*(p+i));
		}
		return 0;
	}

