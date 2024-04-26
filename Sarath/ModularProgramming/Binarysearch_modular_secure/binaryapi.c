int binarysearch(int arr[],int key,int low,int high) //API of binarysearch
{
	int mid=(low+high)/2; //INITIALIZING MID WITH HALF OF LOW+HIGH
	if(low>high) //In case of low is greater than high it will return -1
	{
		return -1;
	}
	if(arr[mid]==key) //return mid if array mid equals to required key value
	{
		return mid;
	}
	else if(arr[mid]>key) //recursively calls binarysearch with high=mid-1 if mid value is more then key
	{
		return binarysearch(arr,key,low,mid-1);
	}
	else if(arr[mid]<key) //recursively calls binarysearch with low=mid+1 if mid value is more then key
	{
		return binarysearch(arr,key,mid+1,high);
	}
	return 0;
}
