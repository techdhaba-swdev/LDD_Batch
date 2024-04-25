#include <stdio.h>
//Standard Input/Output library

//Function prototypes 
//Funtional call 
int add(int num1,int num2) {
	return num1+num2;
//Return the calculated sum
}
int sub(int num1,int num2){
	return num1-num2
//return the calculated sub
}
int mul(int num1,int num2){
	return num1*num2;
	//return calculated mul
}
int div(int num1,int num2){
	if(num2!=0){
		return num1/num2;
		//return calculated div
	}
	else{
		printf("Error Division by zero\n");
		return 0;
		//Indiacate successful program termination.
	}
}

