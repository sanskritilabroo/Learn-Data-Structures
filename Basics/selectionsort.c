#include <stdio.h>

void SelectSort(int arr[], int n)
{
	int pass, i, min_index, temp;
	for (pass = 0; pass < n-1; pass++)
	{
		min_index = pass;
		for(i = pass+1; i < n; i++)
		{
			if (arr[i] < arr[min_index])
				min_index = i;

			if (min_index != pass)
			{
				temp = arr[pass];
				arr[pass] = arr[min_index];
				arr[min_index] = temp;
			}
		}
	}

}

void main()
{
	int arr[10]; int i, j, n, temp;
	printf("Enter the value of n \n"); 
	scanf("%d", &n);
	printf("Enter the elements \n"); 
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	/* Selection sorting begins */
	SelectSort(arr, n);
	printf("The sorted list is (using selection sort): \n"); 
	for (i = 0; i < n; i++)
		printf("%d\t", arr[i]);
}