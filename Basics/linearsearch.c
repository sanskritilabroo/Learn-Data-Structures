#include <stdio.h>
int main()
{
	int a[30],i,j,key,n;
	printf("Enter the no. of elements:");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element to be searched:");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if (key == a[i])
			break;
	}
	printf(i);
}