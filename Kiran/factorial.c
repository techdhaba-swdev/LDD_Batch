 #include<stdio.h>
int recu(int n)
{
	if(n>=1)
	{
		return n*recu(n-1);
	}
	
		else
		{
			return 1;
		}
}
int main ()
{
	int n = 5;
	int value = recu(n);
	printf(" value = %d", value);
	return 0;
}
