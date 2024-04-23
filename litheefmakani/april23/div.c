#include<stdio.h>
float div(float a,float b){
		while(b==0){
			printf("division is not performed\n");
			return 0;
		}
		return a/b;
	}
