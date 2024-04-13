#include <stdio.h>

int fibonacci(int n)
{
	if (n <= 1)
	{
	     return n;
	     }
	return fibonacci(n-1) + fibonacci(n -2);
}

void PrintFibonacci(int n)
{
      for(int  i = 0; i < n; i++)
      {
            printf("%d ", fibonacci(i));
      }
}

int main()
{
    int n;
    printf("Enter the numbeeer of terms:");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    PrintFibonacci(n);
    return 0;
}

