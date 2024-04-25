#include<stdio.h>
#define INT_MAX 14

int main(){

	float x = 1.5;
	int y = (int)x;
	printf("x is %f\n",x);
	printf("y is %d\n",y);
	
	int z = INT_MAX;
	z = z + 1;
	printf("INT_MAZ is %d\n",INT_MAX);
	printf("z is %d\n",z);
	
	int a;
    	printf("a is %d\n", a); 
    	
    	int b = -1;
        unsigned int c = b; // Insecure type conversion
        printf("c is %d\n", c);
        printf("b is %d\n", b);





	FILE *fp = fopen("data.txt", "r");
	/*if (fp == NULL) {
        	printf("Error opening file!\n");
        	return 1;
    	}*/
 
    	char arr[200];
    	char ch[200];
    
    	fscanf(fp,"%s",ch);
    	printf("%s\n",ch);
    	
    	
    	
}
 
    
