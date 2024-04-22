#include <stdio.h>
void insert(){
	int arr[5];
	int i;
	for(i=0;i<3;i++)
	{
printf("%d",i+1);
scanf("%d",&arr[i]);
	}
	int new ;              
 printf("insert   new element");
scanf("%d",&new);
for(i=2;i>=1;i--){
	arr[i+1] = arr[i];
}
arr[1]=new;
printf("after insertionnnnn\n");
for(i=0;i<4;i++)
{
	printf("%d",arr[i]);
}
int main(){
insert();
return 0;
}
}








