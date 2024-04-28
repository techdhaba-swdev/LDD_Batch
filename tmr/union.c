#include<stdio.h>
int main()
{
	union un
	{

	       char a ;
	       char b ;
	       char c ;
	     
	       char d ;
	};

	      union un un1;
	      un1.a = 'A' ;
	      un1.a = 'B';

	      un1.a = 'C';

	      un1.a = 'D';
             


