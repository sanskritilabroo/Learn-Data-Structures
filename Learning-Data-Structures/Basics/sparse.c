#include <stdio.h>
#include <stdbool.h>

bool SparseCheck(int arr[], int n)
{
	int i; int c1=0, c2=0;
	for(i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			c1 ++;
		else 
		c2++;
	}
	if(c1 > c2)
		return true;
	else
		return false;
}
int main()
{
	int arr[10]; int i, j, n, temp;
	printf("Enter the value of n \n"); 
	scanf("%d", &n);
	printf("Enter the elements \n"); 
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	if (SparseCheck(arr, n) == true)
	printf("The matrix is a sparse matrix \n");
	else
	printf("The matrix is not a sparse matrix \n");
	return 0;
}