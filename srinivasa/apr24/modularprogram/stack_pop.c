int top = -1;
int arr[5];
int stack_pop()
{
	if (stack_is_empty==1)
	{
		return 0;
	}
	else 
	{
		int a = arr[top];
		top = top-1;
		return a;
	}
}
