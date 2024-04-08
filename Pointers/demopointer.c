#include <stdio.h>
#include <stdlib.h>
int * passreturnpoint(int *arr, int n)
{
	int i, *p; 
	p = &arr[0];
	return p;
}
int * doublepoint(int *arr, int n)
{
	int i, *p; 
	p = &arr[0];
	return p;
}
int main(){
	int n,*p;
	printf("Enter value of n:\n"); 
	scanf("%d",&n);
	int *arr = (int*)calloc(n,sizeof(int));
	printf("Enter elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	p = small(arr, n);
	printf("Smallest: %d",*p);
	free(arr);
	return 0;
}