#include <stdio.h>
#include <stdlib.h>
int * Smallest(int *p, int n)
{
	int i, *smallest; 
	smallest = p;
    for(i = 0; i < n; i++)  
    {  
        if( *(p + i) < *smallest)  
            *smallest = *(p + i);  
    } 
	return smallest;
}

int main()
{
    int n,*p;
	int *arrptr;
	printf("Enter value of n:\n"); 
	scanf("%d",&n);
	arrptr = (int*)calloc(n,sizeof(int));
	printf("Enter elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&arrptr[i]);
	p = Smallest(arrptr, n);
	printf("Smallest: %d",*p);
	free(arrptr);
	return 0;
}