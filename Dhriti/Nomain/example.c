#include<stdio.h>


int add(int a, int b) {
        return a + b;
}


int sub(int a, int b) {
        return a - b;
}


float mul(float a, float b) {
        return a * b;
}

float divide(float a, float b) {
	if (b==0){
		printf("No Output:Error");
		return 0;
	}
        return a / b;
}

