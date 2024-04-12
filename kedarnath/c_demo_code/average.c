#include<stdio.h>
#include<stdlib.h>
int * getRandom(){

	static int r[10];
	int i;
	for(i=0;i<10;++i){
		r[i]=rand();
		printf("i is %d is value %d\n",i,r[i]);
	}
	return r;
}	



int main(){

	int *p;
	int i=0;
	p=getRandom();
	for(i=0;i<10;i++){
		printf("i is %d is %d\n",i,*(p+i));
	}

	return 0;
}
