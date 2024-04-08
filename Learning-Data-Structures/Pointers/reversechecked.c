#include <stdio.h>
#include <stdlib.h>

void Reverse(int *p, int n)
{
    int *first = p;
	int *last = p+n-1;
	int temp;
	while(first<last)
	{
		temp = *first;
		*first = *last;
		*last = temp;
		first++;
		last--;
	}
	printf("Reversed array:");
	for(int i=0;i<n;i++)
		printf("%d",*(p+i));
}

int main()
{
    int arr[100];
    int *p, n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    p = arr; // Assign the array directly to the pointer
    Reverse(p, n);
    return 0;
}