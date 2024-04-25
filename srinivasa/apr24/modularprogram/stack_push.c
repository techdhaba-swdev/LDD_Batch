int arr[5];
int top=-1;
void stack_push(int x )
{
	if (stack_is_full()==1)
	{
		printf("stack is full");
	}
        else 
	{
	top =top+1;
        arr[top]=x;
	}
}	
