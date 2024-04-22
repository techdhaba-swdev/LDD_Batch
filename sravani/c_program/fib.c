#include<stdio.h>
int fibonocci(int n){
	if(n<=1){
		return ;
	}
return fibonocci(n-1)+fibonocci(n-2);
}
int main(){
	int num;
	printf("Enter the number:\n");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		printf("%d\n",fibonocci(i));
		
	}
return 0;



}

