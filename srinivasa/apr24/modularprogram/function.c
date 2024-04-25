int top =-1;
int arr[5];
void push(int x )
{
	if (top ==4)
	{
		printf("\nstack is full");
	}
	else 
	{
		top = top +1;
		arr[top]=x;
	}
}
void pop()
{
	if (top ==-1)
	{
		printf("stack is empty\n");
	}
	else 
	{
		printf("poped element is %d",arr[top]);
		top = top -1;
	}
}



