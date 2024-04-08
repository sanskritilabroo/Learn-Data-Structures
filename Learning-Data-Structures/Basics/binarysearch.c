#include <stdio.h>
int binary(int low,int high,int item,int a[])
{
	int mid; 
	if(low>high)
		return(-1);
	else
	{
		mid=(low+high)/2; 
		if(item==a[mid])
			return(mid); 
		else if(item<a[mid])
			return binary(low,mid-1,item,a);
		else
			return binary(mid+1,high,item,a);
	}
}
void main()
{
	int i, pos, a[30],n, item; 
	printf("Enter number of items:"); 
	scanf("%d",&n);
	printf("Enter the elements in ascending order:\n"); 
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter element to be searched:");
	scanf("%d",&item);
	pos=binary(0,n-1,item,a);
	if(pos!=-1)
		printf("Item found at location %d",pos+1);
	else
		printf("Item not found");
}