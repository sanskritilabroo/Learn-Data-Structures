#include <stdio.h>
#include <stdbool.h>

void triplets(int arr[], int n)
{
	bool flag = false;
	for(int i = 0; i < n-2; i++)
	{
		for(int j = i+1; j < n-1; j++)
		{
			for(int k = j+1; k < n; k++)
			{
				if ((arr[i] + arr[j] + arr[k])==0)
				{
					printf("%d %d %d\n", arr[i],arr[j],arr[k]);
					flag=true;
				}
			}
		}
	}
	if (flag==false)
		printf("No triplets found");
}
void main()
{
	int arr[10],n;
	printf("Enter the value of n \n"); 
	scanf("%d", &n);
	printf("Enter the elements \n"); 
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	triplets(arr,n);
}