#include <stdio.h>

int * reverse(int *p, int n)
{
	int *first = p;
	int *last = p+n-1;
	while(first<last)
	{
		int temp = *first;
		*first = *last;
		*last = temp;
		first++;
		last--;
	}
	printf("Reversed array:");
	for(int i=0;i<n;i++)
		printf("%d",*p++);
}
int main(){
	int n;
	printf("Enter value of n:"); 
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	reverse(arr, n);
	return 0;
}