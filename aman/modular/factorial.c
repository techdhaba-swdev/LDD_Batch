#include "factorial.h"// its a preproccessor which include content of factorial.h
int factorial(int n){//it defines factorial function and int n specifies that function take integer parametre n
	if(n==0 || n==1){//herechecks input n is equal to 0 or 1.and if n is 0 or 1 it return 1 as the factorial of 0 and 1 is 1
		return 1;}
	else{//recursive case of factorial function, and calculate factorial of n by multiply  n with factorial of n-1/ where recursive call contunue until n becomes 0 or 1 at which recursion stop.
	return n * factorial(n-1);
	}
}
