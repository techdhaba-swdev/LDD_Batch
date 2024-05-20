#include "factorial.h"

int calculateFactorial(int n)
{
	if(n == 0 || n==1)
		{
			return 1;
		}
	else 
	{
		int factorial = 1;
		for(int i = 2; i <= n; i++) {
			factorial *=i;
	}
	return factorial;

}
}
